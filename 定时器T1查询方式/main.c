/*****************************************************************************
*  项目名称  ： 定时器T1查询方式
*    作者    ： 郑朋桥
*    时间    ： 2016/08/02
******************************************************************************/
#include <ioCC2530.h>
#include "LED.h"
#include "CHECKTIME.h"

/*****************************************************************************
*  函数介绍  ： 不精确延时函数
*            ： 
*    参数    ： 毫秒数
*   返回值   ： 无
******************************************************************************/
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
  unsigned int count1 = 0;
  int ledstatus1 = 0;
  unsigned int count2 = 0;
  int ledstatus2 = 0;
  ledInit();  

  initTime1(TIME1_CLOCK_DIV_128,TIME1_MODULE,TIME1_CH_0);
  setT1CCxValue(25,TIME1_CH_0);
  initTime4(TIME3A4_CLOCK_DIV_128,TIME3A4_MODULE,TIME3A4_CH_0);
  setT4CCxValue(250,TIME3A4_CH_0);
  while(1) 
  {
    if( time1ChannalValue(TIME1_CH_0) )   
    {
      count1++ ;
      if(count1 > 100)
      {
        count1 = 0;
        ledstatus1 = ~ledstatus1;
      }
      time1ChannalClear(TIME1_CH_0);
    }
    
    if( time4ChannalValue(TIME3A4_CH_0) )   
    {
      count2++ ;
      if(count2 > 100)
      {
        count2 = 0;
        ledstatus2 = ~ledstatus2;
      }
      time4ChannalClear(TIME3A4_CH_0);
    }
    
    
    if(ledstatus2)
    {
      led2On();
    }
    else
    {
      led2Off();
    }
    
    
    if(ledstatus1)
    {
      led1On();
    }
    else
    {
      led1Off();
    }
    
  }
}

