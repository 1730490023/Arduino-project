/*
 * 
 */ 
const int redPin = 3;         //为每个led选引脚             
const int greenPin = 5;
const int bluePin = 6;
const boolean invert = true;  //如果共阳极设置为true，共阴极则返回false  

int color = 0;         //从0到255 表示色调的 值
int R,G,B;        //红，绿，蓝 颜色分量
 
 void setup()  //引脚有analogWrite驱动，不需要声明引脚
 {
    
                 
 }

 void loop()
 { 
   int brightness = 255;        //255是最大亮度
   hueToRGB(color, brightness); //调用函数色调转换为RGB
   //把RGB值写到引脚
   analogWrite(redPin ,R);
   analogWrite(greenPin,G);
   analogWrite(bluePin ,B);
   
   color++;   //颜色递增
   if(color>255)
   {
    color = 0;
   }
   delay(10);
 }
//把颜色转换为它的红，绿，蓝分量函数
void hueToRGB( int hue ,int brightness)
{
   unsigned int scaledHue = (hue * 6);
   //沿着色轮的0到5区
   unsigned int segment  = scaledHue / 256;
   //区内位置
   unsigned int segmentOffset = scaledHue - (segment * 256);
   unsigned int complement = 0;
   unsigned int prev = (brightness * (255 - segmentOffset)) / 256;
   unsigned int next = (brightness * (segmentOffset)) / 265;
   if(invert)
   {
     brightness = 255-brightness;
     complement = 255;
     prev = 255-prev;
     next = 255-next;
   }

   switch(segment)
   {
     case 0:       //红
     R = brightness;
     G = next;
     B = complement;
     break;
     case 1:    //黄
     R = prev;
     G = brightness;
     B = complement;
     break;
     case 2:   // 绿
     R = complement;
     G = brightness;
     B = next ;
     break;
     case 3:  //青
     R = complement;
     G = prev;
     B = brightness;
     break;
     case 4:   //蓝
     R = next ;
     G = complement;
     B = brightness;
     break;
     case 5:   //杨红
     default:
     R = brightness;
     G = complement;
     B = prev;
     break;
   }
}



