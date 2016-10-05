#ifndef __CHECKUART_H_
#define __CHECKUART_H_

#include <ioCC2530.h>

#define UART0 1
  
  #if (UART0 > 0)  
    extern void setSystemCLK();
    extern void initUart();
    extern void sentChar(char ch);
    extern void sentString(char * str, int len);
    extern char readChar();
    extern int readString(char * str, int len);
  #endif
#endif