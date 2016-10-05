#include "SYSPOWER.h"

void sysPowerMode(ENUM_SYSPOWER mode)
{
  if( mode > 0 && mode < 4 )
  {
    SLEEPCMD |= mode;
    PCON = 0x01;
  }
  else
  {
    PCON = 0x00;
  }
}

void (*ST_ISR_Fum)(void);


/*****************************************************************************
*  函数介绍  ： 设置唤醒中断的时除了清除中断外的格外事件
*            ：
*    参数    ： 函数指针
*   返回值   ： 无
******************************************************************************/
void setStIsrFun(void (*ST_ISR_Fum)(void))
{
  ST_ISR_Fum = ST_ISR_Fum;
}

#pragma vector = ST_VECTOR
__interrupt void ST_ISR(void)
{
  STIF = 0;
  if(ST_ISR_Fum != 0)
  {
    ST_ISR_Fum();
  }
  sysPowerMode(ACTICE_IDLE);
}

void initSleepTimer()
{
  ST_ISR_Fum = 0;
  ST2 = 0x00;
  ST1 = 0x00;
  ST0 = 0x00;
  EA = 1;
  STIE = 1;
  STIF = 0;
}

void Set_ST_Period(unsigned int sec)
{
  unsigned long sleepTimer = 0;
  
  sleepTimer |= (unsigned long)ST0;
  sleepTimer |= (unsigned long)ST1 << 8;
  sleepTimer |= (unsigned long)ST2 << 16;
  sleepTimer += ((unsigned long)sec * (unsigned long)32768);
  ST2 = (unsigned char)(sleepTimer >> 16);
  ST1 = (unsigned char)(sleepTimer >> 8);
  ST0 = (unsigned char)sleepTimer;
}
