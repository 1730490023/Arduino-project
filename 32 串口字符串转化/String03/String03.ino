/*
 * 这是一个将字符串转换为数字的程序
 */
const int ledpin = 13;     //led连接的管脚
int blinkdelay;            //闪烁的速度由它决定
char strvalue[6];          //必须达到足够保存全部数字
int index = 0;             //储存所接收到的数字的数组索引

void setup() {
  Serial.print(9600);
  pinMode(ledpin,OUTPUT);  //LED输出引脚
}

void loop() {
   if(Serial.available())
   {
    char ch = Serial.read();
    if(index <5 && isDigit(ch))
    {
      strvalue[index++] = ch;      //在字符串里加上ASCII字符
    }
    else
    {
      strvalue[index] = 0;          //以0终止字符串
      blinkdelay = atoi(strvalue);  //使用atoi将字符串转换为int
      index = 0;
    }
   }
   blink();
}

void blink()
{
  digitalWrite(ledpin,HIGH);
  delay(blinkdelay/2);      //等待闪烁周期的一半
  digitalWrite(ledpin,LOW);
  delay(blinkdelay/2);      //等待另一半
}
  


