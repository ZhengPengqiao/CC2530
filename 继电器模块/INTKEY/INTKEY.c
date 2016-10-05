#include "INTKEY.h"


 #if ( (IS1 > 0) || (IS2 > 0) )
    void intKeyInit()
    {
      #if (IS1 > 0)
        P0IEN |= (1 << 1);   //引脚使能
        PICTL |= (1 << 0);   //端口0下降沿触发
        P0IFG &= (1 << 1);   //初始化中断值
        IEN1  |= (1 << 5);   //端口0使能
        EA = 1;
      #endif
        
      #if (IS2 > 0)
        P2IEN |= (1 << 0);    //引脚使能
        PICTL |= (1 << 3);    //端口0下降沿触发
        P2IFG &= (1 << 0);   //初始化中断值
        IEN2  |= (1 << 1);    //端口0使能
        EA = 1;
      #endif
    }

  #endif


#if (IS1 > 0)
    void (*IS1_fun)(void);
    void setIntKey1Fun(void (*fun)(void))
    {
      IS1_fun = fun;
    }

    #pragma vector = P0INT_VECTOR
    __interrupt void P0_ISR(void)
    {
      IS1_fun();
      P0IFG &= ~(1 << 1);   //初始化中断值      
      P0IF = 0x00;              //处理到这里。端口0的中断应该都得到处理了,端口0
                                //无中断未决
    }
#endif
    
#if (IS2 > 0)
    void (*IS2_fun)(void);
    void setIntKey2Fun(void (*fun)(void))
    {
      IS2_fun = fun;
    }

    #pragma vector = P2INT_VECTOR
    __interrupt void P2_ISR(void)
    {
      IS2_fun();
      P2IFG &= ~(1 << 0);
    
      P2IF = 0x00;          //处理到这里。端口2的中断应该都得到处理了,端口2无中断未决
      
      
    }
#endif


