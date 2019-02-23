   /*
 * 模拟iic协议的  oled驱动程序
 * 适用于 esp8266 , Arduinoc uno, nano, mini
 */


#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 5    //黄色
#define SCL_PIN 4
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
void setup()
{
  delay(1000);
  display.initialize();
}
void loop()
{
//  display.drawLine(0, 0, 127, 63,WHITE);
//  display.update();
  delay(1000);
  display.clear();
  
  display.setTextSize(1);
  //display.setTextColor(WHITE);
  display.setCursor(20,0);   //x，y轴
  display.println("Hello, world!");
  
  display.setTextColor(BLACK, WHITE); // 'inverted' text
   display.setCursor(0,20);   //x，y轴
  display.println(3.141592);
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
   display.setCursor(0,40);   //x，y轴
  display.print("0x");
  display.println(0xDEADBEEF, HEX);
  display.update();
  delay(2000);
  display.clear();
  while(1);
}
