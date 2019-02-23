#ifndef oled_h
#define oled_h
#include"Arduino.h"

#define OLED_12864_Address 0x3c

class oled
{
 public:
  oled();
  void Picture(char x0, char y0, char x1, char y1, char BMP[]);     //显示图片
  void oled_clear();  //清屏
  void OLED_xy();     //光标位置
  void oled_init();   //初始化
  void fill_picture(unsigned char fill_Data);     //全屏填充
 private:
  void Write_IIC_Data(unsigned char IIC_Data);          //写数据
  void Write_IIC_Command(unsigned char IIC_Command);    //写指令
  
  

  
};
#endif()
