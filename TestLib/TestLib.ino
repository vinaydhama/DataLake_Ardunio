#include <TestMore.h>

const int IRSend_PIN = 3;
const int IRReceive_PIN = 2;
// TestMore TMorse(1);
// TestMore2 TestMore2 (10);
DataPondIR dataPondIR(IRSend_PIN,IRReceive_PIN);
DataPondWifi dataPondWifi ;
DataPondEEPROM dataPondEEPROM;
DataPondRESTAPI dataPondRESTAPI;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
    dataPondIR.DataPondIRBeginSending();
 dataPondIR.DataPondIRBeginReceiving();

//dataPondIR.DataPondIRReceive();
  //TMorse.begin();
}

void loop() {

  String CommandtoWork = Serial.readString();

switch (CommandtoWork.toInt())
{
case 1:
  dataPondIR.DataPondIRsendPulseDistanceWidth("38", "1250", "1450", "1250", "450", "400", "1300", "000045", "11", "true", "2", "4");
  break;

case 2:
  if (dataPondWifi.isWifiConnected())
  {
    dataPondWifi.setupWifiAccessPoint("","");
    dataPondWifi.SetWifiHostName("");
  };
  break;

  case 3:
  dataPondIR.DataPondIRReceive();


case 4:

if (dataPondEEPROM.WriteDataToEEPROM (  0, "Hello"))
{
  String DataFromEEPROM = dataPondEEPROM.ReadDataFromEEPROM ( 0, 5);

}
if (dataPondEEPROM.ClearEEPROM ( 0, 5))
{
  String DataFromEEPROM = dataPondEEPROM.ReadDataFromEEPROM ( 0, 5);
}  
  break;



case 5:
dataPondRESTAPI.launchRestServer();
dataPondRESTAPI.getSendIRDataFromRESTAPI();
dataPondRESTAPI.getSetSystemParams();
dataPondRESTAPI.getSETWiFiParams();
dataPondRESTAPI.getGiveIntro();
dataPondRESTAPI.getOperateCooler();
break;
default:
//IrReceiver.start();

  break;
}

if (CommandtoWork == "1")
  {
    //IrReceiver.stop();


    // boolean bb=  dataLakeIRHelper.sendIRSendPulseDistanceWidth("38", "1350", "350", "1300", "400", "450", "1200", "45", "11", "1", "2", "4");
    // // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1250, 0x2D, 11, PROTOCOL_IS_LSB_FIRST, 2, 4);

    // // SendsendPulseDistanceWidth("38", "1250", "1450", "1250", "450", "400", "1300", "000045", "11", "true", "2", "4");
  }



  // put your main code here, to run repeatedly:

}
