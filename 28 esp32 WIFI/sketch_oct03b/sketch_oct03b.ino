/*
教程请见
https://doc.blinker.app/
快速接入>esp8266 WiFi接入
快速接入>esp32 WiFi接入
*/
 
#define BLINKER_PRINT Serial
#define BLINKER_WIFI

#include <Blinker.h>

char ssid[] = "L223";
char pswd[] = "shiyanshi223";

// 新建组件对象
BlinkerButton Button1("btn-ghx");
BlinkerNumber Number1("num-54v");

int counter = 0;

// 按下按键即会执行该函数
void button1_callback(const String & state) 
{
    BLINKER_LOG2("get button state: ", state);
    digitalWrite(4, !digitalRead(4));
}

void setup() {
    // 初始化串口
    Serial.begin(115200);
    // 初始化有LED的IO
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
    // 初始化blinker
    Blinker.begin(ssid, pswd);
    Button1.attach(button1_callback);
}

void loop() {
    Blinker.run();
    // 如果未绑定的组件被触发，则会执行其中内容
    if (Blinker.available()) {
        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());
        counter++;
        Number1.print(counter);
    }
}
