此项目是，将睡眠模式下的CC2530通过按键中断唤醒，观察LED闪烁现象，



全功能模式：高频晶振（16M或者32M）和低频晶振（32.768K RCOSC/XOSC）全部工作，数字
处理模块正常工作。

PM1:高频晶振（16M或者32M）关闭，低频晶振（32.768K RCOSC/XOSC）工作，数字核心模块
正常工作

PM2: 低频晶振（32.768K RCOSC/XOSC）工作，数字核心模块关闭，系统通过RESET,外部中
断或者睡眠计数器溢出唤醒。

PM3: 晶振全部关闭，数字处理核心模块关闭，系统只能通过REST或者外部中断唤醒，此功
能下功耗最低。



系统的运行模式：
typedef enum SYSPOWER{
  ACTICE_IDLE = 0,  //全速运行
  POWER_MODE1 = 1,  //PM1
  POWER_MODE2 = 2,  //PM2
  POWER_MODE3 = 3   //PM3
}ENUM_SYSPOWER;
设置系统运行模式，将进入相应的模式
extern void sysPowerMode(ENUM_SYSPOWER mode);