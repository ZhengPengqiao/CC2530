#ifndef __KEY_H_
#define __KEY_H_

  #include "ioCC2530.h"
  
#define S1 1   //使用按键KEY1
#define S2 1   //使用按键KEY2

  #if ( (S1 > 0) || (S2 > 0) )
    extern void keyInit();
  #endif

  #if (S1 > 0)
    #define KEY1 P0_1
    extern int key1Value();
    extern int key1Scan();
  #endif

  #if (S2 > 0)
    #define KEY2 P2_0
    extern int key2Value();
    extern int key2Scan();
  #endif 
#endif