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
          Serial.println("receive via BlueTooth:"+phoneData);
          return phoneData;
        }
        return phoneData;
  }
  //发送字符
  void replyBlueTooth(String data){
		//调试打印输出
        Serial.println("reply BlueTooth:"+data);
        //蓝牙模块发送数据
        SerialBlueTooth.println(data);
    }
