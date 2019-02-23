/*
教程请见
https://doc.blinker.app/
快速接入>esp8266MQTT接入
快速接入>esp32MQTT接入
*/

#define BLINKER_PRINT Serial  //物联网控制
#define BLINKER_MQTT
#include <Blinker.h>

char auth[] = "9fc53dc6111a";
char ssid[] = "mi";
char pswd[] = "12345670";

// 新建组件对象
BlinkerButton Button1("btn-cvp");
BlinkerNumber Number1("num-782");

int counter = 0;
int led = 9;
// 按下按键即会执行该函数
void button1_callback(const String & state)
{
    BLINKER_LOG2("get button state: ", state);
    digitalWrite(4, !digitalRead(4));
}

void setup()
{
    // 初始化串口
    Serial.begin(115200);
    // 初始化有LED的IO
    pinMode(led, OUTPUT);
    digitalWrite(4, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    //注册回调函数
    Button1.attach(button1_callback);  
}

void loop()
{
    Blinker.run();
    // 如果未绑定的组件被触发，则会执行其中内容
//    if (Blinker.available())
//    {
//        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());
//        counter++;
//        Number1.print(counter);
//    }
//   digitalWrite(led,HIGH);
//   delay(200);
//   digitalWrite(led,LOW);
//   delay(200);
}
