
/********************************/
/* Mohammed Mostafa Hasan       */
/* date 4/2/2021               */
/* version_1                    */
/********************************/

#include "STD_TYPES.h" 
#include "BIT_MATH.h
#include "DIO_Register.h"

void seven_se_vinit(u8 port_name)
{
	
	DIO_voidSetPortDirection( u8 port_name,0xff);
	
		
} 



    void seven_seg_write(u8 portname,u8 number)
	  {
		  
		  u8 arr[]={0x3f,0x06,0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f,0x6f };
		  
   DIO_voidSetPortValue(u8  portname,arr[number]);
  
  
	  }