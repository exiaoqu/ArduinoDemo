 //初始化
  void setupBlueTooth() {
    SerialBlueTooth.begin(9600);
  }
  //接收命令
  String  receivebt(){
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
          Serial.println("receive:"+phoneData);
          //清空缓存
         return phoneData;
        }
        return phoneData;
  }
  //发送字符
  void sendbt(String data){
        //蓝牙模块发送数据
        SerialBlueTooth.println(data);  
        //调试打印输出
        Serial.println("send:"+data);   
    }
