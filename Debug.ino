
void test(){
  String testCommand = "";
  int status = 0;
  //是否有要发送的数据
    if (Serial.available())
    {
      while (Serial.available() > 0)
      {
        //将窗口数据缓存
        testCommand += char(Serial.read());
        delay(2);
      }
      //调试打印输出
      Serial.println("testCommand:"+testCommand);

      if(testCommand.startsWith(distance)){
        status = 1;
        while(status){
          Serial.println("length:"+length());
          }
          
      }
     
    }
  }
