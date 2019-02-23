import java.awt.Dimension;
/*
*本程序将接管你的鼠标按“ESC”关闭运行程序
*
*/

import java.awt.AWTException;
import java.awt.Robot;
import processing.serial.*;
Serial myPort;
arduMouse myMouse;

public static final short LF = 10;
public static final short portIndex = 0;

int posX, posY, btn;

void setup()
{
 size(200,200);
 printArray(Serial.list());
 println("Constcting to ->" + Serial.list()[portIndex]);
 myPort = new Serial(this ,Serial.list()[portIndex],9600);
 myMouse = new arduMouse();
 btn = 0;
}

void draw()
{
 if( btn !=0)
   myMouse.move(posX,posY);
}
 
void serialEvent(Serial p)
{
  String message = myPort.readStringUntil(LF);
  if(message != null)
  {
   print(message);
   String[]data = message.split(",");
   if(data[0].equals("Data"))
   {
    if( data.length >3)
    {
     try
     {
      posX = Integer.parseInt(data[1]);
      posY = Integer.parseInt(data[2]);
      btn  = Integer.parseInt(data[3]);
     }
     catch(Throwable t)
     {
      println(".");
      println(message); 
     }
    }
   }
  } 
}

class arduMouse
{
 Robot myRobot;
 static final short rate = 4;
 int centerX, centerY;
 arduMouse()
 {
  try
  {
   myRobot = new Robot(); 
  }
  catch(AWTException e)
  {
   e.printStackTrace(); 
  }
  Dimension screen = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
  centerY = (int)screen.getHeight() / 2;
  centerX = (int)screen.getWidth() /2;
 }

   void move(int offsetX,int offsetY)
  {
    myRobot.mouseMove(centerX + (rate * offsetX),centerY - (rate * offsetY));
  }
}
