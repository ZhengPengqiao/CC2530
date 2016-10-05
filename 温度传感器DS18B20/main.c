/****************************************************************************
* 文 件 名: main.c
* 作    者: Andy
* 修    订: 2013-01-08
* 版    本: 1.0
* 描    述: 设置串口调试助手波特率：115200bps 8N1
*           DS18B20采集的温度通过串口传给电脑显示
****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "DS18B20.h"  
#include "INTUART.h"


/*****************************************************************************
*函数含义：不精确延迟函数
*函数参数：延迟毫秒数
*  返回值：无返回值
*****************************************************************************/
void delayMS(int ms)
{
  int i,j;
  for(i = 0; i < ms; i++)
  {
    for(j = 0; j < 535; j++);
  }
}


/****************************************************************************
* 程序入口函数
****************************************************************************/
void main()
{
    char strTemp[6];
    unsigned char ucTemp;
    float fTemp;

    
    setSystemCLK();                      //设置系统时钟源
    initUart();                     //串口初始化
    P0SEL &= 0x7f;                  //DS18B20的io口初始化
    
    while(1)
    {        
        memset(strTemp, 0, sizeof(strTemp)); 
        sendString("TEMPF:", 6);           //输出提示信息

        fTemp = floatReadDs18B20();       //温度读取函数 带1位小数位
        sprintf(strTemp, "%.01f", fTemp); //将浮点数转成字符串  
        sendString(strTemp,4);       //通过串口发送温度值到电脑显示
        sendString("'C",2);
        sendNewLine();       
        delayMS(1000);                   //延时函数使用定时器方式
       
        memset(strTemp, 0, sizeof(strTemp)); 
        sendString("TEMPI:", 6);           //输出提示信息
        ucTemp = ReadDs18B20();           //温度读取函数
        strTemp[0] = ucTemp/10+48;        //取出十位数
        strTemp[1] = ucTemp%10+48;        //取出个位数
        sendString(strTemp,2);       //通过串口发送温度值到电脑显示
        sendString("'C",2);       
        sendNewLine();
        delayMS(1000);                   //延时函数使用定时器方式
    }
}