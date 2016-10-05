#ifndef __PINMODE_H_
#define __PINMODE_H_
#include "ioCC2530.h"
    typedef enum PWM_PIN_NUM_t
    {
      PWM_P0_2,
      PWM_P0_3,
      PWM_P0_4,
      PWM_P0_5,
      PWM_P0_6,
      PWM_P0_7,
      PWM_P1_0,
      PWM_P1_1,
      PWM_P1_2,
   }PWM_PIN_NUM;


/*****************************************************************************
*  函数名称  ： pwmPinMode
*  函数介绍  ： 定会器1的输出引脚初始化，用于初始化PWM要输出的引脚
*            ：
*    参数    ： pinnum ： 引脚数
*   返回值   ： 无
******************************************************************************/
    extern void pwmPinMode(PWM_PIN_NUM pinnum);
#endif