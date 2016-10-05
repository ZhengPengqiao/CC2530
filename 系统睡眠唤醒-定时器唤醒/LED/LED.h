#ifndef __LED_H__
#define __LED_H_
#include "ioCC2530.h"
/*****************************************************************************
* 需要的Led灯及其函数
******************************************************************************/
 #define D1 1
 #define D2 1
 #define D3 0
 #define RX 0
 #define TX 0
/****************************************************************************/

/*****************************************************************************
*定义led灯引脚
*****************************************************************************/
  #if ( (D1 > 0) || (D2 > 0) || (D3 > 0) || (TX > 0) || (RX > 0) )
    extern void ledInit();
  #endif
    
  #if (D1 > 0)
    #define LED1 P1_0
    extern void led1On();
    extern void led1Off();
    extern void led1Toggle();
  #endif
  
  #if (D2 > 0)
    #define LED2 P1_1
    extern void led2On();
    extern void led2Off();
    extern void led2Toggle();
  #endif
  
  #if (D3 > 0)
    #define LED3 P1_4
    extern void led3On();
    extern void led3Off();
    extern void led3Toggle();
  #endif
  
  #if (RX > 0)
    #define RXLED P0_2
    extern void rxLedOn();
    extern void rxLedOff();
    extern void rxToggle();
  #endif
  
  #if (TX > 0)
    #define TXLED P0_3
    extern void txLedOn();
    extern void txLedOff();
    extern void txToggle();
  #endif

#endif