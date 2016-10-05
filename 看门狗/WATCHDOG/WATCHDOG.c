#include "WATCHDOG.h"

void (*WDT_fun)(void);
/*****************************************************************************
*  函数名称  ： void initWatchdog(ENUM_WATCHDOG_INTERVAL，ENUM_WATCHDOG_MODE)
*  函数介绍  ： 根据eatchdogInterval，watchdogMode初始化看门狗
*            ：
*    参数    ： watchdogMode  ： 看门狗模式
*            ： eatchdogInterval ： 看门狗时间间隔
*   返回值   ： 无
******************************************************************************/
void initWatchdog(ENUM_WATCHDOG_INTERVAL eatchdogInterval,\
  ENUM_WATCHDOG_MODE watchdogMode)
{
  WDCTL = 0x00;   //启动IDLE才能设置看门狗
  WDT_fun = 0;
  switch(eatchdogInterval)
  {
  case WATCHDOG_INTERVAL_1s:
    WDCTL |= (0 << 0);  //设置时间间隔
    break;
  case WATCHDOG_INTERVAL_0_25s:
    WDCTL |= (1 << 0);  //设置时间间隔
    break;
  case WATCHDOG_INTERVAL_15_625ms:
    WDCTL |= (2 << 0);  //设置时间间隔
    break;
  case WATCHDOG_INTERVAL_1_9ms:
    WDCTL |= (3 << 0);  //设置时间间隔
    break;
  }
  
  switch(watchdogMode)
  {
  case WATCHDOG_MODE_IDEL:
    WDCTL |= (0 << 2);  //模式选为空闲模式
    break;
  case WATCHDOG_MODE_WATCHDOGMODE:
    WDCTL |= (2 << 2);  //模式选为看门狗
    break;
  case WATCHDOG_MODE_TIMERMODE:
    IEN2 |= (1 << 5);  //使能定时器中断
    WDTIF = 0;  //清楚中断标志位
    EA = 1;
    WDCTL |= (3 << 2);  //模式选为定时器模式
    break;
  }

}

#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR(void)
{
  if( WDT_fun != 0)
  {
      WDT_fun();
  }
   WDTIF = 0;  //清楚中断标志位
}

void setWDTFun(void (*inWDT_fun)(void))
{
  WDT_fun = inWDT_fun;
}


void feetdog(void)
{
  WDCTL = 0xa0;    //清楚定时器，当0xA跟随0x5写到这些位，定时器被清楚
  WDCTL = 0x50;
}
