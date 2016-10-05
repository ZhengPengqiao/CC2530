设置系统模式
extern void sysPowerMode(ENUM_SYSPOWER mode);
初始化系统睡眠时钟
extern void initSleepTimer();
设置睡眠时间
extern void SetSTPeriod(unsigned int sec);


/*****************************************************************************
*  函数介绍  ： 设置唤醒中断的时除了清除中断外和唤醒事件的格外事件
*            ：
*    参数    ： 函数指针
*   返回值   ： 无
******************************************************************************/

void setStIsrFun(void (*ST_ISR_Fum)(void))
{
  ST_ISR_Fum = ST_ISR_Fum;
}


睡眠定时器是一个24位的定时器，运行在一个32KHz的时钟频率（可以从RCOSC或者XOSC）上。
定时器在复位之后即启动，如果没有中断就继续运行。定时器的当前值可以从sfr寄存器ST2
:ST1:ST0中读取