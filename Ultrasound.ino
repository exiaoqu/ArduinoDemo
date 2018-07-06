
//初始化
void setupUltrsound() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

//超声波测距
float ranging() {
  long IntervalTime=0; //定义一个时间变量
    digitalWrite(trig, 1);//置高电平
    delayMicroseconds(15);//延时15us
    digitalWrite(trig, 0);//设为低电平
    IntervalTime=pulseIn(echo, HIGH);//用自带的函数采样反馈的高电平的宽度，单位us
    float S=IntervalTime/58.00; //使用浮点计算出距离，单位cm
    Serial.println("ranging:"+String(S));//通过串口输出距离数值
    //S=0;IntervalTime=0;//对应的数值清零。
    delay(50);//延时间隔决定采样的频率，根据实际需要变换参数
    return  S;
}
//返回命令结果
String length(){

     String dist = String(ranging());
     String data = distance + underline + dist;
     Serial.println("length:"+data);//通过串口输出拼接数据
     return data;
  }


