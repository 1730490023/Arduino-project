#ifndef MAILUN_H
#define MAILUN_H
#include "Arduino.h"

class MAILUN               //定义一个类
{
public:
	MAILUN();                //构造函数
  int jiaodu;              //角度变量
	void OMNI();             
	void PWM();
  int xspeed;               //小车x轴方向速度
  int yspeed;               //小车y轴方向速度
  int w1,w2,w3,w4;          //4个电机的速度 
private:
	
};

#endif()
