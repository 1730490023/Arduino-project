/*
 * 这是一个把逗号分割的文本拆分成组的程序
*/
String text = "peter,paul,mary";
String message = text;
int cp;

void setup() 
{
 Serial.begin(9600);
 
 Serial.println(message);           //显示原字符串
 do
  {
   cp = message.indexOf(',');
   if (cp != -1)
   {
    Serial.println( message.substring(0,cp));
    message = message.substring(cp+1,message.length());
   }
   else                              //这里是被发现的最后一个逗号之后
   {
     if(message.length() > 0)        //如果最后一个逗号后有文字
      Serial.println(message);      //就打印他
   } 
  }
  while(cp >= 0);
}

void loop() {

}
