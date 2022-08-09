/****************************************************************/
/* Author     : Aya Ramzy                                       */
/* Version    : V01                                             */
/* Data       : 1 Sep 2021                                      */
/****************************************************************/

/****************************************************************/
/* guard of file will call one time in .c                       */
/****************************************************************/
/****************** Driver of I2C1 ******************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "I2C_Interface.h"
#include "I2C_Config.h"
#include "I2C_Private.h"

/* Initiate the clocks at main.c file */

void MI2C_voidInit(void)
{
	/* Reset I2C */
	SET_BIT(MI2C->CR1,CR1_SWRST);
	CLR_BIT(MI2C->CR1,CR1_SWRST);

	/* I2C FM Mode as Master mode  */
	SET_BIT(MI2C->CCR,CCR_FS_MODE);
	SET_BIT(MI2C->CCR,CCR_DUTY);

	/* No stretching */
	SET_BIT(MI2C->CR1,CR1_NOSTRETCH);

    (MI2C->CCR) |= 1 ; //320000Hz
	MI2C->TRISE = 1;

	/* Disable the General call */
	CLR_BIT(MI2C->CR1,CR1_ENGC);

	/* Enable clock as 8MHz*/
	CLR_BIT(MI2C->CR2,CR2_FREQ0);
	CLR_BIT(MI2C->CR2,CR2_FREQ1);
	CLR_BIT(MI2C->CR2,CR2_FREQ2);
	SET_BIT(MI2C->CR2,CR2_FREQ3);
	CLR_BIT(MI2C->CR2,CR2_FREQ4);
	CLR_BIT(MI2C->CR2,CR2_FREQ5);

	/* Enable I2C */
	SET_BIT(MI2C->CR1,CR1_PE);
}

void I2C_voidStart(void)
{
	SET_BIT(MI2C->CR1,CR1_ACK);
	SET_BIT(MI2C->CR1,CR1_START);
	while (!(GET_BIT(MI2C->SR1,SR1_SB) &(1<<0)));  // Wait for SB bit to set
	/* Clear SB Bit */
    MI2C->SR1;
}
void I2C_voidStop (void)
{
	SET_BIT(MI2C->CR1,CR1_STOP);
}

void I2C_voidWriteData( u8 Copy_u8Data )
{
	/* indicates that the DR (Data Register) is Empty */
	while (GET_BIT(MI2C->SR1,SR1_TxE)==0);
	MI2C->DR = Copy_u8Data;
	/*  Byte transfer has finished */
	while (GET_BIT(MI2C->SR1,SR1_BTF)==0);

}
void I2C_voidWriteAddress( u8 Copy_u8Address)
{
	MI2C->DR = Copy_u8Address ;

	//I2Cx[I2C_Number]->CR1 &= ~(1<<10);  // clear the ACK bit
	/* wait until the address transmitted */
	while ((GET_BIT(MI2C->SR1,SR1_ADDR))==0);

	/* read SR1 and SR2 to clear the ADDR bit */
	 MI2C->SR1;
	 MI2C->SR2;
}

u8 I2C_u8Read(u8 Copy_u8Address)
{

		 MI2C->DR = Copy_u8Address ;  //  send the address
		while (!(GET_BIT(MI2C->SR1,SR1_ADDR) & (1<<1)));  // wait for ADDR bit to set


		CLR_BIT(MI2C->CR1,CR1_ACK);  // clear the ACK bit
	/* read SR1 and SR2 to clear the ADDR bit */
	    MI2C->SR1;
	    MI2C->SR2;
	    CLR_BIT(MI2C->CR1,CR1_STOP);  // Stop I2C

		while (!(GET_BIT(MI2C->SR1,SR1_RxNE) & (1<<6)));  // wait for RxNE to set

		return MI2C->DR;  // Read the data from the DATA REGISTER
}

