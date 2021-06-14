 
/********************************/
/* Mohammed Mostafa Hasan       */
/* date 3/28/2021               */
/* version_1                    */
/********************************/
 
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include <avr/delay.h>
 
 #include "DIO_interface.h"
 
 #include "LCD_interface.h" 
 #include "LCD_config.h"
 
 void LCD_VoidSendCommand(u8 Copy_u8Command)
 {
	 //RS = 0
	 DIO_voidSetPinValue (RS,LOW);
	 //R/W=0
	 DIO_voidSetPinValue (RW,LOW);
    //send command data
     DIO_voidSetPortValue(LCD_Data_PORT,Copy_u8Command);
       //ENABLE 1 THEN 0
	    DIO_voidSetPinValue (Enable,HIGH);	 
	   _delay_ms(1);
	    DIO_voidSetPinValue (Enable,LOW);
        _delay_ms(1);	 
 }
 void LCD_VoidSendData(u8 Copy_u8Data)
 
 {
	 //RS = 1
	  DIO_voidSetPinValue (RS,HIGH);
	 //R/W=0
	  DIO_voidSetPinValue (RW,LOW);
     //send data
     DIO_voidSetPortValue(LCD_Data_PORT,Copy_u8Data);
	   //ENABLE 1 THEN 0
        DIO_voidSetPinValue (Enable,HIGH);	 
	   _delay_ms(1);
	   DIO_voidSetPinValue (Enable,LOW);
        _delay_ms(1);	 
 }
 
 
 void LCD_VoidInit(void)
 {
	 _delay_ms(35);
 LCD_VoidSendCommand(Function_Set);
     _delay_us(40);
 LCD_VoidSendCommand(DIS_ON_OFF);
     _delay_us(1);
 LCD_VoidSendCommand(CLR_LCD);
     _delay_ms(2);
 LCD_VoidSendCommand(Intery_Mode);

 }
  void lcd_showString(u8 * copy_string)
  {

	  while ((*copy_string) != '\0')
	  {
	  LCD_VoidSendData(*copy_string);
	_delay_ms(300);
	  copy_string ++;

	  }
	  void lcd_showNumber(u8 * copy_Number)
	    {

	  	  while ((*copy_string) != '\0')
	  	  {
	  	  LCD_VoidSendData(*copy_Number);
	  	_delay_ms(300);
	  	copy_Number ++;

	  	  }
	    }
	  void clear_lcd();
  }
  void clear_lcd()
  	  {
  		  LCD_VoidSendCommand(CLR_LCD);

  	  }

  void LCD_voidSetPosition(u8 Copy_u8LineNum,u8 copy_u8col)
  {
	  if(copy_u8col<=39)
	  {
		  switch(Copy_u8LineNum)
		  {
		  case LCD_u8line1: LCD_VoidSendCommand(0x80+copy_u8col); break;
		  case LCD_u8line2: LCD_VoidSendCommand(0xc0+copy_u8col); break;

		  default :/*error */; break;
		  }
	  }
	  else
	  {
		 // error
		  
	  }
	  
  }
  
  //create a function for displaying a number

  void LCD_voidSendNumber(u32 Copy_u8Value)
  {
  if(Copy_u8Value == 0)
  {
  LCD_voidSendData('0');
  }
  else
  {
  s32 c =-1;
  s32 arr[100];
  while(Copy_u8Value > 0)
  {
  arr[++c] = Copy_u8Value % 10 + '0';
  Copy_u8Value /= 10;
  }
  while(c>=0)
  {
  LCD_voidSendData(arr[c--]);
  }
  }
  
  //special chrachter
  /*
  void LCD_printSpecialChachter(void)
  
  {
	  //first character
	 LCD_VoidSendCommand(0b01000000);

	 LCD_VoidSendData(0b00001110);
	 LCD_VoidSendData(0b00001110);
	 LCD_VoidSendData(0b00000100);
	 LCD_VoidSendData(0b00001110);
	 LCD_VoidSendData(0b00010101);
	 LCD_VoidSendData(0b00000100);
	 LCD_VoidSendData(0b00001010);
	 LCD_VoidSendData(0b00011011);
	  


	 //second character
	  LCD_VoidSendCommand(0b01001000);
	  
	    LCD_VoidSendData(0b00001110);
	 	 LCD_VoidSendData(0b00001110);
	 	 LCD_VoidSendData(0b00000100);
	 	 LCD_VoidSendData(0b00001110);
	 	 LCD_VoidSendData(0b00010101);
	 	 LCD_VoidSendData(0b00000111);
	 	 LCD_VoidSendData(0b00000000);
	 	 LCD_VoidSendData(0b00000000);

		 //third character
		 LCD_VoidSendCommand(0b01010000);
		        LCD_VoidSendData(0b00000000);
				LCD_VoidSendData(0b00000000);
			    LCD_VoidSendData(0b00000000);
			    LCD_VoidSendData(0b00000110);
			    LCD_VoidSendData(0b00001001);
			    LCD_VoidSendData(0b00000110);
			    LCD_VoidSendData(0b00000000);

		 //forth character
		 LCD_VoidSendCommand(0b01011000);

		                 LCD_VoidSendData(0b00000000);
		 				 LCD_VoidSendData(0b00000000);
		 				 LCD_VoidSendData(0b00000000);
		 				 LCD_VoidSendData(0b00000110);
		 				 LCD_VoidSendData(0b00001001);
		 				 LCD_VoidSendData(0b00000110);
		 				 LCD_VoidSendData(0b00000000);


	//fifth
		 LCD_VoidSendCommand(0b01100000);

		 LCD_VoidSendData(0b00000000);
		 		 				 LCD_VoidSendData(0b00000000);
		 		 				 LCD_VoidSendData(0b00000000);
		 		 				 LCD_VoidSendData(0b00000110);
		 		 				 LCD_VoidSendData(0b00001001);
		 		 				 LCD_VoidSendData(0b00000110);
		 		 				 LCD_VoidSendData(0b00000000);

	//six
				 LCD_VoidSendCommand(0b01101000);

				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 //////7

				 LCD_VoidSendCommand(0b01110000);

				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);
	        	 LCD_VoidSendData(0b00000000);
				 LCD_VoidSendData(0b00000000);

				 //////////8
				 LCD_VoidSendCommand(0b01111000);

				   LCD_VoidSendData(0b00001110);
				   LCD_VoidSendData(0b00001110);
				   LCD_VoidSendData(0b00000100);
				   LCD_VoidSendData(0b00001110);
				   LCD_VoidSendData(0b00010101);
				   LCD_VoidSendData(0b00000100);
				   LCD_VoidSendData(0b00001010);
				   LCD_VoidSendData(0b00011011);


  }
 
*/