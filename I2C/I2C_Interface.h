/****************************************************************/
/* Author     : Aya Ramzy                                       */
/* Version    : V01                                             */
/* Data       : 1 Sep 2021                                      */
/****************************************************************/

/****************************************************************/
/* guard of file will call one time in .c                       */
/****************************************************************/
#ifndef   DIO_INTERFACE_H
#define   DIO_INTERFACE_H


void MI2C_voidInit(void);
void I2C_voidStart(void);
void I2C_voidStop (void);
void I2C_voidWriteData( u8 Copy_u8Data );
void I2C_voidWriteAddress( u8 Copy_u8Address);
u8 I2C_u8Read(u8 Copy_u8Address);





#endif
