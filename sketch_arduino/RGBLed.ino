#define GREEN_LED_PIN  9
#define RED_LED_PIN  10
#define BLUE_LED_PIN  11

#define BREATH_Ligth_DELAY  3000
#define BREATH_Ligth_BRIGHT 50


//RGB灯点亮模式：0,绿灯亮 1,红灯闪 2,蓝灯亮

int gRGBMode =0;

const double pi = 3.1415926;

unsigned long gLastRedLightTime = 0L;
unsigned long gLastBlueLightTime = 0L;
unsigned long gLastRedTrigTime = 0L;
unsigned long gLastBlueTrigTime = 0L;

int RED_DURATION_TIME = 3000;

int BLUE_DURATION_TIME = 500;

//初始化
void setupRGB() {
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}
void ledExcuter(){
   RGBModeController();
   switch(gRGBMode){
          case 0:
            lightenGreen();
            break;
          case 1:
            blinkRed();
            break;
          case 2:
            lightenBlue();
            break;
        }  
  }
void redTrigController(unsigned long trigTime){
  printLog(DEBUG_MODE,"redTrigController :");
    gLastRedTrigTime = trigTime;
    gRGBMode = 1;           
  }

void blueTrigController(){
  printLog(DEBUG_MODE,"blueTrigController :");
    gLastBlueTrigTime = millis();
    gRGBMode = 2; 
  }

void greenTrigController(){
  printLog(DEBUG_MODE,"greenTrigController :");
    gRGBMode = 0; 
  }
  
void RGBModeController(){
  if(gRGBMode == 1){
     if((millis() - gLastRedTrigTime ) > RED_DURATION_TIME){
        blueTrigController();
          }
    }
   if(gRGBMode == 2){
     if((millis() - gLastBlueTrigTime ) > BLUE_DURATION_TIME){
        greenTrigController();    
          }
    }
 }



void darkLight(){
   analogWrite(RED_LED_PIN,  0);
   analogWrite(GREEN_LED_PIN,  0);
   analogWrite(BLUE_LED_PIN, 0);
  }

void lightenBlue(){
   //printLog(DEBUG_MODE,"lightenBlue :");
   analogWrite(RED_LED_PIN,  255);
   analogWrite(GREEN_LED_PIN,  0);
   analogWrite(BLUE_LED_PIN, 0);
  }

void lightenRed(){
   //printLog(DEBUG_MODE,"lightenRed :");
   analogWrite(RED_LED_PIN,  0);
   analogWrite(BLUE_LED_PIN, 0);
   analogWrite(GREEN_LED_PIN,  255);
  }

void lightenGreen(){
   //printLog(DEBUG_MODE,"lightenGreen :");
   analogWrite(BLUE_LED_PIN,  breathLigth());
   analogWrite(RED_LED_PIN,  0);
   analogWrite(GREEN_LED_PIN,  0);
  }

int breathLigth(){
   double e;
   e = BREATH_Ligth_BRIGHT*sin((2*pi/BREATH_Ligth_DELAY)*(millis()%BREATH_Ligth_DELAY));
   int i = (int)e+BREATH_Ligth_BRIGHT;
   return i;
  }
