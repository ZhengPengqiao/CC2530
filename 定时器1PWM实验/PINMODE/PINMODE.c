#include "PINMODE.h"
#define LED1 P1_0       // P1.0口控制LED1
#define LED2 P1_1       // P1.0口控制LED1



/*****************************************************************************
*  函数名称  ： pwmPinMode
*  函数介绍  ： 定会器1的输出引脚初始化，用于初始化PWM要输出的引脚
*            ：
*    参数    ： pinnum ： 引脚数
*   返回值   ： 无
******************************************************************************/

void pwmPinMode(PWM_PIN_NUM pinnum)
{
    switch(pinnum)
    {
    case PWM_P0_2:
      P0DIR |= (1 << 2);           //端口1为输出    
      P0SEL |= (1 << 2);           //timer1 通道2映射口P1_0
      break;
    case PWM_P0_3:
      P0DIR |= (1 << 3);           //端口1为输出    
      P0SEL |= (1 << 3);           //timer1 通道2映射口P1_0
      break;
    case PWM_P0_4:
      P0DIR |= (1 << 4);           //端口1为输出    
      P0SEL |= (1 << 4);           //timer1 通道2映射口P1_0
      break;
    case PWM_P0_5:
      P0DIR |= (1 << 5);           //端口1为输出    
      P0SEL |= (1 << 5);           //timer1 通道2映射口P1_0
      break;
    case PWM_P0_6:
      P0DIR |= (1 << 6);           //端口1为输出    
      P0SEL |= (1 << 6);           //timer1 通道2映射口P1_0
      break;
    case PWM_P0_7:
      P0DIR |= (1 << 7);           //端口1为输出    
      P0SEL |= (1 << 7);           //timer1 通道2映射口P1_0
      break;
    case PWM_P1_0:
      P1DIR |= (1 << 0);           //端口1为输出    
      P1SEL |= (1 << 0);           //timer1 通道2映射口P1_0
      break;
    case PWM_P1_1:
      P1DIR |= (1 << 1);           //端口1为输出    
      P1SEL |= (1 << 1);           //timer1 通道1映射口P1_1
      break;
    case PWM_P1_2:
      P1DIR |= (1 << 2);           //端口1为输出    
      P1SEL |= (1 << 2);           //timer1 通道1映射口P1_1
      break;
    }
  
    
}
