//火焰传感器
int fireAlarmSensorPin = A0;    // 模拟输入引脚
int fireAlarmLedPin = 13;       // led指示灯引脚
int fireAlarmSensorValue = 0;  //  模拟输入数值变量
int FIRE_THRESHOLD_VALUE = 50;
int FIRE_DELAY = 2000;
long lastTime = 0L;

void setupFireAlarm() {
  // 声明引脚为输出模式
  pinMode(fireAlarmLedPin, OUTPUT);  
  //Serial.begin(SERIAL_BAUD_RATE);
}

void fireDectect(unsigned long curTime){
   // 读取电位器电压值
  fireAlarmSensorValue = analogRead(fireAlarmSensorPin);    
  
  //digitalWrite(fireAlarmLedPin, LOW);  
 //digitalWrite(fireAlarmLedPin, HIGH);   
    

  if(fireAlarmSensorValue > FIRE_THRESHOLD_VALUE){

  //灯闪
   // 使用读取的这个模拟量值作为演示时间，单位ms，范围0-1023
  //delay(fireAlarmSensorValue);          
  // 熄灭led，LY-51S独立模块开发板上led模块则是点亮led 
 digitalWrite(fireAlarmLedPin, HIGH);
 delay(100);  
  digitalWrite(fireAlarmLedPin, LOW);    
  // 使用读取的这个模拟量值作为演示时间，单位ms，范围0-1023
  //delay(fireAlarmSensorValue);
    
     String sensorValue = String(fireAlarmSensorValue);
     String data = FIREALARM + UNDERLINE + sensorValue;
      // 打印传感器数值

      if((curTime - lastTime )>  FIRE_DELAY){
        printLog(DEBUG_MODE,"fireAlarmSensorValue result: "+String(fireAlarmSensorValue));
      //reply[BULE_TOOTH_MODE]("hb");
      replyBlueTooth(data);

      lastTime = curTime;
      }
  
    
    }
  }

