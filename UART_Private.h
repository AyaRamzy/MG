/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 22 AUG 2020                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H

typedef struct 
{
	volatile u32  SR;
	volatile u32  DR;
	volatile u32  BRR;
	volatile u32  CR1;
	volatile u32  CR2;
	volatile u32  CR3;
	volatile u32  GRPR;
	
}MUART_Type;

#define  MUSART1    ((volatile MUART_Type*)0x40013800)



#endif