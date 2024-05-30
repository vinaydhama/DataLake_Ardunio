#include "DataLakeIRHelper.H"
#include <IRremote.h>
#include <stdlib.h>
#include "Arduino.h"


// uint_fast8_t aFrequencyKHz;
// uint16_t aHeaderMarkMicros;
// uint16_t aHeaderSpaceMicros;
// uint16_t aOneMarkMicros;
// uint16_t aOneSpaceMicros;
// uint16_t aZeroMarkMicros;
// uint16_t aZeroSpaceMicros;
// // uint32_t aData;
// IRRawDataType aData;
// uint_fast8_t aNumberOfBits;
// uint8_t aFlags;
// uint16_t aRepeatPeriodMillis;
// int_fast8_t aNumberOfRepeats;

// String sFrmReceiver_FrequencyKHz;
// String sFrmReceiver_HeaderMarkMicros;
// String sFrmReceiver_HeaderSpaceMicros;
// String sFrmReceiver_OneMarkMicros;
// String sFrmReceiver_OneSpaceMicros;
// String sFrmReceiver_ZeroMarkMicros;
// String sFrmReceiver_ZeroSpaceMicros;
// String sFrmReceiver_Data;
// String sFrmReceiver_NumberOfBits;
// String sFrmReceiver_Flags;
// String sFrmReceiver_RepeatPeriodMillis;
// String sFrmReceiver_NumberOfRepeats;


// DataLakeIRHelper:: DataLakeIRHelper(int DataLakeIRSend_PIN,int DataLakeIRReceive_PIN)
// {
//   if (DataLakeIRSend_PIN!=0 && DataLakeIRReceive_PIN!= 0 )
//   {

//   // pinMode(IRSend_PIN, OUTPUT);
//   // IrSender.begin(IRSend_PIN);
//   // IrReceiver.begin(2, DISABLE_LED_FEEDBACK);


//   // = DataLakeIRSend_PIN;
//   // IRReceivePin = DataLakeIRReceive_PIN;
//   }
// }


// DataLakeIRHelper:: sendIRSendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats)
// {
//     boolean returnValue = false;

//   // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, true, 2, 4);

//   //   aFrequencyKHz = ConverStringTouint_fast8_t(sFrequencyKHz);
//   //   aHeaderMarkMicros = ConverStringTouint16_t(sHeaderMarkMicros);
//   //   aHeaderSpaceMicros = ConverStringTouint16_t(sHeaderSpaceMicros);
//   //   aOneMarkMicros = ConverStringTouint16_t(sOneMarkMicros);
//   //   aOneSpaceMicros = ConverStringTouint16_t(sOneSpaceMicros);
//   //   aZeroMarkMicros = ConverStringTouint16_t(sZeroMarkMicros);
//   //   aZeroSpaceMicros = ConverStringTouint16_t(sZeroSpaceMicros);
//   // aData = ConverStringTouint16_t(sData);

//   // //sData
//   //   aNumberOfBits = ConverStringTouint16_t(sNumberOfBits);
//   //   aRepeatPeriodMillis = ConverStringTouint16_t(sRepeatPeriodMillis);
//   //   aNumberOfRepeats = ConverStringTouint16_t(sNumberOfRepeats);

//   if (sFrequencyKHz != "" && sHeaderMarkMicros != "" && sHeaderSpaceMicros != "" && sOneMarkMicros != "" && sOneSpaceMicros != "" && sZeroMarkMicros != "" && sZeroSpaceMicros != "" && sData != "" && sNumberOfBits != "" && sFlags != "" && sRepeatPeriodMillis != "" && sNumberOfRepeats)
//   {
//     aFrequencyKHz = sFrequencyKHz.toInt();
//     aHeaderMarkMicros = sHeaderMarkMicros.toInt();
//     aHeaderSpaceMicros = sHeaderSpaceMicros.toInt();
//     aOneMarkMicros = sOneMarkMicros.toInt();
//     aOneSpaceMicros = sOneSpaceMicros.toInt();
//     aZeroMarkMicros = sZeroMarkMicros.toInt();
//     aZeroSpaceMicros = sZeroSpaceMicros.toInt();
//     aData = sData.toInt();

//     // sData
//     aNumberOfBits = sNumberOfBits.toInt();
//     aRepeatPeriodMillis = sRepeatPeriodMillis.toInt();
//     aNumberOfRepeats = sNumberOfRepeats.toInt();

//     Serial.println(aFrequencyKHz);
//     Serial.println(aHeaderMarkMicros);
//     Serial.println(aHeaderSpaceMicros);
//     Serial.println(aOneMarkMicros);
//     Serial.println(aOneSpaceMicros);
//     Serial.println(aZeroMarkMicros);
//     Serial.println(aZeroSpaceMicros);
//     Serial.println(aData);
//     Serial.println(aNumberOfBits);
//     Serial.println(aFlags);
//     Serial.println(aRepeatPeriodMillis);
//     Serial.println(aNumberOfRepeats);

//     IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, aData, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
//   }
//   else
//   {
//     Serial.print("Command Send Failed");
//   }
//   return returnValue ;
//   // IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, 0x2D, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
// }


// DataLakeIRHelper:: receiveIRData()
{
    boolean returnValue = false;
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
    }
    IrReceiver.start();
  return returnValue ;

}