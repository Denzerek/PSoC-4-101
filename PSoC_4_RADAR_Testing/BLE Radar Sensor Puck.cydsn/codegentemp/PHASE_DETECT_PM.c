/*******************************************************************************
* File Name: PHASE_DETECT.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PHASE_DETECT.h"

static PHASE_DETECT_BACKUP_STRUCT  PHASE_DETECT_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PHASE_DETECT_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet PHASE_DETECT_SUT.c usage_PHASE_DETECT_Sleep_Wakeup
*******************************************************************************/
void PHASE_DETECT_Sleep(void)
{
    #if defined(PHASE_DETECT__PC)
        PHASE_DETECT_backup.pcState = PHASE_DETECT_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PHASE_DETECT_backup.usbState = PHASE_DETECT_CR1_REG;
            PHASE_DETECT_USB_POWER_REG |= PHASE_DETECT_USBIO_ENTER_SLEEP;
            PHASE_DETECT_CR1_REG &= PHASE_DETECT_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PHASE_DETECT__SIO)
        PHASE_DETECT_backup.sioState = PHASE_DETECT_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PHASE_DETECT_SIO_REG &= (uint32)(~PHASE_DETECT_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PHASE_DETECT_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to PHASE_DETECT_Sleep() for an example usage.
*******************************************************************************/
void PHASE_DETECT_Wakeup(void)
{
    #if defined(PHASE_DETECT__PC)
        PHASE_DETECT_PC = PHASE_DETECT_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PHASE_DETECT_USB_POWER_REG &= PHASE_DETECT_USBIO_EXIT_SLEEP_PH1;
            PHASE_DETECT_CR1_REG = PHASE_DETECT_backup.usbState;
            PHASE_DETECT_USB_POWER_REG &= PHASE_DETECT_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PHASE_DETECT__SIO)
        PHASE_DETECT_SIO_REG = PHASE_DETECT_backup.sioState;
    #endif
}


/* [] END OF FILE */
