/*******************************************************************************
* File Name: LED_SLEEP_BLUE.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_SLEEP_BLUE_ALIASES_H) /* Pins LED_SLEEP_BLUE_ALIASES_H */
#define CY_PINS_LED_SLEEP_BLUE_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LED_SLEEP_BLUE_0			(LED_SLEEP_BLUE__0__PC)
#define LED_SLEEP_BLUE_0_PS		(LED_SLEEP_BLUE__0__PS)
#define LED_SLEEP_BLUE_0_PC		(LED_SLEEP_BLUE__0__PC)
#define LED_SLEEP_BLUE_0_DR		(LED_SLEEP_BLUE__0__DR)
#define LED_SLEEP_BLUE_0_SHIFT	(LED_SLEEP_BLUE__0__SHIFT)
#define LED_SLEEP_BLUE_0_INTR	((uint16)((uint16)0x0003u << (LED_SLEEP_BLUE__0__SHIFT*2u)))

#define LED_SLEEP_BLUE_INTR_ALL	 ((uint16)(LED_SLEEP_BLUE_0_INTR))


#endif /* End Pins LED_SLEEP_BLUE_ALIASES_H */


/* [] END OF FILE */
