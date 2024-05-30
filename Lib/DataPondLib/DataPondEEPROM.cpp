/*
  DataPondLib.cpp - Library for flashing DataPondLib code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DataPondLib.h"
#include <EEPROM.h>

// #include <IRremote.hpp>

// #ifdef ESP8266
// #include <ESP8266WiFi.h>
// #else  //ESP32
// #include <WiFi.h>
// #endif

DataPondEEPROM::DataPondEEPROM(/* args */)
{
}

String DataPondEEPROM::ReadDataFromEEPROM ( int readStartpoint, int readEndPoint)
{
  String returnReadvalue="";
  for (int i = readStartpoint; i < readEndPoint; ++i) {
    returnReadvalue += char(EEPROM.read(i));
  }
  Serial.println();
  Serial.print("Read Value: ");
  Serial.println(returnReadvalue);
  
return returnReadvalue;

  // for (int i = 32; i < 96; ++i) {
  //   epass += char(EEPROM.read(i));
  // }
  // Serial.print("PASS: ");
  // Serial.println(epass);
}

boolean DataPondEEPROM:: ClearEEPROM ( int clearStartpoint, int clearEndPoint)
{ 
 for (int i = clearStartpoint; i < clearEndPoint; ++i) {
      EEPROM.write(i, 0); 
    }
     ;  
  return true;
}
boolean DataPondEEPROM:: WriteDataToEEPROM ( int WriteStartpoint, String DatatoWrite)
{
  boolean returnReadvalue=false;

  int writeDataPointer=0; 
  if (DatatoWrite != "")
  {
 for (int i = WriteStartpoint; i < (WriteStartpoint + DatatoWrite.length()); ++i) {
      EEPROM.write(i, DatatoWrite[writeDataPointer]);
      ++writeDataPointer;
    }
    returnReadvalue = true;
  }
  return returnReadvalue;
}
DataPondEEPROM::~DataPondEEPROM()
{
}
