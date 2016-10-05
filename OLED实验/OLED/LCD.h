#ifndef __LCD_H_
#define __LCD_H_

#include <ioCC2530.h>

#define LCD_SCL P1_2       //SCLK  时钟 D0（SCLK）
#define LCD_SDA P1_3       //SDA   D1（MOSI） 数据
#define LCD_RST P1_7       //_RES  hardware reset   复位 
#define LCD_DC  P0_0       //A0  H/L 命令数据选通端，H：数据，L:命令

#define XLevelL        0x00
#define XLevelH        0x10
#define XLevel         ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column     128
#define Max_Row        64
#define Brightness     0xCF 
#define X_WIDTH        128
#define Y_WIDTH        64

    extern void LCD_WrDat(unsigned char dat);
    extern void LCD_WrCmd(unsigned char cmd);
    extern void LCD_Set_Pos(unsigned char x, unsigned char y);
    extern void LCD_Fill(unsigned char bmp_dat);
    extern void LCD_CLS(void);
    extern void LCD_Init(void);
    extern void LCD_P6x8Str(unsigned char x, unsigned char y,unsigned char ch[]);
    extern void LCD_P8x16Str(unsigned char x, unsigned char y,unsigned char ch[]);
    extern void LCD_P16x16Ch(unsigned char x, unsigned char y, unsigned char N);
    extern void Draw_BMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
    extern void test8x16();
#endif
