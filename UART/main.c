
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"



void main (void)
{
	/* 8 MHz */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,14);
	
	/*A9 = TX out 50Mhz  */
	MGPIO_voidSetPinDirection(GPIOA , PIN9 , OUTPUT_SPEED_50MHZ_PP);
	/*A10 = RX input floating */
	MGPIO_voidSetPinDirection(GPIOA , PIN10 , INPUT_FLOATING);
	MGPIO_voidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
    MUSART_voidInit();
	u8 x,y;

	while (1)
	{

		x = MUSART_voidReceive();
		if(x == 97 && x <= 97+25)
		{
			y=x-32;
			MUSART_voidTransmit(y);
		}

	}

}
		
		
