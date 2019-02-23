/*
 * 这是一个麦轮小车跑全方位角度的例程
 * 
 * 作者：林应双
 */
#include"math.h"
#include"MAILUN.h"
MAILUN mailun;         //实例化一个对象
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  mailun.jiaodu=45;            
  MAILUN();
  mailun.OMNI();
  mailun.PWM();
  //Serial.print(",tan=");               //电机PWM  打印测试
  //Serial.println(tan(3.1415926/(180/mailun.jiaodu/*角度*/)));
  /*
  Serial.print(",w1=");
  Serial.print(mailun.w1);
  Serial.print(",w2=");
  Serial.print(mailun.w2);
  Serial.print(",w3=");
  Serial.print(mailun.w3);
  Serial.print(",w4=");
  Serial.print(mailun.w4);
  */
}
