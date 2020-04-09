/*
 * ADC_prog.c
 *
 *  Created on: Apr 7, 2020
 *      Author: hp
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
//#include "../LIBRARY/AVR_REG.h"

#include "ADC_priv.h"
#include "ADC_config.h"
#include "GIE_priv.h"
#include <util/delay.h>

void (*ADC_PF_CallBack) (void*) = NULL;
void* ADC_PvoidParameter = NULL ;

/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuInit.                                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting prescaler , adjustment and reference voltage. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuInit 				(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;
	ADMUX=0;
	ADCSRA=0;

#if	  PRESCALER == PRE_TWO
	PRESCALER_TWO;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_FOUR
	PRESCALER_FOUR;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_EIGHT
	PRESCALER_EIGHT;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_SIXTEEN
	PRESCALER_SIXTEEN;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_THIRTY_TWO
	PRESCALER_THIRTY_TWO;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_SIXTY_FOUR
	PRESCALER_SIXTY_FOUR;
	error_enuState =ES_OK;

#elif PRESCALER == PRE_HUNDRED_TWENTY_EIGHT
	PRESCALER_HUNDRED_TWENTY_EIGHT;
	error_enuState =ES_OK;

#else
#error"Attention!!, your prescaler is wrong..."
#endif

#if	ADJUSTMENT == RIGHT_ADJ
	RIGHT_ADJUSTMENT;
	error_enuState =ES_OK;

#elif	ADJUSTMENT == LEFT_ADJ
	LEFT_ADJUSTMENT;
	error_enuState =ES_OK;

#else
#error"Attention!!, your adjustment is wrong..."

#endif

#if V_REF == A_REF
	AREF_VOLTAGE;
	error_enuState =ES_OK;

#elif V_REF == A_VCC
	AVCC_VOLTAGE;
	error_enuState =ES_OK;

#elif V_REF == INTERNAL_REF
	INTERNAL_VOLTAGE;
	error_enuState =ES_OK;

#else
#error"Attention!!, your reference voltage is wrong..."

#endif

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuEnable.                                        **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the ADC peripheral.                          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuEnable				(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	ENABLE_ADC;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuDisable.                                       **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling the ADC peripheral.                         **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuDisable 			(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	DISABLE_ADC;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuEnableTrigger.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the ADC Trigger.                             **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuEnableTrigger 		(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	ENABLE_TRIGGER;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuDisableTrigger.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling the ADC Trigger.                            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuDisableTrigger 		(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	DISABLE_TRIGGER;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuEnableInterrupt.                               **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the ADC Interrupt.                           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuEnableInterrupt 	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	ENABLE_INTERRUPT;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuDisableInterrupt.                              **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling the ADC Interrupt.                          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuDisableInterrupt 	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	DISABLE_INTERRUPT;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuStartConversion.                               **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Starting of ADC Conversion.                           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuStartConversion	 	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	START_CONVERSION;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuPollingOnFlag.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Polling on rising ADC flag, then clear it.            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuPollingOnFlag	 	(void)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	while(FLAG_RISING);
	CLEAR_FLAG;
	error_enuState =ES_OK;

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuSelectChannel.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Number of ADC Channel.                                **/
/**	Functionality   : Selecting of ADC Channel.                             **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuSelectChannel 		(u8 Copy_u8Channel)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	if (Copy_u8Channel <= CHN_7)
	{
		ADMUX|=Copy_u8Channel;
		error_enuState =ES_OK;
	}
	else
	{
		error_enuState =ES_OUT_OF_RANGE;
	}

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuReadHighRegister.                              **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Address of Variable which will Carry ADC Value.       **/
/**	Functionality   : Reading the highest 8 bit of ADC resolution register. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuReadHighRegister	(u8 * Copy_Pu8ADC_Value)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

#if	ADJUSTMENT == RIGHT_ADJ
	*Copy_Pu8ADC_Value=ADCL>>2;
	*Copy_Pu8ADC_Value|=ADCH<<6;
	error_enuState =ES_OK;

#elif	ADJUSTMENT == LEFT_ADJ
	*Copy_Pu8ADC_Value=ADCH;
	error_enuState =ES_OK;

#else
#error"Attention!!, your adjustment is wrong..."

#endif
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuReadADC.                                       **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Address of Variable which will Carry ADC Value.       **/
/**	Functionality   : Reading All ADC resolution register.                  **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuReadADC				(u16 * Copy_Pu16ADC_Value)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

#if	ADJUSTMENT == RIGHT_ADJ
	*Copy_Pu16ADC_Value = ADC;
	error_enuState =ES_OK;

#elif	ADJUSTMENT == LEFT_ADJ
	*Copy_Pu16ADC_Value=ADC>>6;
	error_enuState =ES_OK;

#else
#error"Attention!!, your adjustment is wrong..."

#endif
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuCallBackFunction.                              **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : ptr to a void func having generic ptr & this generic. **/
/**	Functionality   : Starting of ADC Conversion.                           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES ADC_enuCallBackFunction 	( void (*Copy_PF_CallBack)(void*)  , void* Copy_PvoidParameter)
{
	ERROR_STATES error_enuState =ES_NOT_OK;

	if (ADC_PF_CallBack == NULL)
	{
		ADC_PF_CallBack = Copy_PF_CallBack;
		if (Copy_PvoidParameter == NULL)
			ADC_PvoidParameter = Copy_PvoidParameter;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ISR (__vector_16).                                    **/
/**	Return Type     : void.                                                 **/
/**	Arguments       : Number of interrupt vector.                           **/
/**	Functionality   : Handling of ADC Interrupt.                            **/
/*****************************************************************************/
/*****************************************************************************/
ISR (__vector_16)
{
	if (ADC_PF_CallBack  != NULL)
	{
		ADC_PF_CallBack(ADC_PvoidParameter);
	}
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
