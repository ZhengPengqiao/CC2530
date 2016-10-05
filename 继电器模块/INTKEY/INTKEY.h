#ifndef __INTKEY_H_
#define __INTKEY_H_

  #define IS1 1
  #define IS2 1
 
 #include "ioCC2530.h"

 #if ( (IS1 > 0) || (IS2 > 0) )
    extern void intKeyInit();
 #endif

  #if (IS1 > 0)
    extern void setIntKey1Fun(void (*fun)(void));
  #endif
  #if (IS2 > 0)
    extern void setIntKey2Fun(void (*fun)(void));
  #endif
#endif