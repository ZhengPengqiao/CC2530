#include "INTUART.h"

#if (UART0 > 0)
    char UART0_CHAR[RX_BUFFER_SIZE];   //定义接收缓存大小
    int end,start;
    int sendstatus = 0;
    void (*UART0_RXISR_function)();    //定义接收函数指针
    void (*UART0_TXISR_function)();    //定义发送函数指针
    
    
/*****************************************************************************
*  函数介绍  ： 初始化系统时钟，和运行时钟
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
    void setSystemCLK()
    {
      CLKCONCMD &= ~(1 << 6); //设置系统时钟源为32MHz
      while( CLKCONCMD & (1 << 6) );
      CLKCONCMD &= ~(7 << 0); //当前系统时钟频率为32MHz
    
    }
    
  
/*****************************************************************************
*  函数介绍  ： 初始化串口
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
  void initUart()
  {
    int i;
    for(i = 0; i < RX_BUFFER_SIZE; i++)
    {
      UART0_CHAR[i] = 0;
    }
    
    UART0_RXISR_function = 0;   //初始化函数指针
    UART0_TXISR_function = 0;   //初始化函数指针
    end = start = 0;
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
    IEN0   |= (1 << 2); //UART0 RX中断使能
    IEN2   |= (1 << 2); //UART0 TX中断使能
    EA     = 1;         //开总中断
  } 
  
  
  /*****************************************************************************
  *接收相关的东西
  ******************************************************************************/
  #pragma vector = URX0_VECTOR
  __interrupt void UART0_RXISR(void)
  {         

      URX0IF = 0;
      if(end >= RX_BUFFER_SIZE )
        end = 0;
     UART0_CHAR[end++] = U0DBUF;
     if( UART0_RXISR_function != 0)
     {
         UART0_RXISR_function();
     }
  }
  
  /*****************************************************************************
  *  函数介绍  ：设置接收后的处理函数
  *            ：
  *    参数    ：inUART0_TXISR_function将要设置的函数指针
  *   返回值   ：无
  ******************************************************************************/ 
  void setUART0_RXISR( void (*inUART0_RXISR_function)())
  {
    UART0_RXISR_function = inUART0_RXISR_function;
  }
  
   
  
  /*****************************************************************************
  *发送相关的东西
  ******************************************************************************/
 
  #pragma vector = UTX0_VECTOR
  __interrupt void UART0_TXISR(void)
  {
      UTX0IF = 0;   
      sendstatus = 0;
      if(UART0_TXISR_function != 0 )
      {
          UART0_TXISR_function();
      }
  }

  
  /*****************************************************************************
  *  函数介绍  ：设置发送后的处理函数
  *            ：
  *    参数    ：inUART0_RXISR_function将要设置的函数指针
  *   返回值   ：无
  ******************************************************************************/ 
  void setUART0_TXISR( void (*inUART0_TXISR_function)())
  {
    UART0_TXISR_function = inUART0_TXISR_function;
  }
  
  
  /*****************************************************************************
*  函数介绍  ： 发送一个字符
*            ：
*    参数    ： ch : 将要发送的字符
*   返回值   ： 无
******************************************************************************/
  void sendChar(char ch)
  {
    sendstatus = 1;
    U0DBUF = ch;
    while( sendstatus == 1 );
  }
  
  
/*****************************************************************************
*  函数介绍  ： 读取一个字符
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/

  char readChar()
  {
    if(start != end)
    {
      char ch = UART0_CHAR[start];
      UART0_CHAR[start] = 0;
      start++;
      if(start >= RX_BUFFER_SIZE)
      {
        start = 0;
      }
      
      return ch;
    }
    else
    {
      return 0;
    }
     
  }
  
  /*****************************************************************************
*  函数介绍  ： 发送字符串
*            ：
*    参数    ： str : 字符串指针
*            ： len : 字符串长度
*   返回值   ： 无
******************************************************************************/

  void sendString(char * str, int len)
  {
      int i = 0;
      while(i < len)
      {
        sendChar(*(str+i));
        i++;
      }
      
  }
  
  /*****************************************************************************
  *  函数介绍  ： 读取len个字符，如果缓存中够len个字符，则读取len个。否则，读取
  *            ： 缓存中的所有字符
  *    参数    ： str : 用于保存字符串的位置
  *            ： len : 要读取的长度
  *   返回值   ： 读到的字符个数
  ******************************************************************************/ 
  int readString(char * str, int len)
  {

      int i = 0;
      if(len <= 0)
      {
        return -1;
      }
      char ch = 0;
      ch = readChar();
      while( (ch != 0) )
      {
         *(str+i) = ch;
          i++;
          if( i < len )
          {
            ch = readChar();
          }
          else
          {
            break;
          }
      }
      return i;
  }
  
  void sendNewLine()
  {
       sendString("\r\n",2);
  }
#endif
