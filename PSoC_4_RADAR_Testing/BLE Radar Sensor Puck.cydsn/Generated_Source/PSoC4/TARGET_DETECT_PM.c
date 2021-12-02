/*******************************************************************************
* File Name: TARGET_DETECT.c  
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
#include "TARGET_DETECT.h"

static TARGET_DETECT_BACKUP_STRUCT  TARGET_DETECT_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: TARGET_DETECT_Sleep
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
*  \snippet TARGET_DETECT_SUT.c usage_TARGET_DETECT_Sleep_Wakeup
*******************************************************************************/
void TARGET_DETECT_Sleep(void)
{
    #if defined(TARGET_DETECT__PC)
        TARGET_DETECT_backup.pcState = TARGET_DETECT_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            TARGET_DETECT_backup.usbState = TARGET_DETECT_CR1_REG;
            TARGET_DETECT_USB_POWER_REG |= TARGET_DETECT_USBIO_ENTER_SLEEP;
            TARGET_DETECT_CR1_REG &= TARGET_DETECT_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(TARGET_DETECT__SIO)
        TARGET_DETECT_backup.sioState = TARGET_DETECT_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        TARGET_DETECT_SIO_REG &= (uint32)(~TARGET_DETECT_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: TARGET_DETECT_Wakeup
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
*  Refer to TARGET_DETECT_Sleep() for an example usage.
*******************************************************************************/
void TARGET_DETECT_Wakeup(void)
{
    #if defined(TARGET_DETECT__PC)
        TARGET_DETECT_PC = TARGET_DETECT_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            TARGET_DETECT_USB_POWER_REG &= TARGET_DETECT_USBIO_EXIT_SLEEP_PH1;
            TARGET_DETECT_CR1_REG = TARGET_DETECT_backup.usbState;
            TARGET_DETECT_USB_POWER_REG &= TARGET_DETECT_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(TARGET_DETECT__SIO)
        TARGET_DETECT_SIO_REG = TARGET_DETECT_backup.sioState;
    #endif
}


/* [] END OF FILE */
