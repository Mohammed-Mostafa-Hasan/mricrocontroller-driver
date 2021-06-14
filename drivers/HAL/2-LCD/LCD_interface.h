/********************************/
/* Mohammed Mostafa Hasan       */
/* date:2/2/2021               */
/* version_1                    */
/********************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


 void LCD_VoidSendCommand(u8 Copy_u8Command);
 void LCD_VoidSendData(u8 Copy_u8Data);
 void LCD_VoidInit(void);

 void lcd_showString(u8 *Copy_u8Data);
 void clear_lcd();

 void LCD_voidSetPosition(u8 Copy_u8LineNum,u8 copy_u8col);
 void LCD_voidSendNumber(u32 Copy_u8Value);
 void LCD_printSpecialChachter(void);
 void lcd_showNumber(u8 * copy_Number);
#endif
