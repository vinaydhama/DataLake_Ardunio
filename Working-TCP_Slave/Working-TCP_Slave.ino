/*
  Modbus-Arduino Example - Test Holding Register (Modbus IP ESP8266)
  Configure Holding Register (offset 100) with initial value 0xABCD
  You can get or set this holding register
  Original library
  Copyright by André Sarmento Barbosa
  http://github.com/andresarmento/modbus-arduino

  Current version
  (c)2017 Alexander Emelianov (a.m.emelianov@gmail.com)
  https://github.com/emelianov/modbus-esp8266
*/


// GPIO0-Pin0 in code
// GPIO2-Pin2 in code


#ifdef ESP8266
#include <ESP8266WiFi.h>
#else  //ESP32
#include <WiFi.h>
#endif

#include "Arduino.h"
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include <IRremote.h>
#include <stdlib.h>



#include <ModbusIP_ESP8266.h>

// Modbus Registers Offsets
const int TEST_HREG = 1;

String ssid = "Vin-oppp2";
String password = "Vin1@f!1233";
String newHostname = "HomeAuto-RoomConroller1";


// Storage for the recorded code, pre-filled with NEC data
IRRawDataType sDecodedRawDataArray[RAW_DATA_ARRAY_SIZE] = { 0x7B34ED12 }; // address 0x12 command 0x34
DistanceWidthTimingInfoStruct sDistanceWidthTimingInfo = { 1250, 450, 1250, 450, 400, 1300}; // NEC timing

DistanceWidthTimingInfoStruct sDistanceWidthTimingInfoFromRest = { 1250, 450, 1250, 450, 400, 1300}; // NEC timing


uint_fast8_t aFrequencyKHz;
uint16_t aHeaderMarkMicros;
uint16_t aHeaderSpaceMicros;
uint16_t aOneMarkMicros;
uint16_t aOneSpaceMicros;
uint16_t aZeroMarkMicros;
uint16_t aZeroSpaceMicros;
IRRawDataType aData;
uint_fast8_t aNumberOfBits;
uint8_t aFlags;
uint16_t aRepeatPeriodMillis;
int_fast8_t aNumberOfRepeats;


const int IR_RECV_PIN = 0;
const int IRSend_PIN = 2;

int myInt;
String st;

ModbusIP modbusServer;


// Rest Server
ESP8266WebServer RestServer(80);

//IR Server
IRrecv IrReceive(IR_RECV_PIN);
int CommandToSend = 0;


// Functions
// IR Related

void send_ir_data() {
  //Serial.println(F("Sending IR Command:"));
  // Serial.print(sAddress, HEX);
  // Serial.print(sCommand, HEX);
  // Serial.println(sRepeats, HEX);
  Serial.flush();  // To avoid disturbing the software PWM generation by serial output interrupts
  // For Power
  if (CommandToSend == 49) {
    IrSender.sendPulseDistanceWidth(38, 1300, 400, 1250, 450, 400, 1250, 0x4D, 11, true, 2, 4);
  }
  // For FAN
  if (CommandToSend == 50) {
    IrSender.sendPulseDistanceWidth(38, 1250, 450, 1250, 450, 400, 1250, 0x10D, 11, true, 2, 4);
  }
  // For Swing
  if (CommandToSend == 51) {
    IrSender.sendPulseDistanceWidth(38, 1250, 450, 1250, 450, 400, 1300, 0x20D, 11, true, 2, 4);
  }
  // For Timer
  if (CommandToSend == 52) {
    Serial.print("Sending Timer");
//     IrSender.sendPulseDistanceWidthFromArray(38, &sDistanceWidthTimingInfo, &sDecodedRawDataArray[0], sNumberOfBits,
// #if defined(USE_MSB_DECODING_FOR_DISTANCE_DECODER)
//                                              PROTOCOL_IS_MSB_FIRST
// #else
//                                              PROTOCOL_IS_LSB_FIRST
// #endif
//                                              ,
//                                              100, 0);

    //IrSender.sendPulseDistanceWidth(38, 1250, 450, 1250, 450, 400, 1300, 0x2D, 11,true, 2, 4);
  }
  // For Cool
  if (CommandToSend == 53) {
    IrSender.sendPulseDistanceWidth(38, 1250, 400, 1250, 450, 400, 1300, 0x8D, 11, true, 2, 4);
  }

  CommandToSend = 0;
}


