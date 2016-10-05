#ifndef __TIME1PWM_H_
#define __TIME1PWM_H_
#include "ioCC2530.h"  
  typedef enum PWM_TIME1_LOCALTION_t
  {
      PWM_1_LOCALTION,
      PWM_2_LOCALTION,
  }PWM_TIME1_LOCALTION;
  
  typedef enum PWM_TIME1_CHANNAL_t
  {
      PWM_TIME1_CHANNAL0,
      PWM_TIME1_CHANNAL1,
      PWM_TIME1_CHANNAL2,
      PWM_TIME1_CHANNAL3,
      PWM_TIME1_CHANNAL4,
      
  }PWM_TIME1_CHANNAL;
  
  
/****************************************************************************
* 名    称: initT1PWM()
* 功    能: 设置周期时间，计数器频率为250KHz
* 入口参数: 无
* 出口参数: 无
****************************************************************************/
extern void initT1PWM(unsigned char val);

/*****************************************************************************
*  函数名称  ： setTime1Priority
*  函数介绍  ：设置定时器1的优先级最高
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
extern void setTime1Priority();


/*****************************************************************************
*  函数名称  ： setPWMLocation
*  函数介绍  ：设置定时器1的输出引脚位置
*            ：
*    参数    ： localtion  ： 输出引脚的位置
*   返回值   ： 无
******************************************************************************/
extern void setPWMLocation(PWM_TIME1_LOCALTION localtion);


/*****************************************************************************
*  函数名称  ： setTime1PWMChannal
*  函数介绍  ：设置通道的值，并启动转换
*            ：
*    参数    ： time_channal：通道
*            ： val         ： 阈值
*   返回值   ： 无
******************************************************************************/
extern void setTime1PWMChannal(PWM_TIME1_CHANNAL time_channal,unsigned char val);


#endif