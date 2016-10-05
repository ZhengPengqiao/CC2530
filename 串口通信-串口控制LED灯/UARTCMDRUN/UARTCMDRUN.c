#include "UARTCMDRUN.h"
#include <string.h>
#include <stdlib.h>
#include "LED.h"


#if (LIST > 0)
/*****************************************************************************
*  命令函数对应表
******************************************************************************/
UARTCMDRUNArray *uartCmdRunHand;

/*****************************************************************************
*  函数介绍  ： 初始化串口命令
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
void initUartCmd()
{
  uartCmdRunHand = NULL;
}
/*****************************************************************************
*  函数介绍  ： 运行相应命令
*            ：
*    参数    ： cmd : 命令的字符串
*   返回值   ： 无
******************************************************************************/

void runUartCmd(char * cmd)
{
    UARTCMDRUNArray *q = uartCmdRunHand;
    while(q != NULL)
    {
       if( strcmp(cmd,q->cmd) == 0 )
       {
          q->uartCmdRun_fun();
       }
       q = q->next;
    }
}


/*****************************************************************************
*  函数介绍  ： 添加一个命令映射
*            ：
*    参数    ： cmd : 将要添加的映射
*            ： inuartCmdRun_fun ： 对应的函数
*   返回值   ： 删除成功返回0,否则返回1
******************************************************************************/
int addUartCmd(char * cmd, void (*inuartCmdRun_fun)())
{
   UARTCMDRUNArray **qend = &uartCmdRunHand;
   UARTCMDRUNArray *q = (UARTCMDRUNArray*)calloc( 1,sizeof(UARTCMDRUNArray) );
   if(q == NULL)
   {
     return -1;
   }
   strcpy(q->cmd,cmd);
   q->uartCmdRun_fun = inuartCmdRun_fun;
   q->next = NULL;
    while(*qend != NULL)
    {
        qend = &((*qend)->next); 
    }
     *qend = q;
    return 0;
}


/*****************************************************************************
*  函数介绍  ： 删除一个命令映射
*            ：
*    参数    ： cmd : 将要删除的映射
*   返回值   ： 删除成功返回0,否则返回1
******************************************************************************/

int deleteUartCmd(char * cmd)
{
    UARTCMDRUNArray *q = uartCmdRunHand;
    UARTCMDRUNArray *parent = uartCmdRunHand;
    int ret = 1;
    while(q != NULL)
    {
       if( strcmp(cmd,q->cmd) == 0 )
       {
          if( q == uartCmdRunHand )
          {
              uartCmdRunHand = q->next;
          }
          else
          {
              parent->next = q->next;
          }
          free(q);
          ret = 0;
          break;
       }
       parent = q;
       q = q->next;
    }
    return ret;
}
#endif

#if (ARRAY > 0)
UARTCMDRUNArray uartCmdRunArray[ARRAY_SIZE];

/*****************************************************************************
*  函数介绍  ： 初始化串口命令
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
void initUartCmd()
{
  int i;
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    uartCmdRunArray[i].cmd[0] = '\n';
    uartCmdRunArray[i].uartCmdRun_fun = NULL;
  }
}

/*****************************************************************************
*  函数介绍  ： 运行相应命令
*            ：
*    参数    ： cmd : 命令的字符串
*   返回值   ： 无
******************************************************************************/

void runUartCmd(char * cmd)
{
  int i;
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    if( strcmp(uartCmdRunArray[i].cmd,cmd) == 0 )
    {
      if(uartCmdRunArray[i].uartCmdRun_fun != NULL)
      {
          uartCmdRunArray[i].uartCmdRun_fun();
      }
      break;
    }
  }
}


/*****************************************************************************
*  函数介绍  ： 添加一个命令映射
*            ：
*    参数    ： cmd : 将要添加的映射
*            ： inuartCmdRun_fun ： 对应的函数
*   返回值   ： 删除成功返回0,否则返回1
******************************************************************************/
int addUartCmd(char * cmd, void (*inuartCmdRun_fun)())
{
  int i;
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    if( uartCmdRunArray[i].cmd[0] == '\n')
    {
        strcpy(uartCmdRunArray[i].cmd,cmd);
        uartCmdRunArray[i].uartCmdRun_fun = inuartCmdRun_fun;
        return 0;
    }
  }
  return -1;
}


/*****************************************************************************
*  函数介绍  ： 删除一个命令映射
*            ：
*    参数    ： cmd : 将要删除的映射
*   返回值   ： 删除成功返回0,否则返回1
******************************************************************************/

int deleteUartCmd(char * cmd)
{
  int i;
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    if( strcmp(uartCmdRunArray[i].cmd,cmd) == 0 )
    {
        uartCmdRunArray[i].cmd[0] = '\n';
        uartCmdRunArray[i].uartCmdRun_fun = NULL;
        return 0;
    }
  }
  return -1;
}
#endif
 