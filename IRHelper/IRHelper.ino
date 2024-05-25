
#include <IRremote.h>
#include <stdlib.h>
#include <IRremote.hpp>
const int IRSend_PIN = 3;

uint_fast8_t aFrequencyKHz;
uint16_t aHeaderMarkMicros;
uint16_t aHeaderSpaceMicros;
uint16_t aOneMarkMicros;
uint16_t aOneSpaceMicros;
uint16_t aZeroMarkMicros;
uint16_t aZeroSpaceMicros;
// uint32_t aData;
IRRawDataType aData;
uint_fast8_t aNumberOfBits;
uint8_t aFlags;
uint16_t aRepeatPeriodMillis;
int_fast8_t aNumberOfRepeats;

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
// char buf[6] = {};
// char Secondhalf[2] = {};
// char Thirddhalf[2] = {};

// IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);

// uint16_t ConverStringTouint16_t(String StringToConvert)
// {
//   uint16_t ConvertrdValueHolder = 0;

//   Serial.println(StringToConvert);
//   StringToConvert.toCharArray(buf, StringToConvert.length());
//   Secondhalf[0] = buf[2];
//   Secondhalf[1] = buf[3];
//   Secondhalf[2] = '\0';

//   Serial.print("Secondhalf ");
//   Serial.println(Secondhalf);

//   Thirddhalf[0] = buf[4];
//   Thirddhalf[1] = buf[5];
//   Thirddhalf[2] = '\0';

//   Serial.print("Thirddhalf ");
//   Serial.println(Thirddhalf);

//   buf[2] = '\0';
//   Serial.print("buf");
//   // + atoi(Thirddhalf)
//   Serial.print(buf);
//   uint16_t aa = (atoi(buf) * 1000) + (atoi(Secondhalf) * 100);
//   // Serial.print("int ");
//   // Serial.println(aa);
//   ConvertrdValueHolder = (uint16_t)aa;
//   Serial.println("Value Converted is ");
//   Serial.println(ConvertrdValueHolder);
//   return ConvertrdValueHolder;
// }

// uint32_t ConverStringTouint32_t(String StringToConvert)
// {
//   uint32_t ConvertrdValueHolder = 0;
//   uint_fast8_t Conv1 = 0;
//   uint_fast8_t Conv2 = 0;
//   uint_fast8_t Conv3 = 0;
//   uint_fast8_t Conv4 = 0;
//   uint_fast8_t Conv5 = 0;

//   char bufint[] = {};
//   Serial.println(StringToConvert);
//   // ConverStringTouint32_t
//   StringToConvert.toCharArray(bufint, StringToConvert.length());

//   // ConvertrdValueHolder = Conv1 *100000000 +Conv2 *10000000 +Conv3 *1000000 + Conv4 *10000 + Conv5 *100000   ;
//   //  Secondhalf[0] = buf[2];
//   //  Secondhalf[1] = buf[3];
//   //  Secondhalf[2] = '\0';

//   // // Serial.print("Secondhalf ");
//   // // Serial.println(Secondhalf);
//   // buf[2] = '\0';
//   // int aa = atoi(buf) * 100 + atoi(Secondhalf);
//   // // Serial.print("int ");
//   // // Serial.println(aa);
//   // ConvertrdValueHolder = (uint32_t)aa;
//   // Serial.println("Value Converted is ");
//   // Serial.println(ConvertrdValueHolder);
//   // return ConvertrdValueHolder;
// }

// uint_fast8_t ConverStringTouint_fast8_t(String StringToConvert)
// {
//   uint_fast8_t ConvertrdValueHolder = 0;
//   Serial.print(StringToConvert);
//   StringToConvert.toCharArray(buf, StringToConvert.length());
//   int aa = StringToConvert.toInt();
//   Serial.print("int ");
//   Serial.println(aa);
//   ConvertrdValueHolder = (uint8_t)aa;
//   Serial.print("Value Converted is ");
//   Serial.println(ConvertrdValueHolder);
//   return ConvertrdValueHolder;
// }

void setup()
{
  Serial.begin(115200);
  pinMode(IRSend_PIN, OUTPUT);
  IrSender.begin(IRSend_PIN);
  IrReceiver.begin(2, DISABLE_LED_FEEDBACK);

  // put your setup code here, to run once:
}
// enum TypetoConvert {

// }

void SendsendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats)
{

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
    aFrequencyKHz = sFrequencyKHz.toInt();
    aHeaderMarkMicros = sHeaderMarkMicros.toInt();
    aHeaderSpaceMicros = sHeaderSpaceMicros.toInt();
    aOneMarkMicros = sOneMarkMicros.toInt();
    aOneSpaceMicros = sOneSpaceMicros.toInt();
    aZeroMarkMicros = sZeroMarkMicros.toInt();
    aZeroSpaceMicros = sZeroSpaceMicros.toInt();
    aData = sData.toInt();

    // sData
    aNumberOfBits = sNumberOfBits.toInt();
    aRepeatPeriodMillis = sRepeatPeriodMillis.toInt();
    aNumberOfRepeats = sNumberOfRepeats.toInt();

    Serial.println(aFrequencyKHz);
    Serial.println(aHeaderMarkMicros);
    Serial.println(aHeaderSpaceMicros);
    Serial.println(aOneMarkMicros);
    Serial.println(aOneSpaceMicros);
    Serial.println(aZeroMarkMicros);
    Serial.println(aZeroSpaceMicros);
    Serial.println(aData);
    Serial.println(aNumberOfBits);
    Serial.println(aFlags);
    Serial.println(aRepeatPeriodMillis);
    Serial.println(aNumberOfRepeats);

    IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, aData, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
  }
  else{
    Serial.print("Command Send Failed");
  }
  // IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, 0x2D, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
}

void loop()
{
  // Serial.print("hi");
  String DataToCovert = Serial.readString();
  // char[]  DataToCovertARRAY[];
  //  DataToCovert.toCharArray(DataToCovertARRAY,StringToConvert.length());
  //  DataToCovertARRAY= strtok (DataToCovertARRAY,",");
  if (DataToCovert == "1")
  {
    IrReceiver.stop();

    // String aa = "00000045";
    // uint32_t xx = aa.toInt();
    // Serial.print(xx);

    // ConverStringTouint16_t(DataToCovert);
    //  IrSender.begin(IRSend_PIN);
    // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, true, 2, 4);
    // SendsendPulseDistanceWidth("255" ,"001234","0350","1300","0400","0450","1200","00000045","11","1","2","4");
    // Serial.print(DataToCovert);

    SendsendPulseDistanceWidth("38", "1350", "350", "1300", "400", "450", "1200", "45", "11", "1", "2", "4");
    //IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1250, 0x2D, 11, PROTOCOL_IS_LSB_FIRST, 2, 4);

    // SendsendPulseDistanceWidth("38", "1250", "1450", "1250", "450", "400", "1300", "000045", "11", "true", "2", "4");
  }

  if (DataToCovert == "2")
  {
    Serial.print("Waiting for Decode");
    if (IrReceiver.decode())
    {
      IrReceiver.printIRSendUsage(&Serial);
      DistanceWidthTimingInfoStruct sDistanceWidthTimingInfo;
      sDistanceWidthTimingInfo = IrReceiver.decodedIRData.DistanceWidthTimingInfo; // copy content here
      sFrmReceiver_HeaderMarkMicros = String(sDistanceWidthTimingInfo.HeaderMarkMicros);
      sFrmReceiver_HeaderSpaceMicros = String(sDistanceWidthTimingInfo.HeaderSpaceMicros);
      sFrmReceiver_OneMarkMicros = String(sDistanceWidthTimingInfo.OneMarkMicros);
      sFrmReceiver_OneSpaceMicros = String(sDistanceWidthTimingInfo.OneSpaceMicros);
      sFrmReceiver_ZeroMarkMicros = String(sDistanceWidthTimingInfo.ZeroMarkMicros);
      sFrmReceiver_ZeroSpaceMicros = String(sDistanceWidthTimingInfo.ZeroSpaceMicros);
      sFrmReceiver_FrequencyKHz = "38";
      sFrmReceiver_Data = String(IrReceiver.decodedIRData.decodedRawDataArray[0]);

      sFrmReceiver_NumberOfBits = String(IrReceiver.decodedIRData.numberOfBits);
      sFrmReceiver_RepeatPeriodMillis = "2";
      sFrmReceiver_NumberOfRepeats = "4";
      sFrmReceiver_Flags= "1";

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
    }

    // Receive Data

    IrReceiver.start();
  }

  if (DataToCovert == "3")
  {
    Serial.print("Repeting Command");
    SendsendPulseDistanceWidth(sFrmReceiver_FrequencyKHz, sFrmReceiver_HeaderMarkMicros, sFrmReceiver_HeaderSpaceMicros, 
    sFrmReceiver_OneMarkMicros, sFrmReceiver_OneSpaceMicros, sFrmReceiver_ZeroMarkMicros, sFrmReceiver_ZeroSpaceMicros, 
    sFrmReceiver_Data, sFrmReceiver_NumberOfBits, sFrmReceiver_Flags, sFrmReceiver_RepeatPeriodMillis, sFrmReceiver_NumberOfRepeats);

  }

  // delay(1000);
  //  SendsendPulseDistanceWidth(DataToCovertARRAY[0],DataToCovertARRAY[1]);
}
// put your main code here, to run repeatedly:
