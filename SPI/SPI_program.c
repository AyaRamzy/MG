/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 18 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void MSPI1_voidInit(void)
{
	/*Prescaller = CLK/2  */
	/* cloise clock polarity */
	#if    CLOCK_POLARITY == HIGH
	   SET_BIT(MSPI1 -> CR1 ,CR1_CPOL);
	#elif  CLOCK_POLARITY == LOW 
	   CLR_BIT(MSPI1 -> CR1 ,CR1_CPOL);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* Choise clock phase */
	#if    CLOCK_PHASE == HIGH
	   SET_BIT(MSPI1 -> CR1 ,CR1_CPHA);
	#elif  CLOCK_PHASE == LOW 
	   CLR_BIT(MSPI1 -> CR1 ,CR1_CPHA);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* Choise size of data frame format */
	#if    DATA_FRAME_FORMAT == EIGHT_BITS
	   CLR_BIT(MSPI1 -> CR1 ,CR1_DFF);
	#elif  DATA_FRAME_FORMAT == SIXTEEN_BITS
	   SET_BIT(MSPI1 -> CR1 ,CR1_DFF);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* Choice of SSM */
	#if    SLAVE_SELECT_MODE == HIGH
	   SET_BIT(MSPI1 -> CR1 ,CR1_SSM);
	   #if SSI == HIGH 
	    SET_BIT(MSPI1 -> CR1 ,CR1_SSI);
	   #elif SSI == LOW
	    CLR_BIT(MSPI1 -> CR1 ,CR1_SSI);
	   #else
	     #error ("Wrong choise")
	   #endif
	#elif  SLAVE_SELECT_MODE == LOW 
	   CLR_BIT(MSPI1 -> CR1 ,CR1_SSM);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* choise what will transmit first */
	#if    LSB_MSB == HIGH
	   SET_BIT(MSPI1 -> CR1 ,CR1_LSB_FIRST);
	#elif  SLAVE_SELECT_MODE == LOW 
	   CLR_BIT(MSPI1 -> CR1 ,CR1_LSB_FIRST);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* Prescaler */
	#if    BOAD_RATE == FCLK_DIVIDED_2
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif  BOAD_RATE == FCLK_DIVIDED_4
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif  BOAD_RATE == FCLK_DIVIDED_8
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif    BOAD_RATE == FCLK_DIVIDED_16
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif    BOAD_RATE == FCLK_DIVIDED_32
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif    BOAD_RATE == FCLK_DIVIDED_64
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR2);
	   
	#elif    BOAD_RATE == FCLK_DIVIDED_128
	   CLR_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR2);
	
	#elif    BOAD_RATE == FCLK_DIVIDED_256
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR0);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR1);
	   SET_BIT(MSPI1 -> CR1 ,CR1_BR2);
	  
	#else 
	   #error  ("Wrong choise")
   
    #endif
	
	/* choise master or slave */
	#if    MASTER_OR_SLAVE == HIGH
	   SET_BIT(MSPI1 -> CR1 ,CR1_MSTR);
	#elif  MASTER_OR_SLAVE == LOW 
	   CLR_BIT(MSPI1 -> CR1 ,CR1_MSTR);
	#else 
	   #error  ("Wrong choise")
    #endif
	
	/* choise of data direction */
	#if    DATA_DIRECTION == FULL_DUPLEX
	   CLR_BIT(MSPI1 -> CR1 ,CR1_RX_ONLY);
	#elif  DATA_DIRECTION == HALF_DUPLEX 
	   SET_BIT(MSPI1 -> CR1 ,CR1_RX_ONLY);
	#else 
	   #error  ("Wrong choise")
    #endif
    
	/* Enable SPI */
	SET_BIT(MSPI1 -> CR1 , CR1_SPE);
	
	
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DtaToTransmit,u8 * Copy_DataToReceive)
{
	/* CLR for slave select Pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_LOW);
	
	/* sent data */
	MSPI1 -> DR = Copy_u8DtaToTransmit;
	/* wait Busy flag to finish*/
	while(GET_BIT(MSPI1 -> SR ,7)==1);
	
    /* Return to the receive data */
    * Copy_DataToReceive= MSPI1 -> DR;
	
	/* set slave select pin*/
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,GPIO_HIGH);
}

/*void SPI1_IRQHandler(void)
{
	CallBack(MSPI1 -> DR);
}*/
