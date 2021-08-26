/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 18 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef  SPI_PRIVATE_H
#define  SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 CRCPR   ;
	volatile u32 RXCRCR  ;
	volatile u32 TXCRCR  ; 
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR   ;
	
}SPI_Register;

#define MSPI1  ((SPI_Register *)0x40013000)

/* Bits of CR register */
#define CR1_CPHA        0
#define CR1_CPOL        1
#define CR1_MSTR        2
#define CR1_BR0         3
#define CR1_BR1         4
#define CR1_BR2         5
#define CR1_SPE         6
#define CR1_LSB_FIRST   7
#define CR1_SSI         8
#define CR1_SSM         9
#define CR1_RX_ONLY     10
#define CR1_DFF         11
#define CR1_CRC_NEXT    12
#define CR1_CRC_EN      13
#define CR1_BIDI_OE     14
#define CR1_BIDI_MODE   15

/* Bits of SR register */
#define SR_BSY          7
#define SR_MODE         5
#define SR_UDR          3
#define SR_TXE          1
#define SR_RXNE         0


#endif
