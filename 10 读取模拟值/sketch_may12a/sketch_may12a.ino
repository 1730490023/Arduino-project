void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
}

void BT()
{
  Serial.println(analogRead(2));
  delay(1000);
}

void loop()
{
  BT();
}


