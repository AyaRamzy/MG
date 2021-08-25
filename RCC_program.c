/*********************************************************************************/
/* Author    : Aya Ramzy                                                         */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;
		
	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;
	
	/* Check PLL input */
	#elif	RCC_CLOCK_TYPE == RCC_PLL

		#if	RCC_PLL_INPUT == RCC_PLL_HSI_DIV2
			RCC_CFGR = 0X00000002;
		#elif  RCC_PLL_INPUT == RCC_PLL_HSE_DIV2
			RCC_CFGR = 0X00030002;
		#elif  RCC_PLL_INPUT == RCC_PLL_HSE
			RCC_CFGR = 0X00010002;
		
	    #endif
		 /* Muliple value */
		
	    RCC_CFGR |= (RCC_PLL_MUL_VAL << 18);
	    RCC_CR   |= 0X01000000;    //NEEDS COMPLETION
	#else
		#error ("You chose an invalid clock type")
	
	#endif
	
	
	
	/*Enable PLL */
	#if	RCC_PLL_INPUT == RCC_PLL_HSI_DIV2
		RCC_CR = 0X01000081;
	#elif  RCC_PLL_INPUT == RCC_PLL_HSE_DIV2
		RCC_CR = 0X01010000;
	#elif  RCC_PLL_INPUT == RCC_PLL_HSE
		RCC_CR = 0X01010000;
	
	#endif
}



void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
			/*Some compiler not support empty default */
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR  ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}

