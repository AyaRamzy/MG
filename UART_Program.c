/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 22 AUG 2020                            */
/* Version   : V01                                    */
/******************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"
#include "UART_Register.h"


void MUSART_voidInit(void)
{
	/* 9600    BRR =  0x341 */
	MUSART1 -> BRR =0x341;
	/* 115200  BRR =  0x */
	
	/* 1- Enable RX
	   2- Enable TX
	   3- Enable UART 
	*/
	SET_BIT(MUSART1-> CR1 , 2);
	SET_BIT(MUSART1-> CR1 , 3);
	SET_BIT(MUSART1-> CR1 , 13);
	/*Clear Status Registers */
	MUSART1->SR = 0;
	

}
void MUSART_voidTransmit(u8 arr[])
{
	u8 i =0;
	while (arr[i] != '\0')
	{
		MUSART1-> DR =arr[i];
		/* wait the transmition is complete */
		while(GET_BIT(MUSART1-> SR , 6) == 0);
		i++;
	}
	
}
u8 MUSART_voidReceive(void)
{
	while(GET_BIT(MUSART1-> SR , 5) == 0);
	return (0xFF & (MUSART1-> DR));
	
}
