#include <IRremote.h>
int RECV_PIN = 11;          //红外接收引脚定义
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // 开始接收
  Serial.println("Enabled IRin");
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value);
    irrecv.resume();    // 接收下一个值
  }
  delay(100);
}
