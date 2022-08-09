/****************************************************************/
/* Author     : Aya Ramzy                                       */
/* Version    : V01                                             */
/* Data       : 1 Sep 2021                                      */
/****************************************************************/

/****************************************************************/
/* guard of file will call one time in .c                       */
/****************************************************************/
#ifndef   DIO_PRIVATE_H
#define   DIO_PRIVATE_H

typedef  struct
{
	volatile u32 CR1    ;
    volatile u32 CR2    ;
    volatile u32 OAR1   ;
    volatile u32 OAR2   ;
    volatile u32 DR     ;
    volatile u32 SR1    ;
    volatile u32 SR2    ;
    volatile u32 CCR    ;
    volatile u32 TRISE  ;
	
}MI2C1;

#define  MI2C     ((volatile MI2C1*)(0x40005400))

/* BITS of CR1 Register */
#define  CR1_SWRST        15
#define  CR1_ACK          10
#define  CR1_STOP         9
#define  CR1_START        8
#define  CR1_NOSTRETCH    7
#define  CR1_ENGC         6
#define  CR1_PE           0

/* BITS of CR2 Register */
#define  CR2_FREQ0        0
#define  CR2_FREQ1        1
#define  CR2_FREQ2        2
#define  CR2_FREQ3        3
#define  CR2_FREQ4        4
#define  CR2_FREQ5        5

/* BITS of CCR Register */
#define  CCR_FS_MODE      15
#define  CCR_DUTY         14

/* BITS of SR1 Register */
#define  SR1_SB           0
#define  SR1_TxE          7
#define  SR1_BTF          2
#define  SR1_ADDR         1
#define  SR1_RxNE         6

#endif
