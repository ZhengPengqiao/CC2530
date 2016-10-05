/*****************************************************************************
*  文件介绍  ： 中断方式的计数器函数
*    作者    ： 郑朋桥
*    时间    ： 2016/08/04
******************************************************************************/

#include "INTTIME.h"
#if (TIME1 > 0)
/*****************************************************************************
*  函数介绍  ： 定时器初始化函数，根据time_clkdiv，time_mode，channal来设置分频，
*            ： 相应通道的模式，
*    参数    ： time_clkdiv  分频
*            ： time_mode    计数模式
*            ： channal      通道
*   返回值   ： 
******************************************************************************/
  void initTime1(ENUM_TIME1_CLKDIV time_clkdiv,ENUM_TIME1_MODE time_mode, \
    ENUM_TIME1_CHANNAL channal)
  {
    switch(time_clkdiv) 
    {
      case TIME1_CLOCK_DIV_1: 
         T1CTL |= (0 << 2);  //选择1分频值;
         break;
      case TIME1_CLOCK_DIV_8:
         T1CTL |= (1 << 2);  //选择8分频值;
         break;
      case TIME1_CLOCK_DIV_32:
         T1CTL |= (2 << 2);  //选择32分频值;
         break;
      case TIME1_CLOCK_DIV_128:
         T1CTL |= (3 << 2);  //选择128分频值;
         break;
    }
    
    switch(time_mode)
    {
      case TIME1_STOP:
        T1CTL |= (0 << 0);    //选择定时器1的模式，暂停运行
        break;
      case TIME1_FREERUNNING:
        T1CTL |= (1 << 0);    //选择定时器1的模式，自由运动
        break;
      case TIME1_MODULE:
        T1CTL |= (2 << 0);    //选择定时器1的模式，模模式
        T1CCTL0 |= (1 << 2);  //模模式只能使用0通道
        break;
      case TIME1_UP_DOWN:
        T1CTL |= (3 << 0);    //选择定时器1的模式，正计数/倒计数
        T1CCTL0 |= (1 << 2);  //正计数/负计数只能使用0通道
        break;
    }
      
            
        T1IE  =  1;         //定时器1中断使能
        EA = 1; 
      //寄存器状态寄存器 T1STAT 包括最终计数值事件和五个通道比较 / 捕获事件的中
      //断标志

  }
  

/*****************************************************************************
*  函数介绍  ： 设置T1CC的值
*            ：
*    参数    ： val，要设置的值
*   返回值   ： 无
******************************************************************************/
  void setT1CCxValue(unsigned short val, ENUM_TIME1_CHANNAL channal)
  {
      switch(channal)
      {
      case TIME1_CH_0:
        T1CC0L = ( val & 0xff);
        T1CC0H = ( val & 0xff00 )>>8;
        break;
      case TIME1_CH_1:
        T1CC1L = ( val & 0xff);
        T1CC1H = ( val & 0xff00 )>>8;
        break;
      case TIME1_CH_2:
        T1CC2L = ( val & 0xff);
        T1CC2H = ( val & 0xff00 )>>8;
        break;
      case TIME1_CH_3:
        T1CC3L = ( val & 0xff);
        T1CC3H = ( val & 0xff00 )>>8;
        break;
      case TIME1_CH_4:
        T1CC4L = ( val & 0xff);
        T1CC4H = ( val & 0xff00 )>>8;
        break;
      }
  }

  int time1ChannalValue(ENUM_TIME1_CHANNAL channal)
  {
      switch(channal)
      {
      case TIME1_CH_0:
        return ( T1STAT & (1 << 0) );
        break;
      case TIME1_CH_1:
        return ( T1STAT & (1 << 1) );
        break;
      case TIME1_CH_2:
        return ( T1STAT & (1 << 2) );
        break;
      case TIME1_CH_3:
        return ( T1STAT & (1 << 3) );
        break;
      case TIME1_CH_4:
        return ( T1STAT & (1 << 4) );
        break;
      case TIME1_CH_5:
        return ( T1STAT & (1 << 5) );
        break;
      }
      return -1;
       
  }

  
  void time1ChannalClear(ENUM_TIME1_CHANNAL channal)
  {
      switch(channal)
      {
      case TIME1_CH_0:
        T1STAT &= ~(1 << 0);
        break;
      case TIME1_CH_1:
        T1STAT &= ~(1 << 1);
        break;
      case TIME1_CH_2:
        T1STAT &= ~(1 << 2);
        break;
      case TIME1_CH_3:
        T1STAT &= ~(1 << 3);
        break;
      case TIME1_CH_4:
        T1STAT &= ~(1 << 4);
        break;
      }
  }

  int time1Value()
  {
      return time1ChannalValue(TIME1_CH_5);
  }

  void time1Clear()
  { 
      time1ChannalClear(TIME1_CH_5);
  }

    int (*T1_function)();
   
    void setINTTime1Fun(int (*inT1_function)())
   {
     T1_function = inT1_function;
   }
  
    #pragma vector = T1_VECTOR
    __interrupt void T1_ISR(void)
    {
      if(T1_function != 0)
      {
        T1_function();
      }
      T1IF = 0x00;
    }
#endif


