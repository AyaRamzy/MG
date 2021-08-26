/*********************************************************************************/
/****************************** Author    : Aya Ramzy    *************************/
/****************************** Version   : V01          *************************/
/****************************** Date      : 8 August 2020 ************************/
/*********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definitions */

#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)


/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/*PLL Muliplication factor */
#define PLL_INPUT_CLOCK_MUL_2     0 //PLL input clock * 2
#define PLL_INPUT_CLOCK_MUL_3     1 //PLL input clock * 3
#define PLL_INPUT_CLOCK_MUL_4     2 //PLL input clock * 4
#define PLL_INPUT_CLOCK_MUL_5     3 //PLL input clock * 5
#define PLL_INPUT_CLOCK_MUL_6     4 //PLL input clock * 6
#define PLL_INPUT_CLOCK_MUL_7     5 //PLL input clock * 7
#define PLL_INPUT_CLOCK_MUL_8     6 //PLL input clock * 8
#define PLL_INPUT_CLOCK_MUL_9     7 //PLL input clock * 9
#define PLL_INPUT_CLOCK_MUL_10    8 //PLL input clock * 10
#define PLL_INPUT_CLOCK_MUL_11    9 //PLL input clock * 11
#define PLL_INPUT_CLOCK_MUL_12    10//PLL input clock * 12
#define PLL_INPUT_CLOCK_MUL_13    11//PLL input clock * 13
#define PLL_INPUT_CLOCK_MUL_14    12//PLL input clock * 14
#define PLL_INPUT_CLOCK_MUL_15    13//PLL input clock * 15
#define PLL_INPUT_CLOCK_MUL_16    14//PLL input clock * 16











#endif
