//#define YELLOW_1_LED_PIN  2
//#define YELLOW_2_LED_PIN  3
//#define RED_1_LED_PIN  5
//#define RED_2_LED_PIN  6
//#define GREEN_1_LED_PIN   11
//#define GREEN_2_LED_PIN   13
//
//
//unsigned long gLastYELLOW_1_Time = 0L;
//unsigned long gLastYELLOW_2_Time = 0L;
//unsigned long gLastRED_1_Time = 0L;
//unsigned long gLastRED_2_Time = 0L;
//unsigned long gLastGREEN_1_Time = 0L;
//unsigned long gLastGREEN_2_Time = 0L;
//
//
//
//int ledState = HIGH;    
//int a[3] =  {YELLOW_1_LED_PIN, RED_1_LED_PIN, GREEN_1_LED_PIN };
//unsigned long count = 0L;
//void setupLED() {
//  // 初始化引脚输出模式
//  pinMode(YELLOW_1_LED_PIN, OUTPUT);      
//  pinMode(YELLOW_2_LED_PIN, OUTPUT);  
//  pinMode(RED_1_LED_PIN, OUTPUT);  
//  pinMode(RED_2_LED_PIN, OUTPUT);  
//  pinMode(GREEN_1_LED_PIN, OUTPUT);  
//  pinMode(GREEN_2_LED_PIN, OUTPUT); 
//
//  for(int i = 0; i< 3; i++){
//    digitalWrite(a[i], LOW);
//  }
//   
//
//}
//
//void blinkLED(unsigned long curTime,int durationTime){
//    
//      gDURATION_TIME = durationTime;
//      
//     
//      //printLog(DEBUG_MODE,"curTime - gLastYELLOW_1_Time :" + String(curTime - gLastYELLOW_1_Time ));
//      //printLog(DEBUG_MODE,"gDURATION_TIME :" + String(gDURATION_TIME ));
//      
//      if((curTime - gLastYELLOW_1_Time )>  gDURATION_TIME){
//        switch(count%3){
//          case 0:
//            digitalWrite(a[0], HIGH);
//            digitalWrite(a[1], LOW);
//            digitalWrite(a[2], LOW);
//            break;
//          case 1:
//            digitalWrite(a[0], LOW);
//            digitalWrite(a[1], HIGH);
//            digitalWrite(a[2], LOW);
//            break;
//          case 2:
//            digitalWrite(a[0], LOW);
//            digitalWrite(a[1], LOW);
//            digitalWrite(a[2], HIGH);
//            break;
//        }
//        gLastYELLOW_1_Time = curTime;
//        //delay(1000);
//        count ++;
//      }
//
//
//  }
//

