/*
 * 麦轮小车 .cpp文件
 * 
 */

#include "MAILUN.h"
#include "Arduino.h"

MAILUN::MAILUN()          //构造函数
{    }

void MAILUN::OMNI()       //计算电机的PWM值
{
    yspeed = 255/2;
    xspeed = yspeed*(tan(3.1415926/(180/jiaodu/*角度*/)));
    w1=yspeed - xspeed;
    w2=yspeed + xspeed;
    w3=yspeed - xspeed;
    w4=yspeed + xspeed;
}

void MAILUN::PWM()       //将PWM值赋给每个电机
{
	if(w1 >= 0)
  {
    analogWrite(4,w2);   //正转   1号
  }
  else
  {
    analogWrite(5,w2);   //反转
  }
  
  if(w2 >= 0)
  {
    analogWrite(2,w1);   //正转   2号
  }
  else
  {
    analogWrite(3,w1);   //反转
  }

  if(w3 >= 0)
  {
    analogWrite(6,w3);   //正转   3号
  }
  else
  {
    analogWrite(7,w3);   //反转
  }
  if(w4 >= 0)
  {
    analogWrite(8,w4);   //正转   4号
  }
  else
  {
    analogWrite(9,w4);   //反转
  }
}
