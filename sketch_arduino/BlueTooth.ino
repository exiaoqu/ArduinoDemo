 //初始化
  void setupBlueTooth() {
    SerialBlueTooth.begin(SERIAL_BAUD_RATE);
  }
  //接收命令
  String  receiveCmdViaBlueTooth(){
    String phoneData = "";    // 字符串缓冲区
    
        //蓝牙模块是否接收缓存数据
        if (SerialBlueTooth.available())
        {
          while (SerialBlueTooth.available() > 0)
          {
            //将接收数据缓存
            phoneData += char(SerialBlueTooth.read());
            delay(2);
          }
          //调试打印输出
          phoneData.trim();
          printLog(DEBUG_MODE,"receive via BlueTooth:"+phoneData);
          
          return phoneData + " " + ON;
        }
        return phoneData;
  }

//void initCmd(String data){
//  int len = sizeof(cmdArray)/sizeof(cmdStruct);
//  String cmdType = data.substring(0,COMMAND_HEADER_LENGTH);
//  if(cmd.startsWith(DISTANCE)){
//    memcpy(cmdArray[len].cmd,DISTANCE);
//    cmdArray[len].pfun = &getDistance;
//    
//  }
  
  
          
//}
  
  //发送字符
  void replyBlueTooth(String data){
		//调试打印输出
        printLog(DEBUG_MODE,"reply BlueTooth:"+data);
        //蓝牙模块发送数据
        SerialBlueTooth.println(data);
    }
