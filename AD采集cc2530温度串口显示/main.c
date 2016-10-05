/*****************************************************************************
*  项目名称  ： AD采集cc2530温度串口显示
*    作者    ： 郑朋桥
*    时间    ： 2016/08/06
******************************************************************************/


/*****************************************************************************
*  添加头文件
******************************************************************************/
#include <ioCC2530.h>
#include "INTUART.h"
#include <stdio.h>
#include <string.h>
#include "ADC.h"
#include "LED.h"
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

void main()
{
    float AvgTemp;
    char strTemp[7];
    setSystemCLK();
    initUart();
    ledInit();
    while(1)
    {
        
//TEMP的12位分辨率，参考电压为AVDD5
/*        AvgTemp = getChannalValue(TEMP,BIT12,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A12",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT10,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A10",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT9,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A09",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT7,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A07",3);
        sendNewLine();
        delayMS(3000);
        
        AvgTemp = getChannalValue(TEMP,BIT12,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A12",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT10,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A10",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT9,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A09",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT7,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A07",3);
        sendNewLine();
        delayMS(3000);
*/    
        AvgTemp = getChannalValue(AIN5,BIT12,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendNewLine();
        delayMS(100);
    }
}
