int RED_BLINK_TIME = 100;


unsigned long gLastRedBlinkTime = 0L;

unsigned long count = 0L;

void blinkRed(){

      if((millis() - gLastRedBlinkTime )>  RED_BLINK_TIME){
        switch(count%2){
          case 0:
            //printLog(DEBUG_MODE,"lightenRed :"+count);
            lightenRed();
            break;
          case 1:
            darkLight();
            break;
        }
        gLastRedBlinkTime = millis();
        count ++;
      }
  }
