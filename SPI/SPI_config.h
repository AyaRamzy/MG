/******************************************************/
/* Author    : Aya Ramzy                              */
/* Date      : 18 OCT 2020                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef  SPI_CONFIG_H
#define  SPI_CONFIG_H

/* Write it in apair port , pin*/
#define  MSPI1_SLAVE_PIN    GPIOA,0

/*******************************************/
/* Options of clock polarity
 * 1- HIGH , Leading edge : Falling edge 
 * 2- LOW  , Leading edge : Raising edge 
 */
#define  CLOCK_POLARITY     HIGH

/*******************************************/
/* Options of clock phase 
 * 1- HIGH , Leading edge : Write 
 * 2- LOW  , Leading edge : Read
 */
#define  CLOCK_PHASE        HIGH

/*******************************************/
/* Data Frame format 
 * Options :
 * 1- EIGHT_BITS
 * 2- SIXTEEN_BITS
 */
#define  DATA_FRAME_FORMAT  EIGHT_BITS

/*******************************************/
/* Slave Select Mode */
/* Options :
 * 1- HIGH  : it will be mamange by Software
 * 2- LOW   : it will be manage  by Hardware 
 */
#define  SLAVE_SELECT_MODE  HIGH
#if    SLAVE_SELECT_MODE == HIGH
/* Optins of SSI when SSM is HIGH 
 * HIGH : Master Selected
 * LOW  : Slave Selected
 */
   #define   SSI    HIGH
#endif

/*******************************************/
/* Optins of LSB or MSB 
 * LOW  : MSB TANSMIT FIRST
 * HIGH : LSB TRANSMIT FIRST
 */
#define  LSB_MSB    LOW

/*******************************************/
/* Optins of Broad Rate
 * Frq divided on 2,4,8,16,32,64,128 or 256
 */
#define  BOAD_RATE   FCLK_DIVIDED_2  

/*******************************************/
/* Optins of MASTER or SLAVE 
 * 1- HIGH : MASTRE 
 * 2- LOW  : SLAVE 
 */
#define  MASTER_OR_SLAVE   HIGH  

/*******************************************/
/* choose FULL DUPLEX OR HALF DUPLEX 
 * 1- HALF_DUPLEX
 * 2- FULL_DUPLEX 
 */
 
#define  DATA_DIRECTION  FULL_DUPLEX

#endif
