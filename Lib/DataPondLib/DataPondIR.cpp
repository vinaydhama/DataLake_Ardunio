/*
  DataPondLib.cpp - Library for flashing DataPondLib code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DataPondLib.h"
#include <IRremote.hpp>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else  //ESP32
#include <WiFi.h>
#endif



DataPondLib::DataPondLib(int pin)
{
  _pin = pin;
}

void DataPondLib::begin()
{
  pinMode(_pin, OUTPUT);
}

void DataPondLib::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void DataPondLib::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

// DataPondLib2::DataPondLib2(int pin)
// {
//   _pin = pin;
// }

DataPondIR::DataPondIR(int IRSendPin, int IRReceivePin)
{
  _IRSendPin = IRSendPin;
  _IRReceivePin = IRReceivePin;
}
void DataPondIR::DataPondIRBeginSending()
{
  IrSender.begin(_IRSendPin);
}

void DataPondIR::DataPondIRBeginReceiving()
{
  IrReceiver.begin(_IRReceivePin, DISABLE_LED_FEEDBACK);
}
void DataPondIR::DataPondIRsendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats)
{
  uint_fast8_t dataPondIR_FrequencyKHz;
  uint16_t dataPondIR_HeaderMarkMicros;
  uint16_t dataPondIR_HeaderSpaceMicros;
  uint16_t dataPondIR_OneMarkMicros;
  uint16_t dataPondIR_OneSpaceMicros;
  uint16_t dataPondIR_ZeroMarkMicros;
  uint16_t dataPondIR_ZeroSpaceMicros;
  // uint32_t dataPondIR_Data;
  IRRawDataType dataPondIR_Data;
  uint_fast8_t dataPondIR_NumberOfBits;
  uint8_t dataPondIR_Flags;
  uint16_t dataPondIR_RepeatPeriodMillis;
  int_fast8_t dataPondIR_NumberOfRepeats;
  // void SendsendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats)
  // {

  // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, true, 2, 4);

  //   aFrequencyKHz = ConverStringTouint_fast8_t(sFrequencyKHz);
  //   aHeaderMarkMicros = ConverStringTouint16_t(sHeaderMarkMicros);
  //   aHeaderSpaceMicros = ConverStringTouint16_t(sHeaderSpaceMicros);
  //   aOneMarkMicros = ConverStringTouint16_t(sOneMarkMicros);
  //   aOneSpaceMicros = ConverStringTouint16_t(sOneSpaceMicros);
  //   aZeroMarkMicros = ConverStringTouint16_t(sZeroMarkMicros);
  //   aZeroSpaceMicros = ConverStringTouint16_t(sZeroSpaceMicros);
  // aData = ConverStringTouint16_t(sData);

  // //sData
  //   aNumberOfBits = ConverStringTouint16_t(sNumberOfBits);
  //   aRepeatPeriodMillis = ConverStringTouint16_t(sRepeatPeriodMillis);
  //   aNumberOfRepeats = ConverStringTouint16_t(sNumberOfRepeats);

  if (sFrequencyKHz != "" && sHeaderMarkMicros != "" && sHeaderSpaceMicros != "" && sOneMarkMicros != "" && sOneSpaceMicros != "" && sZeroMarkMicros != "" && sZeroSpaceMicros != "" && sData != "" && sNumberOfBits != "" && sFlags != "" && sRepeatPeriodMillis != "" && sNumberOfRepeats)
  {

    // IrSender.start();
    dataPondIR_FrequencyKHz = sFrequencyKHz.toInt();
    dataPondIR_HeaderMarkMicros = sHeaderMarkMicros.toInt();
    dataPondIR_HeaderSpaceMicros = sHeaderSpaceMicros.toInt();
    dataPondIR_OneMarkMicros = sOneMarkMicros.toInt();
    dataPondIR_OneSpaceMicros = sOneSpaceMicros.toInt();
    dataPondIR_ZeroMarkMicros = sZeroMarkMicros.toInt();
    dataPondIR_ZeroSpaceMicros = sZeroSpaceMicros.toInt();
    dataPondIR_Data = sData.toInt();
    // sData
    dataPondIR_NumberOfBits = sNumberOfBits.toInt();
    dataPondIR_RepeatPeriodMillis = sRepeatPeriodMillis.toInt();
    dataPondIR_NumberOfRepeats = sNumberOfRepeats.toInt();

    Serial.println(dataPondIR_FrequencyKHz);
    Serial.println(dataPondIR_HeaderMarkMicros);
    Serial.println(dataPondIR_HeaderSpaceMicros);
    Serial.println(dataPondIR_OneMarkMicros);
    Serial.println(dataPondIR_OneSpaceMicros);
    Serial.println(dataPondIR_ZeroMarkMicros);
    Serial.println(dataPondIR_ZeroSpaceMicros);
    Serial.println(dataPondIR_Data);
    Serial.println(dataPondIR_NumberOfBits);
    Serial.println(dataPondIR_Flags);
    Serial.println(dataPondIR_RepeatPeriodMillis);
    Serial.println(dataPondIR_NumberOfRepeats);
    IrSender.sendPulseDistanceWidth(dataPondIR_FrequencyKHz, dataPondIR_HeaderMarkMicros, dataPondIR_HeaderSpaceMicros,
                                    dataPondIR_OneMarkMicros, dataPondIR_OneSpaceMicros, dataPondIR_ZeroMarkMicros, dataPondIR_ZeroSpaceMicros,
                                    dataPondIR_Data, dataPondIR_NumberOfBits, true, dataPondIR_RepeatPeriodMillis, dataPondIR_NumberOfRepeats);
    // IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, aData, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
  }
  else
  {
    Serial.print("Command Send Failed");
  }
  // IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, 0x2D, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
  // }
}

void DataPondIR::DataPondIRReceive()
{
  IrReceiver.start();
  bool ContinueListining = true;
  int i = 0;
  while (ContinueListining)
  {
    if (IrReceiver.decode())
    {
      IrReceiver.printIRSendUsage(&Serial);
      DistanceWidthTimingInfoStruct aDistanceWidthTimingInfo;
      aDistanceWidthTimingInfo = IrReceiver.decodedIRData.DistanceWidthTimingInfo; // copy content here
      sFrmReceiver_HeaderMarkMicros = String(aDistanceWidthTimingInfo.HeaderMarkMicros);
      sFrmReceiver_HeaderSpaceMicros = String(aDistanceWidthTimingInfo.HeaderSpaceMicros);
      sFrmReceiver_OneMarkMicros = String(aDistanceWidthTimingInfo.OneMarkMicros);
      sFrmReceiver_OneSpaceMicros = String(aDistanceWidthTimingInfo.OneSpaceMicros);
      sFrmReceiver_ZeroMarkMicros = String(aDistanceWidthTimingInfo.ZeroMarkMicros);
      sFrmReceiver_ZeroSpaceMicros = String(aDistanceWidthTimingInfo.ZeroSpaceMicros);
      sFrmReceiver_FrequencyKHz = "38";
      sFrmReceiver_Data = String(IrReceiver.decodedIRData.decodedRawDataArray[0]);

      sFrmReceiver_NumberOfBits = String(IrReceiver.decodedIRData.numberOfBits);
      sFrmReceiver_RepeatPeriodMillis = "2";
      sFrmReceiver_NumberOfRepeats = "4";
      sFrmReceiver_Flags = "1";

      Serial.println(sFrmReceiver_FrequencyKHz);
      Serial.println(sFrmReceiver_HeaderMarkMicros);
      Serial.println(sFrmReceiver_HeaderSpaceMicros);
      Serial.println(sFrmReceiver_OneMarkMicros);
      Serial.println(sFrmReceiver_OneSpaceMicros);
      Serial.println(sFrmReceiver_ZeroMarkMicros);
      Serial.println(sFrmReceiver_ZeroSpaceMicros);
      Serial.println(sFrmReceiver_Data);
      Serial.println(sFrmReceiver_NumberOfBits);
      Serial.println(sFrmReceiver_Flags);
      Serial.println(sFrmReceiver_RepeatPeriodMillis);
      Serial.println(sFrmReceiver_NumberOfRepeats);
      ContinueListining = false;
    }
    else
    {
      Serial.println("Receive Not Complete");
    }

    delay(100);
        i++;
        
    if (i > 2)
    {
      ContinueListining = false;
    }
    else
    {
      Serial.println("Retry Failed");
    }
  }
}

// DataPondWifi::DataPondWifi(/* args */)
// {
// }

