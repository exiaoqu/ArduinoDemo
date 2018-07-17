#define RED_BLINK_TIME  75


unsigned long gLastRedBlinkTime = 0L;

unsigned long gCount = 0L;

void blinkRed(){

      if((millis() - gLastRedBlinkTime )>  RED_BLINK_TIME){
        switch(gCount%2){
          case 0:
            //printLog(DEBUG_MODE,"lightenRed :"+count);
            lightenRed();
            break;
          case 1:
            darkLight();
            break;
        }
        gLastRedBlinkTime = millis();
        gCount ++;
      }
  }
