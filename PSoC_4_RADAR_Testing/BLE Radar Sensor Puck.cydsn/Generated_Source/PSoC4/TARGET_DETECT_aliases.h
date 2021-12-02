/*******************************************************************************
* File Name: TARGET_DETECT.h  
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

#if !defined(CY_PINS_TARGET_DETECT_ALIASES_H) /* Pins TARGET_DETECT_ALIASES_H */
#define CY_PINS_TARGET_DETECT_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define TARGET_DETECT_0			(TARGET_DETECT__0__PC)
#define TARGET_DETECT_0_PS		(TARGET_DETECT__0__PS)
#define TARGET_DETECT_0_PC		(TARGET_DETECT__0__PC)
#define TARGET_DETECT_0_DR		(TARGET_DETECT__0__DR)
#define TARGET_DETECT_0_SHIFT	(TARGET_DETECT__0__SHIFT)
#define TARGET_DETECT_0_INTR	((uint16)((uint16)0x0003u << (TARGET_DETECT__0__SHIFT*2u)))

#define TARGET_DETECT_INTR_ALL	 ((uint16)(TARGET_DETECT_0_INTR))


#endif /* End Pins TARGET_DETECT_ALIASES_H */


/* [] END OF FILE */
