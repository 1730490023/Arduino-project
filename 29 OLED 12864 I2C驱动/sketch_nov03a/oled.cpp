#include"oled.h"
#include"Wire.h"
#include"Arduino.h"

oled::oled()
{
  
}

/**********************************************
// IIC Write Command   写指令
**********************************************/
void oled::Write_IIC_Command(unsigned char IIC_Command)
{
   Wire.beginTransmission(byte(OLED_12864_Address));  //开始向地址写入
   Wire.write(byte(0x00));      //write command
   Wire.write(byte(IIC_Command)); 
   Wire.endTransmission();            //停止写入
}
/**********************************************
// IIC Write Data    写数据
**********************************************/
void oled::Write_IIC_Data(unsigned char IIC_Data)
{
   Wire.beginTransmission(byte(OLED_12864_Address));  //开始向地址写入
   Wire.write(byte(0x40));      //write data
   Wire.write(byte(IIC_Data)); 
   Wire.endTransmission();            //停止写入
}
/********************************************
// fill_Picture     全屏显示
********************************************/
void oled::fill_picture(unsigned char fill_Data)
{
  unsigned char m,n;
  for(m=0;m<8;m++)
  {
    Write_IIC_Command(0xb0+m);  //page0-page1
    Write_IIC_Command(0x00);    //low column start address
    Write_IIC_Command(0x10);    //high column start address
    for(n=0;n<128;n++)
      {
        Write_IIC_Data(fill_Data);
      }
  }
}
/******************************************
// picture用来显示一个图片
******************************************/
void oled::Picture(char *bmp[])
{
  unsigned char x,y;
  unsigned int i=0;
  for(y=0;y<8;y++)
    {
      Write_IIC_Command(0xb0+y);
      Write_IIC_Command(0x00);
      Write_IIC_Command(0x10);
      for(x=0;x<128;x++)
        {
          Write_IIC_Data(bmp[i++]);
        }
    }
}
/********************************************
//清屏
********************************************/
void oled::oled_clear(void)//清屏
{
    fill_picture(0x00);
}

 /********************************
  * @brief     设置光标位置
  * @param     x,光标x位置
  *            y，光标y位置
  *********************************/
void oled::OLED_xy(unsigned char x, unsigned char y) //设置起始点坐标
{ 
    Write_IIC_Command(0xb0+y);
    Write_IIC_Command(((x&0xf0)>>4)|0x10);
    Write_IIC_Command((x&0x0f)|0x01);
}


/************************************
 * oled 初始化 
 *************************************/
void oled::oled_init()   //OLED 初始化
{
  Write_IIC_Command(0xAE);   //display off
  Write_IIC_Command(0x20);  //Set Memory Addressing Mode  
  Write_IIC_Command(0x10);  //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
  Write_IIC_Command(0xb0);  //Set Page Start Address for Page Addressing Mode,0-7
  Write_IIC_Command(0xc8);  //Set COM Output Scan Direction
  Write_IIC_Command(0x00);//---set low column address
  Write_IIC_Command(0x10);//---set high column address
  Write_IIC_Command(0x40);//--set start line address
  Write_IIC_Command(0x81);//--set contrast control register
  Write_IIC_Command(0x7f);
  Write_IIC_Command(0xa1);//--set segment re-map 0 to 127
  Write_IIC_Command(0xa6);//--set normal display
  Write_IIC_Command(0xa8);//--set multiplex ratio(1 to 64)
  Write_IIC_Command(0x3F);//
  Write_IIC_Command(0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
  Write_IIC_Command(0xd3);//-set display offset
  Write_IIC_Command(0x00);//-not offset
  Write_IIC_Command(0xd5);//--set display clock divide ratio/oscillator frequency
  Write_IIC_Command(0xf0);//--set divide ratio
  Write_IIC_Command(0xd9);//--set pre-charge period
  Write_IIC_Command(0x22); //
  Write_IIC_Command(0xda);//--set com pins hardware configuration
  Write_IIC_Command(0x12);
  Write_IIC_Command(0xdb);//--set vcomh
  Write_IIC_Command(0x20);//0x20,0.77xVcc
  Write_IIC_Command(0x8d);//--set DC-DC enable
  Write_IIC_Command(0x14);//
  Write_IIC_Command(0xaf);//--turn on oled panel 
}


