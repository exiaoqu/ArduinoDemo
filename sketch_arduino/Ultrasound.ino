//延时间隔决定采样的频率，根据实际需要变换参数
#define  DELAY_TIME    50


unsigned long gLastTime = 0L;
bool gIsFromSerial = false;
bool gIsOn = false;
bool gIsCon = false;



//初始化
void setupUltrSound() {
  pinMode(ULTR_SOUND_ECHO_PIN, INPUT);
  pinMode(ULTR_SOUND_TRIG_PIN, OUTPUT);
}

//超声波测距
float ranging() {
  long IntervalTime = 0; //定义一个时间变量
  digitalWrite(ULTR_SOUND_TRIG_PIN, 1);//置高电平
  delayMicroseconds(15);//延时15us
  digitalWrite(ULTR_SOUND_TRIG_PIN, 0);//设为低电平
  IntervalTime = pulseIn(ULTR_SOUND_ECHO_PIN, HIGH); //用自带的函数采样反馈的高电平的宽度，单位us
  float S = IntervalTime / 58.00; //使用浮点计算出距离，单位cm
  printLog(DEBUG_MODE_DETAIL,"ranging:" + String(S)); //通过串口输出距离数值
  //S=0;IntervalTime=0;//对应的数值清零。
  //delay(50);//延时间隔决定采样的频率，根据实际需要变换参数
  return  S;
}

void setParameters(bool isSerial , bool isOn, bool isCon) {
   printLog(DEBUG_MODE_DETAIL,"setParameters： isOn=" + String(isOn) + " isSerial=" + isSerial  + " isCon=" + isCon);
  gIsFromSerial = isSerial;
  gIsOn = isOn;
  gIsCon = isCon;
}

//返回命令结果
void getDistance(unsigned long curTime) {
  if(!gIsOn){
    gIsCon = false;
  }
  if(!isUltraSoundAvalable(curTime) || !gIsOn){
     return;
  }
   printLog(DEBUG_MODE_DETAIL," getDistance： isOn=" + String(gIsOn) + " isSerial=" + String(gIsFromSerial));
   float dis = ranging();
  while (MAX_RANGING_DISTANCE < dis) {
    printLog(DEBUG_MODE,"Distance abnormal :" + String(dis));
    gLastTime = 0;
  }
  String dist = String(dis);
  String data = DISTANCE + UNDERLINE + dist;
  printLog(DEBUG_MODE_DETAIL," getDistance：Distance :" + data);//通过串口输出拼接数据
  reply[gIsFromSerial](data);
  if(!gIsCon) {
    gIsOn = false;
  }
  

  
  gLastTime = curTime;
}

bool isUltraSoundAvalable(unsigned long curTime){
  if((curTime - gLastTime)> DELAY_TIME){  
    return true;
  }
  return false;
}



//