#if (TIME3 > 0)
  void initTime3(ENUM_TIME3A4_CLKDIV time_clkdiv,ENUM_TIME3A4_MODE time_mode, \
      ENUM_TIME3A4_CHANNAL channal)
  {
      T3CTL |= (1 << 3);  //开溢出中断
      switch(time_clkdiv)
      {
      case  TIME3A4_CLOCK_DIV_1:
        T3CTL |= (0 << 5);  //1分频
        break;
      case  TIME3A4_CLOCK_DIV_2:
        T3CTL |= (1 << 5);  //2分频
        break;
      case  TIME3A4_CLOCK_DIV_4:
        T3CTL |= (2 << 5);  //4分频
        break;
      case  TIME3A4_CLOCK_DIV_8:
        T3CTL |= (3 << 5);  //8分频
        break;
      case  TIME3A4_CLOCK_DIV_16:
        T3CTL |= (4 << 5);  //16分频
        break;
      case  TIME3A4_CLOCK_DIV_32:
        T3CTL |= (5 << 5);  //32分频
        break;
      case  TIME3A4_CLOCK_DIV_64:
        T3CTL |= (6 << 5);  //64分频
        break;
      case  TIME3A4_CLOCK_DIV_128:
        T3CTL |= (7 << 5);  //128分频
        break;
      }
      
      switch(time_mode)
      {
       case  TIME3A4_FREERUNNING:     //自动装载
         T3CTL &= ~(3 << 0);
         T3CTL |= (0 << 0); 
        break;
      case  TIME3A4_DOWNMODE:        //倒计数
         T3CTL &= ~(3 << 0);
         T3CTL |= (1 << 0); 
         T3CCTL0 |= (1 << 2);    //定时器4通道0的比较模式
        break;
      case  TIME3A4_MODULE:          //模模式
         T3CTL &= ~(3 << 0);
         T3CTL |= (2 << 0);
         T3CCTL0 |= (1 << 2);    //定时器4通道0的比较模式
        break; 
      case  TIME3A4_UP_DOWN:
        T3CTL &= ~(3 << 0);
         T3CTL |= (3 << 0);     //正计数/负计数
         T3CCTL0 |= (1 << 2);    //定时器4通道0的比较模式
        break;
      
      }
      
        T3IE  =  1;         //定时器1中断使能
        T3CTL |= (1 << 4);  //启动
        EA = 1;             //开启中断
  }

   void setT3CCxValue(unsigned char val, ENUM_TIME3A4_CHANNAL channal)
   {
     switch(channal)
     {
     case TIME3A4_CH_0:
       T3CC0 = val;
       break;
     case TIME3A4_CH_1:
       T3CC1 = val;
       break;
     }
   }

    int (*T3_function)();
   
    void setINTTime3Fun(int (*inT3_function)())
   {
     T3_function = inT3_function;
   }
  
    #pragma vector = T3_VECTOR
    __interrupt void T3_ISR(void)
    {
      if(T3_function != 0)
      {
        T3_function();
      }
      T3IF = 0x00;
    }

#endif


#if (TIME4> 0)
  void initTime4(ENUM_TIME3A4_CLKDIV time_clkdiv,ENUM_TIME3A4_MODE time_mode, \
      ENUM_TIME3A4_CHANNAL channal)
  {
      T4CTL |= (1 << 3);  //开溢出中断
      switch(time_clkdiv)
      {
      case TIME3A4_CLOCK_DIV_1:
        T4CTL |= (0 << 5);  //1分频
        break;
      case TIME3A4_CLOCK_DIV_2:
        T4CTL |= (1 << 5);  //2分频
        break;
      case TIME3A4_CLOCK_DIV_4:
        T4CTL |= (2 << 5);  //4分频
        break;
      case TIME3A4_CLOCK_DIV_8:
        T4CTL |= (3 << 5);  //8分频
        break;
      case TIME3A4_CLOCK_DIV_16:
        T4CTL |= (4 << 5);  //16分频
        break;
      case TIME3A4_CLOCK_DIV_32:
        T4CTL |= (5 << 5);  //32分频
        break;
      case TIME3A4_CLOCK_DIV_64:
        T4CTL |= (6 << 5);  //64分频
        break;
      case TIME3A4_CLOCK_DIV_128:
        T4CTL |= (7 << 5);  //128分频
        break;
      }
      
      switch(time_mode)
      {
      case TIME3A4_FREERUNNING:     //自动装载
         T4CTL &= ~(3 << 0);
         T4CTL |= (0 << 0); 
        break;
      case TIME3A4_DOWNMODE:        //倒计数
         T4CTL &= ~(3 << 0);
         T4CTL |= (1 << 0); 
        break;
      case TIME3A4_MODULE:          //模模式
         T4CTL &= ~(3 << 0);
         T4CTL |= (2 << 0);
         T4CCTL0 |= (1 << 2);    //定时器4通道0的比较模式
        break; 
      case TIME3A4_UP_DOWN:
        T4CTL &= ~(3 << 0);
         T4CTL |= (3 << 0);     //正计数/负计数
         T4CCTL0 |= (1 << 2);    //定时器4通道0的比较模式
        break;
      }
      T4IE  =  1;         //定时器1中断使能
      T4CTL |= (1 << 4);  //启动
      EA = 1;             //开启中断
  }

   void setT4CCxValue(unsigned char val, ENUM_TIME3A4_CHANNAL channal)
   {
     switch(channal)
     {
     case TIME3A4_CH_0:
       T4CC0 = val;
       break;
     case TIME3A4_CH_1:
       T4CC1 = val;
       break;
     }
   }
   

   int (*T4_function)();
   
   void setINTTime4Fun(int (*inT4_function)())
   {
     T4_function = inT4_function;
   }
  
    #pragma vector = T4_VECTOR
    __interrupt void T4_ISR(void)
    {
      T4_function();
      T4IF = 0x00;
    }

#endif

