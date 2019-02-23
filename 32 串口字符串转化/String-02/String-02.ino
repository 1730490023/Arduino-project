/*
 * 将一个数字转换为字符串的程序
 */

void setup() {
  Serial.begin(9600);
}
char buffer[12];

void loop() {
   long value = 12345;
   ltoa(value,buffer,10);
   Serial.print(value);
   Serial.print("has");
   Serial.print(strlen(buffer));
   Serial.print("digits");
   value = 12345679;
   ltoa(value,buffer,10);
   Serial.print(value);
   Serial.print("has");
   Serial.print(strlen(buffer));
   Serial.print("digits");
   delay(1000);
}
