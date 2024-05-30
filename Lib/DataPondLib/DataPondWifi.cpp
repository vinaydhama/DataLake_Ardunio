#include "Arduino.h"
#include "DataPondLib.h"
// #include <IRremote.hpp>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else  //ESP32
#include <WiFi.h>
#endif

DataPondWifi::DataPondWifi(/* args */)
{
}

DataPondWifi::~DataPondWifi()
{

}

void  DataPondWifi:: beginWiFiConnection(String SSID,String password)
{
WiFi.begin(SSID.c_str(), password.c_str());
}
boolean DataPondWifi:: isWifiConnected() {
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

void DataPondWifi:: SetWifiHostName(String hostNameToSet)
{
 WiFi.hostname(hostNameToSet.c_str());

}
void DataPondWifi:: setupWifiAccessPoint(String accessPointName,String password) {
String st;

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
  WiFi.softAP(accessPointName, password);
  Serial.println("Initializing_softap_for_wifi credentials_modification");
  //launchWeb();
  Serial.println("over");
}