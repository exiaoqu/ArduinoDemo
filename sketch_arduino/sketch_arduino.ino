#include <SoftwareSerial.h>

//**************************************************************************
//###############################################################
// define
//###############################################################
#define SERIAL_BAUD_RATE 9600
#define STEERING_PIN  12
#define BULE_TOOTH_PIN_TX  7
#define BULE_TOOTH_PIN_RX  8

#define ULTR_SOUND_ECHO_PIN  9
#define ULTR_SOUND_TRIG_PIN  10


#define REPLY_METHOD_LENGTH  2
#define COMMAND_HEADER_LENGTH  2
#define COMMAND_ACTIVITY_INDEX  3
#define COMMAND_ACTIVITY_LENGTH  2

#define BULE_TOOTH_MODE  0
#define SERIAL_MODE  1



#define MAX_RANGING_DISTANCE 1500.0f
//**************************************************************************
//###############################################################
// function define
//###############################################################
//蓝牙串口声明
SoftwareSerial SerialBlueTooth(BULE_TOOTH_PIN_TX, BULE_TOOTH_PIN_RX);
void printLog(int logLevel, String str);
bool checkActivity(String str) ;
bool checkDistanceContinuous(String str) ;
void setParameters(bool isSerial , bool isOn, bool isCon);
void getDistance(unsigned long);
void heartBeat(unsigned long);
void replyBlueTooth(String);
void replySerial(String);
void fireDectect(unsigned long curTime);
void setupHumidty();  

void setupUltrSound();
String receiveCmdViaSerial();


void setupSteering(); 

//**************************************************************************
//###############################################################
// global
//###############################################################
int DEBUG_MODE = 0 ;
int DEBUG_MODE_DETAIL = 1 ;
int DEBUG_MODE_DISTANCE_CONTINUOUS = 0 ;
int LOG_LEVEL = DEBUG_MODE;
//超声波模块引脚定义
//const int trig = ULTR_SOUND_TRIG;    // 触发信号
//const int  = ULTR_SOUND_ECHO_PIN;    // 反馈信号

String ON = "on";

//命令前缀
String DISTANCE = "DI";
String FIREALARM = "FI"; //温度
String HUMIDTY = "HU";   //湿度S
String TEMPERATURE = "TE";   //湿度S

//串口调试命令
String STOP = "STOP";   //停止
String DEBUG = "debug";
String MASSAGES = "";

//下划线
String UNDERLINE = "_";

typedef void(*pFunString)(String);
typedef void(*pFunBool)(bool);
typedef void (*pFun)(unsigned long);

struct cmdStruct {
  char cmd[10];
  pFun pfun;
};

cmdStruct cmdArray[] = {
  {"HB", &heartBeat},
  {"FI", &fireDectect},
  {"DI", &getDistance},
  {0, 0}
};



pFunString reply[] = {&replyBlueTooth,
                      &replySerial,
                      0
                     };



void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  setupBlueTooth();
  setupUltrSound();
  setupFireAlarm();
  setupSteering();
  setupHumidty();
}

void loop() {
  while (1) {
   

    //命令模式
    String command = receiveCmdViaBlueTooth();
    if (command.length() > 0) {
      handleMsgViaBlueTooth(command);
    }



    //调试模式
    String massageS = receiveCmdViaSerial();
    if (massageS.length() > 0 ) {
      handleMsgViaSerial(massageS);
    }

   //Rooting
    rooting();
    //经测试，间隔100ms

  }
}
//**************************************************************************
//###############################################################
// handle Msg  begin
//###############################################################
void handleMsgViaBlueTooth(String cmd) {
  handleMsg(false, cmd);
}

void handleMsgViaSerial(String cmd) {  
  handleMsg(true, cmd);
}

void handleMsg(bool isSerial, String cmd) {
  String header = cmd.substring(0, COMMAND_HEADER_LENGTH);
  header.toUpperCase();
  if (header.startsWith("DI")) {
    printLog(DEBUG_MODE_DETAIL, "cmd is: " + cmd);
    handleDistanceInDebug(isSerial,cmd);
  }
  if (header.startsWith("LO")) {
    printLog(DEBUG_MODE, "cmd is: " + cmd);
    handleLogLevel(cmd);
  }
  if (header.startsWith("ST")) {
    printLog(DEBUG_MODE, "cmd is: " + cmd);
    steeringPlay();
  }
  if (header.startsWith("HU")) {
    printLog(DEBUG_MODE, "cmd is: " + cmd);
    humidity(isSerial);
  }

   if (header.startsWith("TE")) {
    printLog(DEBUG_MODE, "cmd is: " + cmd);
    temperature(isSerial);
  }
  printLog(DEBUG_MODE, "just test cmd is: " + cmd);
}


void handleLogLevel(String cmd) {
  printLog(DEBUG_MODE, "handleLogLevel: " + cmd);
  bool isOn = checkActivity(cmd);
  if (isOn) {
    LOG_LEVEL = DEBUG_MODE_DETAIL;
  } else {
    LOG_LEVEL = DEBUG_MODE;
  }
}


void handleDistanceInDebug(bool isSerial,String cmd) {
  printLog(DEBUG_MODE, "handleDistanceInDebug: " + cmd);
  ;  bool isOn = checkActivity(cmd);
  bool isCon = checkDistanceContinuous(cmd);
  printLog(DEBUG_MODE_DETAIL, "handleDistanceInDebug: isSerial " + String(isSerial) + " isOn: " + String(isOn) + " isCon: " + String(isCon));
  setParameters(isSerial, isOn, isCon);
}
//void handleDistanceInDebug(String cmd) {
//  Serial.println("handleDistanceInDebug: " + cmd);
//  bool enable = checkActivity(cmd);
//  Serial.println("enable: " + String(enable));
//  if (checkDistanceContinuous(cmd)) {
//    DEBUG_MODE_DISTANCE_CONTINUOUS = 1;
//  }
//  if (DEBUG_MODE_DISTANCE_CONTINUOUS || enable ) {
//    getDistance(true);
//  }
//  if (!enable) {
//    DEBUG_MODE_DISTANCE_CONTINUOUS = 0;
//  }
//  Serial.println("DEBUG_MODE_DISTANCE_CONTINUOUS: " + String(DEBUG_MODE_DISTANCE_CONTINUOUS));
//}


//**************************************************************************
//###############################################################
// handle Msg  end
//###############################################################


//Rooting
void rooting() {

  unsigned long curTime = millis();
  //fireDectect(curTime);
  //distance
  cmdArray[0].pfun(curTime);
  cmdArray[1].pfun(curTime);
  cmdArray[2].pfun(curTime);
}








