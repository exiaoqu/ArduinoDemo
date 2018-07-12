#include <Servo.h> 

#define  STEERING_DELAY_TIME_BASE 400
#define  STEERING_ANGLE_BASE  10
#define  STEERING_ANGLE_DETLA  3

Servo mySteering;  
                // 最多可以控制8路舵机
 
int pos = 0;    // 用于存储舵机位置的变量
//0 angle, 1: delay time

//长亭外，古道边
//芳草碧连天
int myPosition[13][2] = {{5,2},{3,1},{5,1},{8,4}, {6,2},{8,2},{5,5},
                      {5,2},{1,1},{2,1},{3,1},{2,1},{1,1}
                      };

//初始化
void setupSteering() 
{ 
  mySteering.attach(STEERING_PIN);  // 舵机控制信号引脚 
} 

void oneAction(int x, int y){
  //转5*10, 听 2*100
   mySteering.write(x*STEERING_ANGLE_BASE);               
   delay(y*STEERING_DELAY_TIME_BASE);
   mySteering.write(0);
   delay(x*STEERING_ANGLE_DETLA*STEERING_ANGLE_BASE);
   
}
void steeringPlay(){
//  for(int i = 0;i <13 ;i++  ){
//      oneAction( myPosition[i][0], myPosition[i][1]);
//    }

mySteering.write(360);
delay(4000);
mySteering.write(0);
delay(2000);
//mySteering.write(720);
//delay(100);
//mySteering.write(3600);
//delay(100);

    
  }
 
//主循环
//void loop() 
//{ 
//  for(pos = 0; pos < 180; pos += 1)  // 从0度-180度
//  {                                  // 步进角度1度
//    myservo.write(pos);              // 输入对应的角度值，舵机会转到此位置
//    delay(1);                       // 1ms后进入下一个位置 
//  } 
//  for(pos = 180; pos>=1; pos-=1)     // 从180度-0度 
//  {                                
//    myservo.write(pos);              // 输入对应的角度值，舵机会转到此位置 
//    delay(1);                       // 1ms后进入下一个位置
//  } 
//} 


