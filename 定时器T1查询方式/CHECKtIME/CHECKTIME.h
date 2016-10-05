/*****************************************************************************
*  文件介绍  ： 查询方式的计数器函数头文件
*    作者    ： 郑朋桥
*    时间    ： 2016/08/02
******************************************************************************/

#ifndef __CHECKTIME_H_
#define __CHECKTIME_H_

  #define TIME1 1
  #define TIME3 1
  #define TIME4 1


  #include "ioCC2530.h"
  #if (TIME1 > 0)
    typedef enum ENUM_TIME1_CLKDIV_t{
      TIME1_CLOCK_DIV_1,
      TIME1_CLOCK_DIV_8,
      TIME1_CLOCK_DIV_32,
      TIME1_CLOCK_DIV_128
    }ENUM_TIME1_CLKDIV;
    typedef enum ENUM_TIME1_MODE_t{
      TIME1_STOP,
      TIME1_FREERUNNING,
      TIME1_MODULE,
      TIME1_UP_DOWN
    }ENUM_TIME1_MODE;
    
        
    typedef enum ENUM_TIME1_CHANNAL_t{
      TIME1_CH_0,
      TIME1_CH_1,
      TIME1_CH_2,
      TIME1_CH_3,
      TIME1_CH_4,
      TIME1_CH_5
    }ENUM_TIME1_CHANNAL;
    
    
    extern void setT1CCxValue(unsigned short val, ENUM_TIME1_CHANNAL channal);
    extern void initTime1(ENUM_TIME1_CLKDIV time_clkdiv,ENUM_TIME1_MODE time_mode, \
      ENUM_TIME1_CHANNAL channal);
    extern int time1Value();
    extern int time1ChannalValue(ENUM_TIME1_CHANNAL channal);
    extern void time1Clear();
    extern void time1ChannalClear(ENUM_TIME1_CHANNAL channal);
  #endif
  
  
    
  #if ( (TIME3 > 0) || (TIME4 > 0))
    typedef enum ENUM_TIME3A4_CLKDIV_t{
      TIME3A4_CLOCK_DIV_1,
      TIME3A4_CLOCK_DIV_2,
      TIME3A4_CLOCK_DIV_4,
      TIME3A4_CLOCK_DIV_8,
      TIME3A4_CLOCK_DIV_16,
      TIME3A4_CLOCK_DIV_32,
      TIME3A4_CLOCK_DIV_64,
      TIME3A4_CLOCK_DIV_128
    }ENUM_TIME3A4_CLKDIV;
    typedef enum ENUM_TIME3A4_MODE_t{
      TIME3A4_FREERUNNING,
      TIME3A4_DOWNMODE,
      TIME3A4_MODULE,
      TIME3A4_UP_DOWN
    }ENUM_TIME3A4_MODE;
    
    typedef enum ENUM_TIME3A4_CHANNAL_t{
      TIME3A4_CH_0,
      TIME3A4_CH_1
    }ENUM_TIME3A4_CHANNAL;
    
    #if (TIME3 > 0)
        extern void setT3CCxValue(unsigned char val, ENUM_TIME3A4_CHANNAL channal);
        extern void initTime3(ENUM_TIME3A4_CLKDIV time_clkdiv,ENUM_TIME3A4_MODE time_mode, \
          ENUM_TIME3A4_CHANNAL channal);
        extern int  time3Value();
        extern void time3Clear();
        extern int  time3ChannalValue(ENUM_TIME3A4_CHANNAL channal);
        extern void time3ChannalClear(ENUM_TIME3A4_CHANNAL channal);
    #endif
    #if (TIME4 > 0)
      extern void setT4CCxValue(unsigned char val, ENUM_TIME3A4_CHANNAL channal);
      extern void initTime4(ENUM_TIME3A4_CLKDIV time_clkdiv,ENUM_TIME3A4_MODE time_mode, \
        ENUM_TIME3A4_CHANNAL channal);
      extern int  time4Value();
      extern void time4Clear();
      extern int  time4ChannalValue(ENUM_TIME3A4_CHANNAL channal);
      extern void time4ChannalClear(ENUM_TIME3A4_CHANNAL channal);
    #endif
  #endif
#endif