#include "TIME1PWM.h"


/*****************************************************************************
*  函数名称  ： setPWMLocation
*  函数介绍  ：设置定时器1的输出引脚位置
*            ：
*    参数    ： localtion  ： 输出引脚的位置
*   返回值   ： 无
******************************************************************************/

void setPWMLocation(PWM_TIME1_LOCALTION localtion)
{
    switch(localtion)
    {
    case PWM_1_LOCALTION:
       PERCFG &= ~(1 << 6);    //定时器1 的IO位置   PWM_1_LOCALTION:备用位置1
    case PWM_2_LOCALTION:
       PERCFG |= (1 << 6);    //定时器1 的IO位置   PWM_2_LOCALTION:备用位置2 
    }
}



/*****************************************************************************
*  函数名称  ： setTime1Priority
*  函数介绍  ：设置定时器1的优先级最高
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/

void setTime1Priority()
{
    P2SEL &= ~0x10;          //定时器1优先
    P2DIR |= 0xC0;           //第1优先级：定时器1通道2-3
}

/****************************************************************************
* 名    称: initT1PWM()
* 功    能: 设置周期时间，计数器频率为250KHz
* 入口参数: 无
* 出口参数: 无
****************************************************************************/
void initT1PWM(unsigned char val)
{
    CLKCONCMD &= ~0x40;      //设置系统时钟源为32MHZ晶振
    while(CLKCONSTA & 0x40); //等待晶振稳定为32M
    CLKCONCMD &= ~0x07;      //设置系统主时钟频率为32MHZ   
    CLKCONCMD |= 0x38;       //时钟速度32 MHz 定时器标记输出设置[5:3]250kHz
    
    T1CC0H = 0x00;           
    T1CC0L = val;           //设置PWM周期  
      
    T1CTL = 0x02;            //250KHz 1分频
}


/*****************************************************************************
*  函数名称  ： setTime1PWMChannal
*  函数介绍  ：设置通道的值，并启动转换
*            ：
*    参数    ： time_channal：通道
*            ： val         ： 阈值
*   返回值   ： 无
******************************************************************************/

void setTime1PWMChannal(PWM_TIME1_CHANNAL time_channal,unsigned char val)
{
    switch(time_channal)
    {
    case PWM_TIME1_CHANNAL0:
      T1CC0H = 0x00;           
      T1CC0L = val;            //修改T1CC0L可调整占空比   
      T1CCTL0 = 0x1c;          // 模式选择 通道0比较模式
      break;
    case PWM_TIME1_CHANNAL1:
      T1CC1H = 0x00;         
      T1CC1L = val;            //修改T1CC2L可调整led的亮度    
      T1CCTL1 = 0x1c;          // 模式选择 通道1比较模式
      break;
    case PWM_TIME1_CHANNAL2:
      T1CC2H = 0x00;          
      T1CC2L = val;            //修改T1CC2L可调整led的亮度
      T1CCTL2 = 0x1c;          // 模式选择 通道2比较模式
      break;
    case PWM_TIME1_CHANNAL3:
      T1CC3H = 0x00;         
      T1CC3L = val;            //修改T1CC2L可调整led的亮度
      T1CCTL3 = 0x1c;          // 模式选择 通道3比较模式
      break;
    case PWM_TIME1_CHANNAL4:
      T1CC3H = 0x00;          
      T1CC3L = val;            //修改T1CC2L可调整led的亮度
      T1CCTL3 = 0x1c;          // 模式选择 通道4比较模式
      break;      
    }
}
