const int firstled = 3;
const int secondled = 5;
const int thirdled = 6;

int brightness = 0;
int increment = 1;

void setup()          //由analogWrite驱动的引脚不需要被声明为输出
{               
  
}

void loop()
{
  if(brightness > 255)
  {
    increment = -1;   //达到255后倒数
  }
  else if(brightness <1)
  {
    increment = 1;     //回到0后正数
  }
  brightness = brightness + increment;  //递增

  //写亮度值到led
  analogWrite(firstled, brightness);
  analogWrite(secondled, brightness);
  analogWrite(thirdled, brightness);
  delay(10);
}