// Wifi Related
bool testWifi(void) {
  int c = 0;
  Serial.println("Waiting for Wifi to connect");
  while (c < 30) {
    if (WiFi.status() == WL_CONNECTED) {
      return true;
    }
    delay(500);
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Connect timed out, opening AP");
  return false;
}

void setupAP(void) {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");
  st = "<ol>";
  for (int i = 0; i < n; ++i) {
    // Print SSID and RSSI for each network found
    st += "<li>";
    st += WiFi.SSID(i);
    st += " (";
    st += WiFi.RSSI(i);
    st += ")";
    st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    st += "</li>";
  }
  st += "</ol>";
  delay(100);
  WiFi.softAP("HomeAutomationControl", "");
  Serial.println("Initializing_softap_for_wifi credentials_modification");
  //launchWeb();
  Serial.println("over");
}

void launchRestServer() {
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
    Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());

  // Set RestServer routing
  restServerRouting();
  // Set not found response
  RestServer.onNotFound(handleNotFound);
  // Start RestServer
  RestServer.begin();
  Serial.println("HTTP RestServer started");
  modbusServer.server(502);
  modbusServer.addHreg(TEST_HREG, 0, 4);
}
//ModbusIP Server
// Rest Functions
/// http://192.168.4.1/SETWiFiParams/home_timeline.json?ssid=dsd&pass=P222

uint16_t ConvertStringTouint16_t(String valueToConvert)
{
  uint16_t convertedValue=0;
Serial.print("valueToConvert" + valueToConvert);
convertedValue = valueToConvert.toInt();
Serial.print("convertedValue" + convertedValue);

  return convertedValue;

}

void getSendIRDataFromRESTAPI(){

//     IrSender.sendPulseDistanceWidthFromArray(38, &sDistanceWidthTimingInfo, &sDecodedRawDataArray[0], sNumberOfBits,
// #if defined(USE_MSB_DECODING_FOR_DISTANCE_DECODER)
//                                              PROTOCOL_IS_MSB_FIRST
// #else
//                                              PROTOCOL_IS_LSB_FIRST
// #endif
//                                              ,
//                                              100, 0);
String strFromRESTAPI="";
//uint_fast8_t aFrequencyKHz

strFromRESTAPI= RestServer.arg("aFrequencyKHz");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

aHeaderMarkMicros= ConvertStringTouint16_t (RestServer.arg("aHeaderMarkMicros"));

// uint16_t aHeaderMarkMicros
// strFromRESTAPI= RestServer.arg("aHeaderMarkMicros");

//   if (strFromRESTAPI!= "")
//   {
//     aHeaderMarkMicros = strFromRESTAPI.toInt();
//     strFromRESTAPI=0;
//   }

// uint16_t aHeaderSpaceMicros

strFromRESTAPI= RestServer.arg("aHeaderSpaceMicros");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// uint16_t aOneMarkMicros
strFromRESTAPI= RestServer.arg("aOneMarkMicros");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// uint16_t aOneSpaceMicros
strFromRESTAPI= RestServer.arg("aOneSpaceMicros");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// uint16_t aZeroMarkMicros
strFromRESTAPI= RestServer.arg("aZeroMarkMicros");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// uint16_t aZeroSpaceMicros
strFromRESTAPI= RestServer.arg("aZeroSpaceMicros");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// IRRawDataType aData
// uint_fast8_t aNumberOfBits
strFromRESTAPI= RestServer.arg("aNumberOfBits");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

// uint8_t aFlags
// uint16_t aRepeatPeriodMillis
strFromRESTAPI= RestServer.arg("aRepeatPeriodMillis");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }
// int_fast8_t aNumberOfRepeats
strFromRESTAPI= RestServer.arg("aNumberOfRepeats");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

