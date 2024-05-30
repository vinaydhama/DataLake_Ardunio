/*
  DataPondLib.h - Library for flashing DataPondLib code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef DataPondLib_h
#define DataPondLib_h

#include "Arduino.h"
#include <ESP8266WebServer.h>
extern ESP8266WebServer RestServer;

// #include <IRremote.hpp>

class DataPondLib
{
public:
  DataPondLib(int pin);
  void begin();
  void dot();
  void dash();

private:
  int _pin;
};

class DataPondLib2
{
public:
  DataPondLib2(int pin);

private:
  int _pin;
};

class DataPondIR
{
private:
  int _IRSendPin;
  int _IRReceivePin;

public:
  String sFrmReceiver_FrequencyKHz;
  String sFrmReceiver_HeaderMarkMicros;
  String sFrmReceiver_HeaderSpaceMicros;
  String sFrmReceiver_OneMarkMicros;
  String sFrmReceiver_OneSpaceMicros;
  String sFrmReceiver_ZeroMarkMicros;
  String sFrmReceiver_ZeroSpaceMicros;
  String sFrmReceiver_Data;
  String sFrmReceiver_NumberOfBits;
  String sFrmReceiver_Flags;
  String sFrmReceiver_RepeatPeriodMillis;
  String sFrmReceiver_NumberOfRepeats;

  DataPondIR(int IRSendPin, int IRReceivePin);
  void DataPondIRBeginSending();
  void DataPondIRBeginReceiving();

  void DataPondIRsendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros,
                                        String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData,
                                        String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats);
  void DataPondIRReceive();

  // ~DataPondIR();
};

class DataPondWifi
{
private:
  /* data */
public:
  boolean isWifiConnected();
  void setupWifiAccessPoint(String accessPointName, String password);
  void beginWiFiConnection(String SSID, String password);
  void SetWifiHostName(String hostNameToSet);
  DataPondWifi(/* args */);
  ~DataPondWifi();
};

class DataPondEEPROM
{
private:
  /* data */
public:
  String ReadDataFromEEPROM(int readStartpoint, int readEndPoint);
  boolean WriteDataToEEPROM(int WriteStartpoint, String DatatoWrite);
  boolean ClearEEPROM(int clearStartpoint, int clearEndPoint);

  DataPondEEPROM(/* args */);
  ~DataPondEEPROM();
};

class DataPondRESTAPI
{
private:
  /* data */
public:
  static String sSIDFromREST;
  static String passowrdFromREST;
  void initializeRESTServer(int PortNumber);
  void launchRestServer();
  static void getSendIRDataFromRESTAPI();
  static void getSETWiFiParams();
  static void getSetSystemParams();
  static void getGiveIntro();
  static void getOperateCooler();
  static void getReceiveIRData ();
  static void restServerRouting();
  static void handleNotFound();

  DataPondRESTAPI(/* args */);
  ~DataPondRESTAPI();
};

// class DataPondRestAPI
// {
// private:
//   /* data */
// public:
//   DataPondRestAPI(/* args */);
//   ~DataPondRestAPI();
// };

// DataPondRestAPI::DataPondRestAPI(/* args */)
// {
// }

// DataPondRestAPI::~DataPondRestAPI()
// {
// }

// class DataPondModBus
// {
// private:
//   /* data */
// public:
//   DataPondModBus(/* args */);
//   ~DataPondModBus();
// };

// DataPondModBus::DataPondModBus(/* args */)
// {
// }

// DataPondModBus::~DataPondModBus()
// {
// }

// DataPondIR::DataPondIR(int IRSendPin,int IRReceivePin)
// {

// }

// DataPondIR::~DataPondIR()
// {
// }

#endif