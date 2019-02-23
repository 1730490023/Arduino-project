/*
 * 显示心脏跳动
 */

 int  bigHeart[] = { 
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000};
int  smallHeart[] ={
  B00000000,
  B00000000,
  B00010100,
  B00111110,
  B00111110,
  B00011100,
  B00001000,
  B00000000};

const int columnPins[] = {2,3,4,5,6,7,8,9};
const int rowPins[] = {10,11,12,15,16,17,18,19};

void setup()
{
  for(int i = 0;i<8;i++)
  {
    pinMode(rowPins[i],OUTPUT);
    pinMode(columnPins[i],OUTPUT);
    digitalWrite(columnPins[i],HIGH);
  }
}

void loop()
{
  int pulseDelay = 800;
  show(smallHeart,80);
  show(bigHeart,160);
  delay(pulseDelay);
}

void show(int *image, unsigned long duration)
{
  unsigned long start = millis();
  while(start + duration > millis())
  {
    for(int row = 0 ; row < 8; row++)
    {
      digitalWrite(rowPins[row],HIGH);
      for(int column = 0;column<8; column++)
      {
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1)
        {
          digitalWrite(columnPins[column],  LOW);
        }
        delayMicroseconds(300);
        digitalWrite(columnPins[column],HIGH);
      }
      digitalWrite(rowPins[row],LOW);
    }
  }
}