//uint_fast8_t aFrequencyKHz

strFromRESTAPI= RestServer.arg("aFrequencyKHz");

  if (strFromRESTAPI!= "")
  {
    aFrequencyKHz = strFromRESTAPI.toInt();
    strFromRESTAPI=0;
  }

//   char buf[30];
  
//    FrequencyKHz.toCharArray(buf,FrequencyKHz.length());
//    Serial.println(buf);
//    aFrequencyKHz =  strtol(buf, NULL, 16);  
//   }


// Serial.print("Freq:");
// Serial.print(aFrequencyKHz,HEX);
// String s1= "Freq Received " + aFrequencyKHz;
// RestServer.send(200, "text/json", s1);

// sDistanceWidthTimingInfoFromRest = RestServer.arg("DistanceWidthTimingInfo");
// aHeaderSpaceMicros = strtol(RestServer.arg("HeaderSpaceMicros"), NULL, 16);
// aNumberOfBits = strtol(RestServer.arg("NumberOfBits"), NULL, 16);
// aRepeatPeriodMillis = strtol(RestServer.arg("RepeatPeriodMillis"), NULL, 16);
// aNumberOfRepeats = strtol(RestServer.arg("NumberOfRepeats"), NULL, 16);

// IrSender.sendPulseDistanceWidthFromArray(aFrequencyKHz, &sDistanceWidthTimingInfoFromRest, aHeaderSpaceMicros, aNumberOfBits,
// #if defined(USE_MSB_DECODING_FOR_DISTANCE_DECODER)
//                                              PROTOCOL_IS_MSB_FIRST
// #else
//                                              PROTOCOL_IS_LSB_FIRST
// #endif
//                                              ,
//                                              aRepeatPeriodMillis, aNumberOfRepeats);
}

void getSETWiFiParams() {
  String qsid = RestServer.arg("ssid");
  String qpass = RestServer.arg("pass");
  String s1 = "";
  if (qsid.length() > 0 && qpass.length() > 0) {
    ssid = qsid;
    password = qpass;
    Serial.println("clearing eeprom");
    for (int i = 0; i < 96; ++i) {
      EEPROM.write(i, 0);
    }
    s1 += "{\"name\": \"Setting WiFi Parameters ";
    s1 += "SSID" + qsid + "Password" + qpass;

    Serial.println("writing eeprom ssid:");
    for (int i = 0; i < qsid.length(); ++i) {
      EEPROM.write(i, qsid[i]);
      Serial.print("Wrote: ");
      Serial.println(qsid[i]);
    }
    Serial.println("writing eeprom pass:");
    for (int i = 0; i < qpass.length(); ++i) {
      EEPROM.write(32 + i, qpass[i]);
      Serial.print("Wrote: ");
      Serial.println(qpass[i]);
    }
    EEPROM.commit();
    s1 += "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
    ESP.reset();
  } else {
    s1 += "{\"Error\":\"404 not found\"}";
    Serial.println("Sending 404");
  }
  s1 += "\"}";
  RestServer.send(200, "text/json", s1);
  //modbusServer.Hreg(TEST_HREG)= myInt;
  //mb.addHreg(TEST_HREG, myInt);
}

void getGiveIntro() {
  String cmdValue = RestServer.arg(1);
  //myInt= 2;

  String s1 = "\"DeviceInfo\":		{";
  s1 += "\"Name\":\"Name1\",";
  s1 += "\"ID\":\"ID1\",";
  s1 += "\"Type\":\"ID1\",";
  s1 += "\"DisplayName\": \"DisplayName1\",";
  s1 += "\"IP\":\"IP1\",";
  s1 += "\"Port\":\"Port1\",";
  s1 += "\"Location\":\"Loc1\",";
  s1 += "\"SSID\":\"\",";
  s1 += "\"Password\":\"\"";
  s1 += "},";

  RestServer.send(200, "text/json", s1);
  Serial.println(s1);
}


