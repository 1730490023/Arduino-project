/*
 * 每十分之一秒递减一次的倒数计时器
 * 到0时点亮LED
 * 按下按钮递增计数，持续按钮递增速率
 */

 const int ledPin = 13;            //输出引脚
 const int inPin  = 2;             //输入引脚
 const int debounceTime = 20;      //要求的时间毫秒数
 const int fastIncrement = 1000;   //达到这个数后递增加快
 const int veryFastIncrement = 400; //大到这个数后递增更快
 int count = 0;                     //计数每十分之一秒递减一次

 void setup()
 { 
   pinMode(inPin,INPUT);
   digitalWrite(inPin,HIGH);
   pinMode(ledPin,OUTPUT);
   Serial.begin(9600);
 }

void loop()
{
  int duration = switchTime();
  if( duration > veryFastIncrement)
    count = count + 10;
  else if(duration > fastIncrement)
    count = count + 4;
  else if( duration >debounceTime)
    count = count +1;
  else 
  {
    if( count == 0)
     {
       digitalWrite(ledPin,HIGH);  //如果count为0 就点亮led
     }
    else
     {
      digitalWrite(ledPin,LOW);  //如果count不为0 就熄灭led
      count = count -1;          //并递减count
     }
  }
  Serial.println(count);
  delay(100); 
}

long switchTime()              //返回开关被按下的以毫秒为单位的时间
{
  static unsigned long startTime = 0;  //开关状态变化第一次被检测到
  static boolean state;                //开关的当前状态
  if(digitalRead(inPin) != state)      //检查是否开关状态已改变
  {
    state = ! state;                  //是的，逆转状态
    startTime = millis();             //存储该时间
  }
  if(state ==LOW)
     return millis() - startTime;  //开关按下，返回时间
  else
    return 0;                      //如果没有被按下，就返回0
}







