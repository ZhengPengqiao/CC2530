#include "LED.h"

/*****************************************************************************
*函数含义：初始化LED小灯
*函数参数：无参数
*  返回值：无返回值
*****************************************************************************/
#if ( (D1 > 0) || (D2 > 0) || (D3 > 0) || (TX > 0) || (RX > 0) )
void ledInit()
  {
    #if (D1 > 0)
      P1SEL &= ~(1 << 0);
      P1DIR |=  (1 << 0);
    #endif
      
    #if (D2 > 0)
      P1SEL &= ~(1 << 1);
      P1DIR |=  (1 << 1);
    #endif
  
    #if (D3 > 0)
      P1SEL &= ~(1 << 4);
      P1DIR |=  (1 << 4);
    #endif
  
    #if (RX > 0)
      P0SEL &= ~(1 << 2);
      P0DIR |=  (1 << 2);
    #endif
  
    #if (TX > 0)
      P0SEL &= ~(1 << 3);
      P0DIR |=  (1 << 3);
    #endif
  }
#endif
#if (D1 > 0)
  void led1On()
  {
    LED1 = 0;
  }
  
  void led1Off()
  {
    LED1 = 1;
  }
  void led1Toggle()
  {
    LED1 = ~LED1;
  }
#endif

#if (D2 > 0)
  void led2On()
  {
    LED2 = 0;
  }
  
  void led2Off()
  {
    LED2 = 1;
  }

  void led2Toggle()
  {
    LED2 = ~LED2;
  }
#endif

#if (D3 > 0)
  void led3On()
  {
    LED3 = 0;
  }
  
  void led3Off()
  {
    LED3 = 1;
  }

  void led3Toggle()
  {
    LED3 = ~LED3;
  }
#endif

#if (RX > 0)
  void rxLedOn()
  {
    RXLED = 0;
  }
  
  void rxLedOff()
  {
    RXLED = 1;
  }

  void rxToggle()
  {
    RXLED = ~RXLED;
  }
#endif

#if (TX > 0)
  void txLedOn()
  {
    TXLED = 0;
  }
  
  void txLedOff()
  {
    TXLED = 1;
  }

  void txToggle()
  {
    TXLED = ~TXLED;
  }
#endif
