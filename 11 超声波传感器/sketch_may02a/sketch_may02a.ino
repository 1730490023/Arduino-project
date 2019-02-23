const int pingPin = 5;
const int ledPin  = 13;  //连接led的引脚
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin , OUTPUT);
}

 void loop()
 {
  int cm = ping(pingPin);
  Serial.println(cm);
  digitalWrite(ledPin, HIGH);
  delay(cm * 10);          //每厘米增加了10ms的延时
  digitalWrite(ledPin , LOW);
  delay( cm * 10);
 }

 //返回厘米距离
int ping(int pingPin)
{
  //建立脉冲持续时间变量
  //以英寸和厘米表示距离的结果
  long duration ,cm;     
  //由2个或多个微妙的高电位脉冲触发
  //给一个简短的低脉冲以确保干净的高电位脉冲    
  pinMode(pingPin,OUTPUT);   
  digitalWrite(pingPin , LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin ,HIGH);

  //把时间转换成距离
  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds)
{
  //声音的速度为340m/s或29us/cm
  //脉冲传播出来再折返回来，所以所求对象的距离是一半的行程
  return microseconds/ 29 /2;
}













