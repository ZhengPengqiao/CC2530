/*****************************************************************************
*  项目名称  ： 模拟PWM调光实验
*    作者    ： 郑朋桥
*    时间    ： 2016/08/10
******************************************************************************/

/*****************************************************************************
*  添加头文件
******************************************************************************/
#include "ioCC2530.h"
#include "LED.h"

void pwm1(unsigned int p,unsigned int a)
{
  unsigned int i;
  for(i = 0; i < a; i++)
  {
    if(i < p)
    {
      led1On();
    }
    else
    {
      led1Off();
    }
  }
}

void pwm2(unsigned int p,unsigned int a)
{
  unsigned int i;
  for(i = 0; i < a; i++)
  {
    if(i < p)
    {
      led2On();
    }
    else
    {
      led2Off();
    }
  }
}

void pwm3(unsigned int p,unsigned int a)
{
  unsigned int i;
  for(i = 0; i < a; i++)
  {
    if(i < p)
    {
      led3On();
    }
    else
    {
      led3Off();
    }
  }
}

void main()
{
  ledInit();
  int i,j;

  while(1)
  {
    
    for(i = 0,j = 0; i < 1000; i += j,j++)
    {
      pwm1(i,1000);
    }
    for(i = 1000,j = 0; i > 0; i -= j,j++)
    {
      pwm1(i,1000);
    }

    for(i = 0,j = 0; i < 1000; i += j,j++)
    {
      pwm2(i,1000);
    }
    for(i = 1000,j = 0; i > 0; i -= j,j++)
    {
      pwm2(i,1000);
    }
    
    for(i = 0,j = 0; i < 1000; i += j,j++)
    {
      pwm3(i,1000);
    }
    for(i = 1000,j = 0; i > 0; i -= j,j++)
    {
      pwm3(i,1000);
    }
    
  }
}

