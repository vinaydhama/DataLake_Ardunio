
#include <IRremote.h>
#include <stdlib.h>
const int IRSend_PIN = 3;


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
  char buf[4] = {};
  char Secondhalf[2] = {};

//IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);

uint16_t ConverStringTouint16_t(String StringToConvert) {
  uint16_t ConvertrdValueHolder = 0;

  Serial.println(StringToConvert);
  StringToConvert.toCharArray(buf, StringToConvert.length());
  Secondhalf[0] = buf[2];
  Secondhalf[1] = buf[3];
  Secondhalf[2] = '\0';

  // Serial.print("Secondhalf ");
  // Serial.println(Secondhalf);
  buf[2] = '\0';
  int aa = atoi(buf) * 100 + atoi(Secondhalf);
  // Serial.print("int ");
  // Serial.println(aa);
  ConvertrdValueHolder = (uint16_t)aa;
  Serial.println("Value Converted is ");
  Serial.println(ConvertrdValueHolder);
  return ConvertrdValueHolder;
}

uint_fast8_t ConverStringTouint_fast8_t(String StringToConvert) {
  uint_fast8_t ConvertrdValueHolder = 0;
  //   char Firsthalf[2];
  //   char Secondhalf[2];
  Serial.print(StringToConvert);
  StringToConvert.toCharArray(buf, StringToConvert.length());
  //  Secondhalf[0]= buf[2];
  //  Secondhalf[1]= buf[3];
  //  Secondhalf[2]= '\0';

  // Serial.print("Secondhalf ");
  // Serial.println(Secondhalf);
  buf[1] = '\0';
  //  int aa = atoi(buf);
  int aa = StringToConvert.toInt();

  // //*100 +  atoi(Secondhalf) ;
  Serial.print("int ");
  Serial.println(aa);
  ConvertrdValueHolder = (uint8_t)aa;
  Serial.print("Value Converted is ");
  Serial.println(ConvertrdValueHolder);
  return ConvertrdValueHolder;
}

void setup() {
  Serial.begin(115200);
  pinMode(IRSend_PIN, OUTPUT);
  IrSender.begin(IRSend_PIN);
  // put your setup code here, to run once:
}
// enum TypetoConvert {

// }

void SendsendPulseDistanceWidth(String sFrequencyKHz, String sHeaderMarkMicros, String sHeaderSpaceMicros, String sOneMarkMicros, String sOneSpaceMicros, String sZeroMarkMicros, String sZeroSpaceMicros, String sData, String sNumberOfBits, String sFlags, String sRepeatPeriodMillis, String sNumberOfRepeats) {

  // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, true, 2, 4);

  aFrequencyKHz = ConverStringTouint_fast8_t(sFrequencyKHz);
  aHeaderMarkMicros = ConverStringTouint16_t(sHeaderMarkMicros);
  aHeaderSpaceMicros = ConverStringTouint16_t(sHeaderSpaceMicros);
  aOneMarkMicros = ConverStringTouint16_t(sOneMarkMicros);
  aOneSpaceMicros = ConverStringTouint16_t(sOneSpaceMicros);
  aZeroMarkMicros = ConverStringTouint16_t(sZeroMarkMicros);
  aZeroSpaceMicros = ConverStringTouint16_t(sZeroSpaceMicros);
//sData
  aNumberOfBits = ConverStringTouint16_t(sNumberOfBits);
  aRepeatPeriodMillis = ConverStringTouint16_t(sRepeatPeriodMillis);
  aNumberOfRepeats = ConverStringTouint16_t(sNumberOfRepeats);

  // if( aFrequencyKHz != "" && aHeaderMarkMicros != "" && aHeaderSpaceMicros != "" && aOneMarkMicros != "" && aOneSpaceMicros != "" && aZeroMarkMicros != "" && aZeroSpaceMicros != "" && aData != "" && aNumberOfBits != "" && aFlags != "" && aRepeatPeriodMillis != "" && aNumberOfRepeats)
  // {

  // }
  IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, 450, aZeroSpaceMicros, 0x2D, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);

  // IrSender.sendPulseDistanceWidth(aFrequencyKHz, aHeaderMarkMicros, aHeaderSpaceMicros, aOneMarkMicros, aOneSpaceMicros, aZeroMarkMicros, aZeroSpaceMicros, 0x2D, aNumberOfBits, true, aRepeatPeriodMillis, aNumberOfRepeats);
}


void loop() {

  String DataToCovert = Serial.readString();
  //char[]  DataToCovertARRAY[];
  // DataToCovert.toCharArray(DataToCovertARRAY,StringToConvert.length());
  // DataToCovertARRAY= strtok (DataToCovertARRAY,",");
  if (DataToCovert != "") {
    // IrSender.begin(IRSend_PIN);
    // IrSender.sendPulseDistanceWidth(38, 1350, 350, 1300, 400, 450, 1200, 0x2D, 11, true, 2, 4);
    SendsendPulseDistanceWidth("38" ,"1350","350","1300","400","450","1200","0x2D","11","true","2","4");
    //SendsendPulseDistanceWidth("38", "1250", "1450", "1250", "450", "400", "1300", "0x20D", "11", "true", "2", "4");
  }
  // SendsendPulseDistanceWidth(DataToCovertARRAY[0],DataToCovertARRAY[1]);
}
// put your main code here, to run repeatedly:
