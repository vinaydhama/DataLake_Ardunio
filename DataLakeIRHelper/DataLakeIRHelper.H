// DataLakeIRHelper H file
#ifndef DataLakeIRHelper_H
#define DataLakeIRHelper_H
#include "Arduino.h"

 class DataLakeIRHelper
{

public:
     DataLakeIRHelper(int DataLakeIRSend_PIN, int DataLakeIRReceive_PIN);
     // int DataLakeIRSend_PIN;
     // int DataLakeIRReceive_PIN;
     // IniateDataLakeIRSender()

     // boolean sendIRSendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats);
     // boolean receiveIRData();

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
};

#endif