void getOperateCooler() {
  String cmdValue = RestServer.arg(1);
  //myInt= 2;
  String s1 = "{\"name\": \"OperateCooler ";
  s1 += cmdValue;
  s1 += "\"}";
  RestServer.send(200, "text/json", s1);
  Serial.println(cmdValue);
}


// Define routing
void restServerRouting() {
  RestServer.on("/", HTTP_GET, []() {
    RestServer.send(200, F("text/html"),
                    F("Welcome to the REST Web Server"));
  });
  RestServer.on(F("/GiveIntro/home_timeline.json"), HTTP_GET, getGiveIntro);
  RestServer.on(F("/SETWiFiParams/home_timeline.json"), HTTP_GET, getSETWiFiParams);
  RestServer.on(F("/OperateCooler/home_timeline.json"), HTTP_GET, getOperateCooler);
  RestServer.on(F("/SendIRDataFromRESTAPI/home_timeline.json"), HTTP_GET, getSendIRDataFromRESTAPI);
  //RestServer.on(F("/ReceiveIRData/home_timeline.json"), HTTP_GET, getReceiveIRData);
}
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += RestServer.uri();
  message += "\nMethod: ";
  message += (RestServer.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += RestServer.args();
  message += "\n";
  for (uint8_t i = 0; i < RestServer.args(); i++) {
    message += " " + RestServer.argName(i) + ": " + RestServer.arg(i) + "\n";
  }
  RestServer.send(404, "text/plain", message);
}

void setup() {
  Serial.begin(9600);
  pinMode(IRSend_PIN, OUTPUT);
  IrSender.begin(IRSend_PIN);
  //WiFi.begin("Maraf!", "VINF!123456");
  //WiFi.begin("Vin vivo", "VINF!123456");
  WiFi.disconnect();
  EEPROM.begin(512);  //Initialasing EEPROM
                      //---------------------------------------- Read eeprom for ssid and pass
  Serial.println("Reading EEPROM ssid");
  String esid;
  for (int i = 0; i < 32; ++i) {
    esid += char(EEPROM.read(i));
  }
  Serial.println();
  Serial.print("SSID: ");
  Serial.println(esid);
  Serial.println("Reading EEPROM pass");
  String epass = "";
  for (int i = 32; i < 96; ++i) {
    epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass);


  WiFi.begin(esid.c_str(), epass.c_str());

  Serial.printf("Default hostname: %s\n", WiFi.hostname().c_str());
  //Set new hostname
  WiFi.hostname(newHostname.c_str());

  Serial.printf("New hostname: %s\n", WiFi.hostname().c_str());

  if (testWifi()) {
    Serial.println("Succesfully Connected!!!");
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    launchRestServer();
  } else {
    Serial.println("Turning the HotSpot On");
    setupAP();  // Setup HotSpot
    launchRestServer();
  }
}

void loop() {
  //Call once inside loop() - all magic here
  modbusServer.task();
  myInt = modbusServer.Hreg(TEST_HREG);

  uint8_t myBytes[2] = { highByte(myInt), lowByte(myInt) };
  //  shiftOut(dataPin, clockPin, LSBFIRST, myBytes[0]);


  CommandToSend= Serial.read();
   


 //readDataFromESPSerialAndPrint();
if (CommandToSend== 49 || CommandToSend== 50|| CommandToSend== 51 || CommandToSend== 52 || CommandToSend== 53|| CommandToSend== 54)
{
   Serial.println(CommandToSend);
  send_ir_data();

}

  RestServer.handleClient();
  delay(100);
}
