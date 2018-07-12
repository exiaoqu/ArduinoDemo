//************************************
//#########################
//public API
//#########################
void printLog(int logLevel, String str){
  if(LOG_LEVEL >= logLevel ){
     Serial.println(str);
  }  
}


bool checkActivity(String str) {
  printLog(DEBUG_MODE_DETAIL,"checkActivity str: " + str);
  String result = str.substring(COMMAND_ACTIVITY_INDEX, COMMAND_ACTIVITY_INDEX + COMMAND_ACTIVITY_LENGTH);
  printLog(DEBUG_MODE_DETAIL,"checkActivity result: " + result);
  result.toLowerCase();
  return result.equals(ON);
}

bool checkDistanceContinuous(String str) {
  String result = str.substring((str.length() - 3));
  printLog(DEBUG_MODE, "checkDistanceContinuous result: " + result);
  result.toLowerCase();
  return result.equals("con");
}



