const int nbrleds = 6;
const int ledPins[] = {2,3,4,5,6,7};
const int wait = 30;
void setup()
{
  for(int led = 0;led < nbrleds;led++)
  {
    pinMode(ledPins[led],OUTPUT);
  }
}

void loop()
{
  for(int led = 0;led <nbrleds-1;led++)
  {
    digitalWrite(ledPins[led],LOW);
    delay(wait);
    digitalWrite(ledPins[led + 1],LOW);
    delay(wait);
    digitalWrite(ledPins[led + 2],LOW);
    delay(wait);
    digitalWrite(ledPins[led],HIGH);
    delay(wait*2);
  }
  /*
  for(int led = nbrleds-1;led >0 ;led--)
  {
    digitalWrite(ledPins[led],LOW);
    delay(wait);
    digitalWrite(ledPins[led - 1],LOW);
    delay(wait);
    digitalWrite(ledPins[led - 2],LOW);
    delay(wait);
    digitalWrite(ledPins[led],HIGH);
    delay(wait*2);
  }*/
}

