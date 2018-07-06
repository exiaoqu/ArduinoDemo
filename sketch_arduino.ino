#include <SoftwareSerial.h>

//蓝牙串口声明
SoftwareSerial SerialBlueTooth(7, 8);//Tx 7 , Rx 8

//超声波模块引脚定义
const int trig = 10;    // 触发信号
const int echo = 9;    // 反馈信号

//命令前缀
String distance = "DISTANCE";  //距离
String temperature = "TEMPERATURE"; //温度
String humidty = "HUMIDITY";   //湿度
String blind = "BLIND";   //导盲
String stop = "STOP";   //停止
//串口调试命令
String debug = "debug"; 

//下划线
String underline = "_";

void setup() {
  Serial.begin(9600);
  setupBlueTooth();
  setupUltrsound();
}

void loop() {
   while(1){

    String command = receivebt();

    if(command.startsWith(distance)){
         sendbt(length());
      }

    }   
}

