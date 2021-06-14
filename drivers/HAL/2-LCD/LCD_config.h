/********************************/
/* Mohammed Mostafa Hasan       */
/* date 3/28/2021               */
/* version_1                    */
/********************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define LCD_u8line1   0
#define LCD_u8line2   1

#define  LCD_Data_PORT   DIO_PORTA
#define  RS              DIO_PORTD,PIN0 
#define  RW              DIO_PORTD,PIN1 
#define  Enable          DIO_PORTD,PIN2 

#define  Function_Set    0b00111000
#define  DIS_ON_OFF      0b00001111
#define  CLR_LCD         0b00000001
#define  Intery_Mode     0b00000110

#endif