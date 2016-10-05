#include "KEY.h"
#if ( (S1 > 0) || (S2 > 0) )
  //初始化Key
  void keyInit()
  {
    #if (S1 > 0)
      P0SEL &= ~(1 << 1);   //通用IO引脚
      P0DIR &= ~(1 << 1);   //输入方向
      //设置为上拉
      P0INP &= ~(1 << 1);
      P2INP &= ~(1 << 5);
    #endif
    #if (S2 > 0)
      
      P2SEL &= ~(1 << 0);   //通用IO引脚
      P2DIR &= ~(1 << 0);   //输入方向
      //设置为上拉
      P2INP &= ~(1 << 0);
      P2INP &= ~(1 << 7);
    #endif
  }
#endif
#if (S1 > 0)
  
    int key1Scan()
    {
      int i;
      if(KEY1 == 0) //高电平有效
      {
          //检测到按键
          for(i = 0;i<10000;i++)
          {
          }
          
          if(KEY1 == 0)
          {
            while(!KEY1); //直到松开按键
            return(1);
          }
      }
      return 0;
    }
#endif

#if (S2 > 0)
    int key2Scan()
    {
      int i;
      if(KEY2 == 0) //高电平有效
      {
          //检测到按键
        for(i = 0;i<10000;i++)
        {
        }
          if(KEY2 == 0)
          {
            while(KEY2); //直到松开按键
            return(1);
          }
      }
      return 0;
    }
#endif 