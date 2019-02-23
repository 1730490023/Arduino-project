
import processing.serial.*;

PrintWriter output;
//DateFormat fnameFormat = new SimpleDateFormat("yyMMdd_HHmm");
//DateFormat timeFormat  = new SimpleDateFormat("hh:mm:ss");
String fileName;

Serial myPort;
short portIndex = 0;
char HEADER = 'H';

void setup()
{
 size(200,200);
 
 String portName = Serial.list()[portIndex];
 printArray(Serial.list());
 println("Connecting to ->" + Serial.list()[portIndex]);
 myPort = new Serial(this ,portName,9600);
 //Data now = new Date();
 //fileName = fnameFormat.format(now);
 output = createWriter(fileName + ".txt");  //在程序文件夹保存文件
}

void draw()
{
  int val;
  String time;
  
  if(myPort.available() >= 15)      //等待整个消息到达
  {
   if( myPort.read() == HEADER)    //信头
   {
    //String timeString = timeFormat.format(new Date());
   // println("Message received at" + timeString);
   // output.println(timeString);
    
    val = readArduinoInt();     //打印每一位值
    
    for(int pin=2,bit=1;pin <= 13;pin++)
    {
     print("digital pin" + pin + "=");
     output.print("digital pin" + pin + "=");
     int isSet = (val & bit);
     if(isSet ==0)
     {
       println("0");
       output.println("0");
     }
     else
     {
      println("1");
      output.println("0");
     }
     bit = bit * 2;      //移位
    }
    for(int i=0;i<6;i++)    //打印6个模拟值
    {
     val = readArduinoInt();
     println("analog port"+ i + "=" + val);
     output.println("analog port" + i + "=" + val);
    }
    println("------");
    output.println("-------");
   }
  }
}

void keyPressed()
{
 output.println();    //将剩余的数据写入文件
 output.close();      //完成文件
 exit();             //停止程序
}

//根据串口接收到的字节返回整型值
int readArduinoInt()
{
 int val;            //从串口接收到的数据
 val = myPort.read();   //读取最小显著性字节
 val = myPort.read() * 256 + val; //加上最大显著性字节
 return val;
}
