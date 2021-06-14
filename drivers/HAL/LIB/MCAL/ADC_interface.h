#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define ADCMUX_Reg  *((volatile u8*)0x27)
#define ADCSRA_Reg  *((volatile u8*)0x26)
#define ADCH_Reg    *((volatile u8*)0x25)
#define ADCL_Reg    *((volatile u8*)0x24)

extern void ADC_Init(void);
extern u16 ADC_u16GetResult(void);

#endif