/*******************************************************************************
* File Name: TC_Interrupt.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_TC_Interrupt_H)
#define CY_ISR_TC_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void TC_Interrupt_Start(void);
void TC_Interrupt_StartEx(cyisraddress address);
void TC_Interrupt_Stop(void);

CY_ISR_PROTO(TC_Interrupt_Interrupt);

void TC_Interrupt_SetVector(cyisraddress address);
cyisraddress TC_Interrupt_GetVector(void);

void TC_Interrupt_SetPriority(uint8 priority);
uint8 TC_Interrupt_GetPriority(void);

void TC_Interrupt_Enable(void);
uint8 TC_Interrupt_GetState(void);
void TC_Interrupt_Disable(void);

void TC_Interrupt_SetPending(void);
void TC_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the TC_Interrupt ISR. */
#define TC_Interrupt_INTC_VECTOR            ((reg32 *) TC_Interrupt__INTC_VECT)

/* Address of the TC_Interrupt ISR priority. */
#define TC_Interrupt_INTC_PRIOR             ((reg32 *) TC_Interrupt__INTC_PRIOR_REG)

/* Priority of the TC_Interrupt interrupt. */
#define TC_Interrupt_INTC_PRIOR_NUMBER      TC_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable TC_Interrupt interrupt. */
#define TC_Interrupt_INTC_SET_EN            ((reg32 *) TC_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the TC_Interrupt interrupt. */
#define TC_Interrupt_INTC_CLR_EN            ((reg32 *) TC_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the TC_Interrupt interrupt state to pending. */
#define TC_Interrupt_INTC_SET_PD            ((reg32 *) TC_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the TC_Interrupt interrupt. */
#define TC_Interrupt_INTC_CLR_PD            ((reg32 *) TC_Interrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_TC_Interrupt_H */


/* [] END OF FILE */
