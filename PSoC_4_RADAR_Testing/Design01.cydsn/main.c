/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>


CY_ISR(phaseDetect_interruptHandler)
{
   UART_UartPutString("INTERRUPT Phase Interrupt \r\n");
        if(TARGET_DETECT_Read())
        {
            UART_UartPutString("INTERRUPT TARGET DETECT HIGH \r\n");
            LED_1_Write(1); 
        }
        else
        {
            UART_UartPutString("INTERRUPT TARGET DETECT LOW \r\n");
            LED_1_Write(0);
        }
    PHASE_DETECT_ClearInterrupt();
}

CY_ISR(Timer_interruptHandler)
{
    UART_UartPutString("INTERRUPT Timer Terminal count \r\n");
    TCPWM_1_ClearInterrupt(TCPWM_1_INTR_MASK_TC);
}

int main (void)
{
    UART_Start();
    UART_UartPutString("\r\n GPIO Pin Testing \r\n");
    
    PHASE_DETECT_INT_StartEx(phaseDetect_interruptHandler);
    TCPWM_1_Start();
    
    timerInt_StartEx(Timer_interruptHandler);
    
    LED_1_Write(1);
    
    CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        
        UART_UartPutString("Entering Deep Sleep\r\n");
        CyDelay(10);
        CySysPmDeepSleep();
        UART_UartPutString("Exiting Deep Sleep\r\n");
        CyDelay(10);
        
        
    }
}

/* [] END OF FILE */
