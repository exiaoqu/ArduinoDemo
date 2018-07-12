
#include <dht.h>
dht DHT;
#define DHT11_PIN 4//put the sensor in the digital pin 4  
void setupHumidty()
{
  //  Serial.print("DHT PROGRAM ");
  //  Serial.print("LIBRARY VERSION: ");
  //  Serial.println(DHT_LIB_VERSION);
  //  Serial.println();
}

void temperature(bool isSerial) {
  int chk = DHT.read11(DHT11_PIN);
  String data = TEMPERATURE + UNDERLINE +  DHT.temperature;
  reply[isSerial](data);
}

void humidity(bool isSerial)
{
  //   READ DATA
  //  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  String data = HUMIDTY + UNDERLINE +  DHT.humidity;
  reply[isSerial](data);

  //  switch (chk)
  //  {
  //    case 0:  Serial.print("OK,\t"); break;
  //    case -1: Serial.print("Checksum error,\t"); break;
  //    case -2: Serial.print("Time out error,\t"); break;
  //    default: Serial.print("Unknown error,\t"); break;
  //  }
  // DISPLAT DATA
  //  Serial.print(DHT.humidity,1);
  //  Serial.print(",\t");
  //  Serial.println(DHT.temperature,1);


}



