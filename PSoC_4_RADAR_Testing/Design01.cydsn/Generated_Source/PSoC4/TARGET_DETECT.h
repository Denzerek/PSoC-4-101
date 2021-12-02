/*******************************************************************************
* File Name: TARGET_DETECT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_TARGET_DETECT_H) /* Pins TARGET_DETECT_H */
#define CY_PINS_TARGET_DETECT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TARGET_DETECT_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} TARGET_DETECT_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   TARGET_DETECT_Read(void);
void    TARGET_DETECT_Write(uint8 value);
uint8   TARGET_DETECT_ReadDataReg(void);
#if defined(TARGET_DETECT__PC) || (CY_PSOC4_4200L) 
    void    TARGET_DETECT_SetDriveMode(uint8 mode);
#endif
void    TARGET_DETECT_SetInterruptMode(uint16 position, uint16 mode);
uint8   TARGET_DETECT_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void TARGET_DETECT_Sleep(void); 
void TARGET_DETECT_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(TARGET_DETECT__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define TARGET_DETECT_DRIVE_MODE_BITS        (3)
    #define TARGET_DETECT_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TARGET_DETECT_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the TARGET_DETECT_SetDriveMode() function.
         *  @{
         */
        #define TARGET_DETECT_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define TARGET_DETECT_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define TARGET_DETECT_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define TARGET_DETECT_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define TARGET_DETECT_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define TARGET_DETECT_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define TARGET_DETECT_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define TARGET_DETECT_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define TARGET_DETECT_MASK               TARGET_DETECT__MASK
#define TARGET_DETECT_SHIFT              TARGET_DETECT__SHIFT
#define TARGET_DETECT_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TARGET_DETECT_SetInterruptMode() function.
     *  @{
     */
        #define TARGET_DETECT_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define TARGET_DETECT_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define TARGET_DETECT_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define TARGET_DETECT_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(TARGET_DETECT__SIO)
    #define TARGET_DETECT_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(TARGET_DETECT__PC) && (CY_PSOC4_4200L)
    #define TARGET_DETECT_USBIO_ENABLE               ((uint32)0x80000000u)
    #define TARGET_DETECT_USBIO_DISABLE              ((uint32)(~TARGET_DETECT_USBIO_ENABLE))
    #define TARGET_DETECT_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define TARGET_DETECT_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define TARGET_DETECT_USBIO_ENTER_SLEEP          ((uint32)((1u << TARGET_DETECT_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << TARGET_DETECT_USBIO_SUSPEND_DEL_SHIFT)))
    #define TARGET_DETECT_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << TARGET_DETECT_USBIO_SUSPEND_SHIFT)))
    #define TARGET_DETECT_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << TARGET_DETECT_USBIO_SUSPEND_DEL_SHIFT)))
    #define TARGET_DETECT_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(TARGET_DETECT__PC)
    /* Port Configuration */
    #define TARGET_DETECT_PC                 (* (reg32 *) TARGET_DETECT__PC)
#endif
/* Pin State */
#define TARGET_DETECT_PS                     (* (reg32 *) TARGET_DETECT__PS)
/* Data Register */
#define TARGET_DETECT_DR                     (* (reg32 *) TARGET_DETECT__DR)
/* Input Buffer Disable Override */
#define TARGET_DETECT_INP_DIS                (* (reg32 *) TARGET_DETECT__PC2)

/* Interrupt configuration Registers */
#define TARGET_DETECT_INTCFG                 (* (reg32 *) TARGET_DETECT__INTCFG)
#define TARGET_DETECT_INTSTAT                (* (reg32 *) TARGET_DETECT__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define TARGET_DETECT_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(TARGET_DETECT__SIO)
    #define TARGET_DETECT_SIO_REG            (* (reg32 *) TARGET_DETECT__SIO)
#endif /* (TARGET_DETECT__SIO_CFG) */

/* USBIO registers */
#if !defined(TARGET_DETECT__PC) && (CY_PSOC4_4200L)
    #define TARGET_DETECT_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define TARGET_DETECT_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define TARGET_DETECT_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define TARGET_DETECT_DRIVE_MODE_SHIFT       (0x00u)
#define TARGET_DETECT_DRIVE_MODE_MASK        (0x07u << TARGET_DETECT_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins TARGET_DETECT_H */


/* [] END OF FILE */
