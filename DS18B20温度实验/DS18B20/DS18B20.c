#include "ds18b20.h" 

#define Ds18b20IO P0_7       //温度传感器引脚

/*****************************************************************************
*  函数名称  ： Delay_us
*  函数介绍  ：  使用Time1定时器模模式，进行精确定位
*            ：
*    参数    ： k : 延时k us
*   返回值   ： 无
******************************************************************************/

void Delay_us(unsigned int k)//us延时函数
{ 

    T1CC0L = 0x10;
    T1CC0H = 0x00;
    T1CCTL0 |= (1 << 2);  //模模式只能使用0通道
    T1CTL = 0x02; 
    //一秒16M = 16000K = 16000000 次
    while(k)
    {
        while( ( T1STAT & (1 << 0) ) != 1);
        T1STAT &= ~(1 << 0);
        k--;
    }
    T1CTL = 0x00; //关闭定时器
}



void Delay_s(unsigned int k)
{
    while(k)
    {
        Delay_ms(1000);
        k--;
    }
}

void Ds18b20InputInitial(void)//设置端口为输入
{
    P0DIR &= 0x7f;
}

void Ds18b20OutputInitial(void)//设置端口为输出
{
    P0DIR |= 0x80;
}

char get18B20Ack()
{
  EA = 0;
  char ret = 1;
  Ds18b20OutputInitial();
  Ds18b20IO = 1;
  Delay_us(50);
  Ds18b20IO = 0;
  Delay_us(750);
  Ds18b20IO = 1;
  Ds18b20InputInitial();
  Delay_us(60);
  ret = Ds18b20IO;
  Ds18b20OutputInitial();
  Ds18b20IO = 1;
  Delay_us(240);
  EA = 1;
  return ret;
  
}


void write18B20(unsigned char ch)
{
  unsigned char i = 0;
  EA = 0;
  Ds18b20OutputInitial();
  for(i = 0; i < 8; i++)
  {
    if(ch & (1 << i))
    {
      Ds18b20IO = 0;
      Delay_us(6);
      Ds18b20IO = 1;
      Delay_us(60);      
    }
    else
    {
      Ds18b20IO = 0;
      Delay_us(60);
      Ds18b20IO = 1;
      Delay_us(6);      
    }
      
  }
  EA = 1;
}

unsigned char read18B20()
{
    unsigned char ret = 0;
    unsigned char i;
    EA = 0;
    Ds18b20OutputInitial();
    Ds18b20IO = 1;
    Delay_us(10);
    for(i = 0; i < 8; i++)
    {
      Ds18b20OutputInitial();
      Ds18b20IO = 0;
      Delay_us(3);
      Ds18b20IO = 1;
      Delay_us(3);
      Ds18b20InputInitial();
      ret |= (Ds18b20IO << i);
      Ds18b20IO = 0;
      Delay_us(30);
    }
    EA = 1;
    return ret;
}


//温度读取函数
unsigned char getDs18B20(void) 
{
    unsigned char V1,V2;   //定义高低8位 缓冲
    unsigned char temp;    //定义温度缓冲寄存器
    char status;
    status = get18B20Ack();
    if( status == 0)
    {
        write18B20(0xcc);    // 跳过读序号列号的操作
        write18B20(0x44);    // 启动温度转换
    }
    
    status = get18B20Ack();
    if( status == 0)
    {
        write18B20(0xcc);    //跳过读序号列号的操作 
        write18B20(0xbe);    //读取温度寄存器等（共可读9个寄存器） 前两个就是温度
    }
    
    V1 = read18B20();    //低位
    V2 = read18B20();    //高位
    temp = ((V1 >> 4)+((V2 & 0x07)*16)); //转换数据 

    return temp;
}

//温度读取函数 带1位小数位
float getFloatDs18B20(void) 
{
    unsigned char V1,V2;   //定义高低8位 缓冲
    unsigned int temp;     //定义温度缓冲寄存器
    char status;
    float fValue;
    status = get18B20Ack();
    if( status == 0)
    {
        write18B20(0xcc);    // 跳过读序号列号的操作
        write18B20(0x44);    // 启动温度转换
    }
    
    status = get18B20Ack();
    if( status == 0)
    {
        write18B20(0xcc);    //跳过读序号列号的操作 
        write18B20(0xbe);    //读取温度寄存器等（共可读9个寄存器） 前两个就是温度
    }
    V1 = read18B20();    //低位
    V2 = read18B20();    //高位
    //temp = ((V1 >> 4)+((V2 & 0x07)*16)); //转换数据 
    temp=V2*0xFF+V1;
    fValue = temp*0.0625;
    
    return fValue;
}
