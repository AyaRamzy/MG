/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 18 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef  SPI_INTERFACE_H
#define  SPI_INTERFACE_H



void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DtaToTransmit,u8 * Copy_DataToReceive);
//void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DtaToTransmit,void (*CallBack)(u8));


#endif
