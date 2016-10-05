#include "ADC.h"

float getChannalValue(ENUM_ADC_CHANNAL channal,ENUM_ADC_RESOLUTION resolution,\
  ENUM_ADC_VOLTAGE voltage)
{
  short value = 0;
  char valueH = 0;
  char valueL = 0;
  //应尽量先设置参考电压。参考电压稳定需要一定时间。
  ADCCON3 &= ~(3 << 6);    //将参考电压为清楚为0
  switch(voltage)
  {
  case INTERNAL_REFERENCE:
    //ADCCON3 |= (0 << 6);   //内部参考电压
    break;
  case AIN7_EXTERNAL_VOLTAGE:
    ADCCON3 |= (1 << 6);   //AIN7引脚参考的电压
    break;
  case AVDD5_PIN_VOLTAGE:
    ADCCON3 |= (2 << 6);   //AVDD5做为电压
    break;
  case AIN6_AIN7_VOLTAGE:
    ADCCON3 |= (3 << 6);   //AIN6_AIN7差分输入的外部参考电压
    break;
  }

  
  ADCCON3 &= ~(15 << 0);
  switch(channal)
  {
    case  AIN0:
      APCFG   |=  (1 << 0); //设置P0_0为模拟输入
      ADCCON3 |= (0 << 0);  //通道选择
      break;
    case  AIN1:
      APCFG   |=  (1 << 1);
      ADCCON3 |= (1 << 0);  //通道选择
      break;
    case  AIN2:
      APCFG   |=  (1 << 2);
      ADCCON3 |= (2 << 0);  //通道选择
      break;
    case  AIN3:
      APCFG   |=  (1 << 3);
      ADCCON3 |= (3 << 0);  //通道选择
      break;
    case  AIN4:
      APCFG   |=  (1 << 4);
      ADCCON3 |= (4 << 0);  //通道选择
      break;
    case  AIN5:
      APCFG   |=  (1 << 5);
      ADCCON3 |= (5 << 0);  //通道选择
      break;
    case  AIN6:
      APCFG   |=  (1 << 6);
      ADCCON3 |= (6 << 0);  //通道选择
      break;
    case  AIN7:
      APCFG   |=  (1 << 7);
      ADCCON3 |= (7 << 0);  //通道选择
      break;
    case  AIN0_AIN1:
      APCFG   |=  (1 << 0);
      APCFG   |=  (1 << 1);
      ADCCON3 |= (8 << 0);  //通道选择
      break;
    case  AIN2_AIN3:
      APCFG   |=  (1 << 2);
      APCFG   |=  (1 << 3);
      ADCCON3 |= (9 << 0);  //通道选择
      break;
    case  AIN4_AIN5:
      APCFG   |=  (1 << 4);
      APCFG   |=  (1 << 5);
      ADCCON3 |= (10 << 0);  //通道选择
      break;
    case  AIN6_AIN7:
      APCFG   |=  (1 << 6);
      APCFG   |=  (1 << 7);
      ADCCON3 |= (11 << 0);  //通道选择
      break;
    case  GND:
      ADCCON3 |= (12 << 0);  //地参考
      break;
    case  VCC:
      ADCCON3 |= (13 << 0);  //正电压参考
      break;
    case  TEMP:
      TR0 = (1 << 0);                 //设置为1来连接温度到SOC_ADC
      ATEST = (1 << 0);               //使能温度传感
      ADCCON3 |= (14 << 0);  //温度传感器
      break;
    case  VDD_3:
      ADCCON3 |= (15 << 0);  //
      break;
  }
  
  ADCCON3 &= ~(3 << 4);
  switch(resolution)
  {
    case BIT7:
      ADCCON3 |= (0 << 4);   //64抽取率，7位的分辨率
      break;
    case BIT9:
      ADCCON3 |= (1 << 4);   //128抽取率，9位的分辨率
      break;
    case BIT10:
      ADCCON3 |= (2 << 4);   //256抽取率，10位的分辨率
      break;  
    case BIT12:
      ADCCON3 |= (3 << 4);   //512抽取率，12位的分辨率
      break;  
   }
  
  

  
  ADCCON1 |= (3 << 4);   //选择ADC的启动模式为手动
  ADCCON1 |= (1 << 1);   //启动转换
  
  while( !(ADCCON1 & (1 << 7)) );  //查看转换是否完成
  //ADCL寄存器低两位无效，由于他只有12位有效，ADCL寄存器低4位无效。网上很多代码
  //这里都是移动两位，那是不对的
  value = 0;
  valueL = ADCL;
  valueH = ADCH;
  value |= valueL;  
  value |= valueH << 8;

  switch(resolution)
  {
    case BIT7:
      value = value >> 8;
      break;
    case BIT9:
      value = value >> 6;
      break;
    case BIT10:
      value = value >> 5;
      break;  
    case BIT12:
      value = value >> 3;
      break;  
   }

  //根据AD值，计算出实际的温度，温度系数应该是4.5 /'c进行温度校正，这里减去5'C
  //(不同芯片根据具体情况校正)
  return value;  
}
