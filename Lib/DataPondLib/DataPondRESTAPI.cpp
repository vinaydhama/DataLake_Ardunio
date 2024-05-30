/*
  DataPondLib.cpp - Library for flashing DataPondLib code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DataPondLib.h"
// #include <EEPROM.h>

// #include <IRremote.hpp>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else  //ESP32
#include <WiFi.h>
#endif
#include <ESP8266WebServer.h>

ESP8266WebServer RestServer (80);
String  DataPondRESTAPI:: sSIDFromREST;
String DataPondRESTAPI:: passowrdFromREST;


void DataPondRESTAPI::initializeRESTServer(int PortNumber)
{
   //RestServer(PortNumber); //=  ESP8266WebServer (PortNumber);
}
void DataPondRESTAPI:: restServerRouting() {
  RestServer.on("/", HTTP_GET, []() {
    RestServer.send(200, F("text/html"),
                    F("Welcome to the REST Web Server"));
  });
  RestServer.on(F("/GiveIntro/home_timeline.json"), HTTP_GET, getGiveIntro);
  RestServer.on(F("/SETWiFiParams/home_timeline.json"), HTTP_GET, getSETWiFiParams);
  RestServer.on(F("/OperateCooler/home_timeline.json"), HTTP_GET, getOperateCooler);
  RestServer.on(F("/SendIRDataFromRESTAPI/home_timeline.json"), HTTP_GET, getSendIRDataFromRESTAPI);
  RestServer.on(F("/ReceiveIRData/home_timeline.json"), HTTP_GET, getReceiveIRData);
  RestServer.on(F("/SetSystemParams/home_timeline.json"), HTTP_GET, getSetSystemParams);

}
void DataPondRESTAPI:: handleNotFound() {
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

void DataPondRESTAPI:: launchRestServer() {
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
  // modbusServer.server(502);
  // modbusServer.addHreg(TEST_HREG, 0, 4);
}

void DataPondRESTAPI:: getSendIRDataFromRESTAPI(){
}

void DataPondRESTAPI:: getSetSystemParams(){
}

void DataPondRESTAPI::getSETWiFiParams() {
  sSIDFromREST = RestServer.arg("ssid");
  passowrdFromREST = RestServer.arg("pass");
  //String s1 = "";
  // if (qsid.length() > 0 && qpass.length() > 0) {
  //   //ssid = qsid;
  //   //password = qpass;
  //   Serial.println("clearing eeprom");
  //   for (int i = 0; i < 96; ++i) {
  //     EEPROM.write(i, 0);
  //   }
  //   s1 += "{\"name\": \"Setting WiFi Parameters ";
  //   s1 += "SSID" + qsid + "Password" + qpass;

  //   Serial.println("writing eeprom ssid:");
  //   for (int i = 0; i < qsid.length(); ++i) {
  //     EEPROM.write(i, qsid[i]);
  //     Serial.print("Wrote: ");
  //     Serial.println(qsid[i]);
  //   }
  //   Serial.println("writing eeprom pass:");
  //   for (int i = 0; i < qpass.length(); ++i) {
  //     EEPROM.write(32 + i, qpass[i]);
  //     Serial.print("Wrote: ");
  //     Serial.println(qpass[i]);
  //   }
  //   EEPROM.commit();
  //   s1 += "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
  //   ESP.reset();
  // } else {
  //   s1 += "{\"Error\":\"404 not found\"}";
  //   Serial.println("Sending 404");
  // }
  // s1 += "\"}";
  // RestServer.send(200, "text/json", s1);
  //modbusServer.Hreg(TEST_HREG)= myInt;
  //mb.addHreg(TEST_HREG, myInt);
}

void DataPondRESTAPI::getGiveIntro() {
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


void DataPondRESTAPI:: getOperateCooler() {
  String cmdValue = RestServer.arg(1);
  //myInt= 2;
  String s1 = "{\"name\": \"OperateCooler ";
  s1 += cmdValue;
  s1 += "\"}";
  RestServer.send(200, "text/json", s1);
  Serial.println(cmdValue);
}
void DataPondRESTAPI:: getReceiveIRData(){

}

// // Define routing
// void DataPondRESTAPI:: restServerRouting() {
//   RestServer.on("/", HTTP_GET, []() {
//     RestServer.send(200, F("text/html"),
//                     F("Welcome to the REST Web Server"));
//   });
//   RestServer.on(F("/GiveIntro/home_timeline.json"), HTTP_GET, getGiveIntro);
//   RestServer.on(F("/SETWiFiParams/home_timeline.json"), HTTP_GET, getSETWiFiParams);
//   RestServer.on(F("/OperateCooler/home_timeline.json"), HTTP_GET, getOperateCooler);
//   RestServer.on(F("/SendIRDataFromRESTAPI/home_timeline.json"), HTTP_GET, getSendIRDataFromRESTAPI);
//   RestServer.on(F("/ReceiveIRData/home_timeline.json"), HTTP_GET, getReceiveIRData);
//   RestServer.on(F("/SetSystemParams/home_timeline.json"), HTTP_GET, getSetSystemParams);

// }
// void DataPondRESTAPI::handleNotFound() {
//   String message = "File Not Found\n\n";
//   message += "URI: ";
//   message += RestServer.uri();
//   message += "\nMethod: ";
//   message += (RestServer.method() == HTTP_GET) ? "GET" : "POST";
//   message += "\nArguments: ";
//   message += RestServer.args();
//   message += "\n";
//   for (uint8_t i = 0; i < RestServer.args(); i++) {
//     message += " " + RestServer.argName(i) + ": " + RestServer.arg(i) + "\n";
//   }
//   RestServer.send(404, "text/plain", message);
// }



DataPondRESTAPI::DataPondRESTAPI(/* args */)
{
}

DataPondRESTAPI::~DataPondRESTAPI()
{
}

