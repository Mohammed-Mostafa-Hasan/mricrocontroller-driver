/********************************/
/* Mohammed Mostafa Hasan       */
/* date 2/10/2021               */
/* version_1                    */
/********************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA  'A'
#define PORTB  'B'
#define PORTC  'C'
#define PORTD  'D'
void DIO_voidSetPinDirection   (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction);
void DIO_voidSetPortDirection  (u8 Copy_u8PORT,u8 Copy_u8Direction);
void DIO_voidSetPinValue       (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value);
void DIO_voidSetPortValue      (u8 Copy_u8PORT,u8 Copy_u8Value);
void DIO_voidClearPinValue     (u8 Copy_u8PORT,u8 Copy_u8PIN);
void DIO_voidClearPortValue    (u8 Copy_u8PORT);
void DIO_voidSetTogglePinValue (u8 Copy_u8PORT,u8 Copy_u8PIN);
u8   DIO_u8GetPinValue         (u8 Copy_u8PORT,u8 Copy_u8PIN);
u8   DIO_u8GetPortValue        (u8 Copy_u8PORT);

#endif
