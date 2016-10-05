#include "CHECKUART.h"


  
#if (UART0 > 0)
    void setSystemCLK()
    {
      CLKCONCMD &= ~(1 << 6); //设置系统时钟源为32MHz
      while( CLKCONCMD & (1 << 6) );
      CLKCONCMD &= ~(7 << 0); //当前系统时钟频率为32MHz
    
    }
  /*****************************************************************************
  *  函数介绍  ：  初始化串口
  *            ：
  *    参数    ： 无
  *   返回值   ： 无
  ******************************************************************************/
  void initUart()
  {
    PERCFG &= ~(1 << 0); //设置uart0在位置1
    P0SEL  |= (1 << 2);  //将P0_2设置为外设
    P0SEL  |= (1 << 3);  //将P0_3设置为外设
    P2DIR  &= ~(3 << 6); //设置uart0的优先级最大
    U0CSR  |= (1 << 7);  //usart0做为uart0
    //设置波特率为115200
    U0GCR  |= (11 << 0); //设置BAUD_E为11
    U0BAUD = 216;        //设置U0BAUD_M为216
    UTX0IF = 0;          //UART0 TX中断标志为0
    U0CSR  |= (1 << 6); // 设置Uarrt0的接收功能
  } 
  
  void sentChar(char ch)
  {
    U0DBUF = ch;
    while( UTX0IF == 0 );  //直到有发送完成中断，表示发送完成
    UTX0IF = 0;
  }
  
  void sentString(char * str, int len)
  {
    int i = 0;
    while(i < len)
    {
      sentChar(*(str+i));
      i++;
    }
  }
  
  char readChar()
  {
    if( U0CSR & (1 << 2) )
    {
        return U0DBUF;
    }
    return -1;
  }
  
  int readString(char * str, int len)
  {
    int i = 0;
    char ch;
    while(i < len)
    {
      ch=readChar();
      if(ch != (char)-1)
      {
        *(str+i) = ch;
        i++;
      }
    }
    
    return i;
  }
#endif
