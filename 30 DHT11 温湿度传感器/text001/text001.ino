/*
 * 温湿度传感器程序
 */


#include <dht11.h>
#include <Arduino.h>
dht11 DHT11;
#define DHT11PIN 2
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //Serial.println("/n");
  int chk = DHT11.read(DHT11PIN);
  // Serial.print("Read sensor: ");
   /*
  switch (chk)
  {
    case DHTLIB_OK: 
                Serial.println("OK"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.println("校验和错误"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.println("超时错误"); 
                break;
    default: 
                Serial.println("未知错误"); 
                break;
  }
   */
  Serial.print("Temp:");
  Serial.print((float)DHT11.temperature, 2);
  Serial.print("  Hum:");
  Serial.println((float)DHT11.humidity, 2);
 //delay(1000);
}
