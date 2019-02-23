#include "Timer.h"    
Timer t;  
int tim;


void call()
{
  tim++;
  if(tim >10)
  {
    tim = 8;
  }
}
void pwm_out(int zhan_kong)
{
 digitalWrite(3,HIGH);
 delayMicroseconds(zhan_kong);
 digitalWrite(3,LOW);
 delay(19-(zhan_kong/1000));   //50Hz 的频率
}

void setup() 
{
  pinMode(3,OUTPUT);  
  t.every(1000,call);
  tim = 0;
  //jiao_zun();
  //delay(1500);
}

void loop() 
{
  t.update();
  if(tim<=3)
   { 
    pwm_out(2050);    //占空比 10.8%
    }  
  else if(tim<=5 && tim>3)
   { 
    pwm_out(1020);
    }
    else
   {
      pwm_out(1100);
   }
  /*
  digitalWrite(3, HIGH);   // sets the pin on
  delayMicroseconds(1000);        // pauses for 50 microseconds
  digitalWrite(3, LOW);    // sets the pin off
  delayMicroseconds(31000);  //产生准确延迟的最大值是16383
  */
 // analogWrite(3,125);
} 
