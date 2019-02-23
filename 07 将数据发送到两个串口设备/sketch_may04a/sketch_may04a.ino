#include<SoftwareSerial.h>

int rxPin = 2;
int txPin = 3;
SoftwareSerial mySerial = SoftwareSerial(rxPin,txPin);

void setup()
{
  pinMode(txPin,INPUT);
  pinMode(txPin,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

int number = 0;
void loop()
{
  //mySerial.listen();
  mySerial.print("The number is The number is");
  mySerial.println(number);
  Serial.print("The number is");
  Serial.println(number);

  delay(500);
  number++;
  
}



