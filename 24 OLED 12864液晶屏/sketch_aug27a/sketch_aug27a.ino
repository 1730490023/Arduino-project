/*
 *  oled 12864 显示中英文
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define LOGO16_GLCD_HEIGHT 16 //定义显示高度
#define LOGO16_GLCD_WIDTH  16 //定义显示宽度

static const unsigned char PROGMEM zhi[] =
{ 
  0x20,0x00,0x3E,0x7C,0x48,0x44,0x08,0x44,0xFF,0x44,0x14,0x44,0x22,0x7C,0x40,0x00,
  0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10
};

static const unsigned char PROGMEM neng[] =
{ 
   0x10,0x40,0x24,0x44,0x42,0x48,0xFF,0x70,0x01,0x40,0x00,0x42,0x7E,0x42,0x42,0x3E,
   0x42,0x00,0x7E,0x44,0x42,0x48,0x42,0x70,0x7E,0x40,0x42,0x42,0x4A,0x42,0x44,0x3E
};
static const unsigned char PROGMEM chu[] =
{ 
  0x20,0x00,0x27,0xFE,0x24,0x00,0x24,0x04,0xF7,0xE4,0x24,0x04,0x25,0xDE,0x75,0x44,
  0x6D,0x44,0xA5,0xD4,0xA4,0x0C,0x25,0x44,0x24,0x84,0x24,0xE4,0x2B,0x14,0x20,0x08
};
static const unsigned char PROGMEM gui[] =
{ 
  0x10,0x00,0x11,0xFE,0x11,0x00,0x11,0x00,0xFD,0x00,0x11,0xFC,0x31,0x04,0x39,0x04,
  0x55,0x04,0x55,0x04,0x91,0xFC,0x11,0x00,0x11,0x00,0x11,0x00,0x11,0xFE,0x10,0x00
};
static const unsigned char PROGMEM guan[] =
{ 
  0x20,0x40,0x3F,0x7E,0x48,0x90,0x85,0x08,0x01,0x00,0x7F,0xFE,0x40,0x02,0x9F,0xE4,
  0x10,0x20,0x1F,0xE0,0x10,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10
};
static const unsigned char PROGMEM jia[] =
{ 
  0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x80,0x04,0x7F,0xFC,0x02,0x00,0x0D,0x08,
  0x71,0x90,0x02,0xA0,0x0C,0xC0,0x71,0xA0,0x06,0x98,0x18,0x86,0xE2,0x80,0x01,0x00
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
void setup()   {                
  Serial.begin(9600);
 
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  display.clearDisplay();
 
  //英文字符显示
  display.setTextSize(1);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体颜色白色
  display.setCursor(0,0);             //设置字体的起始位置
  display.println("Hello, world!");   //输出字符并换行
  
  display.setTextColor(BLACK, WHITE); //设置字体黑色，字体背景白色 
  display.println(3.141592);          //输出数字并换行
  
  display.setTextSize(2);             //设置字体大小
  display.setTextColor(WHITE);        //设置字体白色
  display.print("0x");                //输出字符
  display.println(0xDEADBEEF, HEX);   //输出为ASCII编码的十六进制
  //display.display();                  //显示以上
  
  //中文字符显示
  display.drawBitmap(26, 32, zhi, 16, 16, 1); //在坐标X:26  Y:16的位置显示中文字符凌
  display.drawBitmap(42, 32, neng, 16, 16, 1); //在坐标X:42  Y:16的位置显示中文字符顺
  display.drawBitmap(58, 32, chu, 16, 16, 1);
  display.drawBitmap(74, 32, gui, 16, 16, 1);
  display.drawBitmap(90, 32, guan, 16, 16, 1);
  display.drawBitmap(106, 32, jia, 16, 16, 1);
  display.display();                  //把缓存的都显示
}
 
void loop() {
 
}


