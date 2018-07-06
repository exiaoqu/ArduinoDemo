
  String  receiveCmdViaSerial(){
    String debugData="";
      if (Serial.available())
      {
        while (Serial.available() > 0)
        {
          //将窗口数据缓存
          debugData += char(Serial.read());
          delay(2);
        }
        //调试打印输出
        Serial.println("receive from Serial: "+debugData);
      }
      debugData.trim();
      
    return debugData;
  }