// DataPondWifi::~DataPondWifi()
// {

// }

// void  DataPondWifi:: beginWiFiConnection(String SSID,String password)
// {
// WiFi.begin(SSID.c_str(), password.c_str());
// }
// boolean DataPondWifi:: isWifiConnected() {
//   int c = 0;
//   Serial.println("Waiting for Wifi to connect");
//   while (c < 30) {
//     if (WiFi.status() == WL_CONNECTED) {
//       return true;
//     }
//     delay(500);
//     Serial.print("*");
//     c++;
//   }
//   Serial.println("");
//   Serial.println("Connect timed out, opening AP");
//   return false;
// }

// void DataPondWifi:: setupWifiAccessPoint(String accessPointName,String password) {
// String st;

//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect();
//   delay(100);
//   int n = WiFi.scanNetworks();
//   Serial.println("scan done");
//   if (n == 0)
//     Serial.println("no networks found");
//   else {
//     Serial.print(n);
//     Serial.println(" networks found");
//     for (int i = 0; i < n; ++i) {
//       // Print SSID and RSSI for each network found
//       Serial.print(i + 1);
//       Serial.print(": ");
//       Serial.print(WiFi.SSID(i));
//       Serial.print(" (");
//       Serial.print(WiFi.RSSI(i));
//       Serial.print(")");
//       Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
//       delay(10);
//     }
//   }
//   Serial.println("");
//   st = "<ol>";
//   for (int i = 0; i < n; ++i) {
//     // Print SSID and RSSI for each network found
//     st += "<li>";
//     st += WiFi.SSID(i);
//     st += " (";
//     st += WiFi.RSSI(i);
//     st += ")";
//     st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
//     st += "</li>";
//   }
//   st += "</ol>";
//   delay(100);
//   WiFi.softAP(accessPointName, password);
//   Serial.println("Initializing_softap_for_wifi credentials_modification");
//   //launchWeb();
//   Serial.println("over");
// }