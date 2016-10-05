pwmPinMode(PWM_P1_0);		         //调用初始化函数
pwmPinMode(PWM_P1_1);		         //调用初始化函数

setTime1Priority();
setPWMLocation(PWM_1_LOCALTION); 
initT1PWM(250);     
setTime1PWMChannal(PWM_TIME1_CHANNAL1,50);
setTime1PWMChannal(PWM_TIME1_CHANNAL2,50);

while(1)
{
    setTime1PWMChannal(PWM_TIME1_CHANNAL1,50);
    setTime1PWMChannal(PWM_TIME1_CHANNAL2,250);
    delayMS(1000);  
    
    setTime1PWMChannal(PWM_TIME1_CHANNAL1,250);
    setTime1PWMChannal(PWM_TIME1_CHANNAL2,50);
    delayMS(1000);
}

PWM_1_LOCALTION ：位置1
通道 ： 引脚
0 : P0_2
1 : P0_3
2 : P0_4
3 : P0_5
4 : P0_6


PWM_2_LOCALTION ：位置2
通道 ： 引脚
0 : P0_2
1 : P0_1
2 : P0_0
3 : P0_6
4 : P0_7

/****************************************************************************
* 名    称: initT1PWM()
* 功    能: 设置周期时间，计数器频率为250KHz
* 入口参数: 无
* 出口参数: 无
****************************************************************************/
extern void initT1PWM(unsigned char val);

/*****************************************************************************
*  函数名称  ： setTime1Priority
*  函数介绍  ：设置定时器1的优先级最高
*            ：
*    参数    ： 无
*   返回值   ： 无
******************************************************************************/
extern void setTime1Priority();


/*****************************************************************************
*  函数名称  ： setPWMLocation
*  函数介绍  ：设置定时器1的输出引脚位置
*            ：
*    参数    ： localtion  ： 输出引脚的位置
*   返回值   ： 无
******************************************************************************/
extern void setPWMLocation(PWM_TIME1_LOCALTION localtion);


/*****************************************************************************
*  函数名称  ： setTime1PWMChannal
*  函数介绍  ：设置通道的值，并启动转换
*            ：
*    参数    ： time_channal：通道
*            ： val         ： 阈值
*   返回值   ： 无
******************************************************************************/
extern void setTime1PWMChannal(PWM_TIME1_CHANNAL time_channal,unsigned char val);


/*****************************************************************************
*  函数名称  ： pwmPinMode
*  函数介绍  ： 定会器1的输出引脚初始化，用于初始化PWM要输出的引脚
*            ：
*    参数    ： pinnum ： 引脚数
*   返回值   ： 无
******************************************************************************/