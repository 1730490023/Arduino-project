/*
    MPU6050三轴陀螺仪和加速计。俯仰和偏航陀螺仪的例子。
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-zyroskop-i-akcelerometr-mpu6050.html
    GIT: https://github.com/jarzebski/Arduino-MPU6050
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <MPU6050.h>
#include <avr/wdt.h>


MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

//俯仰、滚动和偏航值
float pitch = 0;
float roll = 0;
float yaw = 0;

void setup() 
{
  Serial.begin(115200);
  wdt_enable(WDTO_2S);
  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  
  //调整陀螺仪。校准必须是静止的。
  // 如果你不想校准，请评论这条线。
  mpu.calibrateGyro();

   //Set threshold sensivty. Default 3.
  //如果你不想使用阈值，请评论这一行或设置0。
  mpu.setThreshold(3);
}

void loop()
{
  timer = millis();

  // 读归一化值
  Vector norm = mpu.readNormalizeGyro();

  // 计算俯仰，滚动和偏航
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;

  // Output raw
  Serial.print(" Pitch = ");
  Serial.print(pitch);      
  Serial.print(" Roll = ");
  Serial.print(roll);      
  Serial.print(" Yaw = ");
  Serial.println(yaw);

  // 等待全时阶段
  delay((timeStep*1000) - (millis() - timer));
}
