#ifndef __ADC_H_
#define __ADC_H_

#define ADC 1
#include "ioCC2530.h"
#if( ADC > 0 )
    typedef enum ADC_CHANNAL_E{
        AIN0,
        AIN1,
        AIN2,
        AIN3,
        AIN4,
        AIN5,
        AIN6,
        AIN7,
        AIN0_AIN1,
        AIN2_AIN3,
        AIN4_AIN5,
        AIN6_AIN7,
        GND,
        VCC,
        TEMP,
        VDD_3
    }ENUM_ADC_CHANNAL;
   
    typedef enum ADC_RESOLUTION{
      BIT7,
      BIT9,
      BIT10,
      BIT12
    }ENUM_ADC_RESOLUTION;
    
    typedef enum ADC_VOLTAGE{
      INTERNAL_REFERENCE,
      AIN7_EXTERNAL_VOLTAGE,
      AVDD5_PIN_VOLTAGE,
      AIN6_AIN7_VOLTAGE,
    }ENUM_ADC_VOLTAGE;
    extern float getChannalValue(ENUM_ADC_CHANNAL channal,\
      ENUM_ADC_RESOLUTION resolution,\
      ENUM_ADC_VOLTAGE voltage);
#endif
#endif