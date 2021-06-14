/********************************/
/* Mohammed Mostafa Hasan       */
/* date 2/10/2021               */
/* version_1                    */
/********************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h"
#include "DIO_Register.h"


void DIO_voidSetPinDirection   (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
	if(1==Copy_u8Direction)
	{		
		switch(Copy_u8PORT)
		{
		case 0: SET_BIT(DDRA,Copy_u8PIN);break;
        case 1: SET_BIT(DDRB,Copy_u8PIN);break;
		case 2: SET_BIT(DDRC,Copy_u8PIN);break;
		case 3: SET_BIT(DDRD,Copy_u8PIN);break;
  		}
		
	}
	else if(0==Copy_u8Direction)
	{
		
		switch(Copy_u8PORT)
		{
		case 0: CLR_BIT(DDRA,Copy_u8PIN);break;
        case 1: CLR_BIT(DDRB,Copy_u8PIN);break;
		case 2: CLR_BIT(DDRC,Copy_u8PIN);break;
		case 3: CLR_BIT(DDRD,Copy_u8PIN);break;
  		}
				
		
	}
	
	
}


void DIO_voidSetPortDirection  (u8 Copy_u8PORT,u8 Copy_u8Direction)
{
	if(1==Copy_u8Direction)
	{		
		switch(Copy_u8PORT)
		{
		case 0: DDRA = 0b11111111; break;
        case 1: DDRB = 0b11111111; break;
		case 2: DDRC = 0b11111111; break;
		case 3: DDRD = 0b11111111; break;
  		}
		
	}
	else if(0 ==Copy_u8Direction)
	{
		
		switch(Copy_u8PORT)
		{
		case 0: DDRA = 0b00000000; break;
        case 1: DDRB = 0b00000000; break;
		case 2: DDRC = 0b00000000; break;
		case 3: DDRD = 0b00000000; break;
  		}
				
		
	}
	
	
}

void DIO_voidSetPinValue   (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
    if(1==Copy_u8Value)
	{		
		switch(Copy_u8PORT)
		{
		case 0: SET_BIT(PORTA,Copy_u8PIN); break;
        case 1: SET_BIT(PORTB,Copy_u8PIN); break;
		case 2: SET_BIT(PORTC,Copy_u8PIN); break;
		case 3: SET_BIT(PORTD,Copy_u8PIN); break;
  		}
		
	}
	else if(0==Copy_u8Value)
	{
		
		switch(Copy_u8PORT)
		{
		case 0: CLR_BIT(PORTA,Copy_u8PIN); break;
        case 1: CLR_BIT(PORTB,Copy_u8PIN); break;
		case 2: CLR_BIT(PORTC,Copy_u8PIN); break;
		case 3: CLR_BIT(PORTD,Copy_u8PIN); break;
  		}
				
		
	}
	
	
	
	
}
                                             //0x3f == arr[0] 

void DIO_voidSetPortValue   (u8 Copy_u8PORT,u8 Copy_u8Value)
{
    u8 arr[10];
	{		
		switch(Copy_u8PORT)
		{
		case 0: PORTA=arr[Copy_u8Value]; break;
        case 1: PORTB=arr[Copy_u8Value]; break;
		case 2: PORTC=arr[Copy_u8Value]; break;
		case 3: PORTD=arr[Copy_u8Value]; break;
		
  		}
		
	}
	
	
}
	void DIO_voidClearPinValue  (u8 Copy_u8PORT,u8 Copy_u8PIN)
	
	{
      

switch(Copy_u8PORT)
		{
		case 0: CLR_BIT(PORTA,Copy_u8PIN); break;
        case 1: CLR_BIT(PORTB,Copy_u8PIN); break;
		case 2: CLR_BIT(PORTC,Copy_u8PIN); break;
		case 3: CLR_BIT(PORTD,Copy_u8PIN); break;
  		}

	}

 void DIO_voidClearPortValue    (u8 Copy_u8PORT)
 {
	 
	 switch(Copy_u8PORT)
		{
		case 0:  PORTA=0b00000000; break;
        case 1:  PORTA=0b00000000; break;
		case 2:  PORTA=0b00000000; break;
		case 3:  PORTA=0b00000000; break;
  		}
	
	 
 }
void DIO_voidSetTogglePinValue (u8 Copy_u8PORT,u8 Copy_u8PIN)

{
	
	
	switch(Copy_u8PORT)
		{
		case 0: TOG_BIT(PORTA,Copy_u8PIN); break;
        case 1: TOG_BIT(PORTB,Copy_u8PIN); break;
		case 2: TOG_BIT(PORTC,Copy_u8PIN); break;
		case 3: TOG_BIT(PORTD,Copy_u8PIN); break;
  		}

	}
	
u8   DIO_u8GetPinValue   (u8 Copy_u8PORT,u8 Copy_u8PIN)	

{
	u8 LOC_Result;
	switch(Copy_u8PORT)
		{
		case 0: LOC_Result = GET_BIT(PINA,Copy_u8PIN); break;
        case 1: LOC_Result = GET_BIT(PINB,Copy_u8PIN); break;
		case 2: LOC_Result = GET_BIT(PINC,Copy_u8PIN); break;
		case 3: LOC_Result = GET_BIT(PIND,Copy_u8PIN); break;
  		}
	return  LOC_Result;

	
}

u8   DIO_u8GetPortValue        (u8 Copy_u8PORT)
{
	
	u8 LOC_Result = 0;
	switch(Copy_u8PORT)
		{
		case 0: LOC_Result = PINA; break;
        case 1: LOC_Result = PINB; break;
		case 2: LOC_Result = PINC; break;
		case 3: LOC_Result = PIND; break;
  		}
	
	return LOC_Result;
}



