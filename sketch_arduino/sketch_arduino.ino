#include <SoftwareSerial.h>

#define SERIAL_BAUD_RATE 9600

#define BULE_TOOTH_PIN_TX  7
#define BULE_TOOTH_PIN_RX  8
#define ULTR_SOUND_ECHO  9
#define ULTR_SOUND_TRIG  10

#define COMMAND_HEADER_LENGTH  2
#define COMMAND_ACTIVITY_INDEX  3
#define COMMAND_ACTIVITY_LENGTH  2



#define MAX_RANGING_DISTANCE 1500.0f
int DEBUG_MODE = 0 ;
int DEBUG_MODE_DISTANCE_CONTINUOUS = 0 ;

//蓝牙串口声明
SoftwareSerial SerialBlueTooth(BULE_TOOTH_PIN_TX, BULE_TOOTH_PIN_RX);

//超声波模块引脚定义
const int trig = ULTR_SOUND_TRIG;    // 触发信号
const int echo = ULTR_SOUND_ECHO;    // 反馈信号

String ON = "on"; 

//命令前缀
String DISTANCE = "DI";  //距离
String TEMPERATURE = "TE"; //温度
String HUMIDTY = "HU";   //湿度S

//串口调试命令
String STOP = "STOP";   //停止
String DEBUG = "debug"; 
String MASSAGES = "";

//下划线
String UNDERLINE = "_";

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  setupBlueTooth();
  setupUltrsound();
}

void loop() {
   while(1){
	   
    //命令模式
	String command = receiveCmdViaBlueTooth();	
	handleMsgViaBlueTooth(command);	

    
    


	//调试模式
	String massageS = receiveCmdViaSerial();
	handleMsgViaSerial(massageS);


      
   }
}

void handleMsgViaBlueTooth(String cmd){
	if(cmd.startsWith(DISTANCE)){
		replyBlueTooth(getDistance());
    }
	
}

void handleMsgViaSerial(String cmd){
	//设置退出标志位

  if( DEBUG_MODE_DISTANCE_CONTINUOUS ){
     handleDistanceInDebug("di on");
  }
	if(cmd.startsWith(DISTANCE) ){
	   handleDistanceInDebug(cmd);
	}
	
}

void handleDistanceInDebug(String cmd){
  //Serial.println("handleDistanceInDebug: "+cmd);
	bool enable = checkActivity(cmd);
  //Serial.println("enable: "+String(enable));
	   if (checkDistanceContinuous(cmd)){
		   DEBUG_MODE_DISTANCE_CONTINUOUS = 1;
	   }
	   if(DEBUG_MODE_DISTANCE_CONTINUOUS || enable ){
		   Serial.println(getDistance());
	   } 
	   if(!enable){
		   DEBUG_MODE_DISTANCE_CONTINUOUS = 0;
	   }
   //Serial.println("DEBUG_MODE_DISTANCE_CONTINUOUS: "+String(DEBUG_MODE_DISTANCE_CONTINUOUS));
}


bool checkActivity(String str){
  //Serial.println("checkActivity str: "+str);
  String result = str.substring(COMMAND_ACTIVITY_INDEX,COMMAND_ACTIVITY_INDEX+COMMAND_ACTIVITY_LENGTH);
  //Serial.println("checkActivity result: "+result);
  result.toLowerCase();
	return result.equals(ON);
}

bool checkDistanceContinuous(String str){
  String result = str.substring((str.length() -3));
  //Serial.println("checkDistanceContinuous result: "+result);
  result.toLowerCase();
  return result.equals("con");
}


