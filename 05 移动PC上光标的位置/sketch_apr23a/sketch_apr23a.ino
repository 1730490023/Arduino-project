/*
 * 基于两个电位器的位置移动鼠标的位置
 * 
 */
const int buttonPin = 2;    //数字引脚上的低电位打开鼠标

const int potXPin = 5;      //电位器用的模拟引脚
const int potYPin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(potXPin,INPUT);
  pinMode(potYPin,INPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH); 
}

void loop()
{
  //Serial.write("Data"); 
  int x = (512 - analogRead(potXPin)) / 4;  //范围是 -127~127
  int y = (512 - analogRead(potYPin)) / 4;
  Serial.print("Data,");
  //Serial.print(",");
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print(y,DEC);
  Serial.print(",");
  if(digitalRead(buttonPin) == LOW)
    Serial.print(1);        //当按键按下时发送 1 
  else
    Serial.print(0);
  Serial.print(",");
  delay(50);              //每秒发送位置20次
}


