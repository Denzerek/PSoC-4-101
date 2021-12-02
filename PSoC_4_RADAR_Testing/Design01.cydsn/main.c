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

//#define serialDebug  UART_UartPutString
#define serialDebug  
#define serialMain  UART_UartPutString

#define ENABLE_PHASE_SIMULATION


volatile static uint8_t phaseState;


CY_ISR(phaseDetect_interruptHandler)
{
   serialDebug("INTERRUPT Phase Interrupt \r\n");
    
    #ifdef ENABLE_PHASE_SIMULATION
    if(!PHASE_DETECT_Read())
    #else
    if(PHASE_DETECT_Read())
    #endif
    {
        serialDebug("INTERRUPT PHASE DETECT HIGH \r\n");
        phaseState = 1;
    }
    else
    { 
        serialDebug("INTERRUPT PHASE DETECT LOW \r\n");
        phaseState = 1;
    }
    PHASE_DETECT_ClearInterrupt();
}

CY_ISR(Timer_interruptHandler)
{
    serialDebug("INTERRUPT Timer Terminal count \r\n");
    TCPWM_1_ClearInterrupt(TCPWM_1_INTR_MASK_TC);
}

int main (void)
{
    UART_Start();
    serialDebug("\r\n GPIO Pin Testing \r\n");
    
    PHASE_DETECT_INT_StartEx(phaseDetect_interruptHandler);
    TCPWM_1_Start();
    
    timerInt_StartEx(Timer_interruptHandler);
    
    LED_1_Write(1);
    
    CyGlobalIntEnable;  /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        
        serialDebug("Entering Deep Sleep\r\n\n");
        CyDelay(10);
        CySysPmDeepSleep();
        serialDebug("Exiting Deep Sleep\r\n");
        
        if(!PHASE_DETECT_Read())
        {
            if(TARGET_DETECT_Read())
            {
                serialMain("TARGET Invalid \r\n");
            }
            else
            { 
                serialMain("TARGET APPROACHING \r\n");
            }
        }
        else
        {
            if(TARGET_DETECT_Read())
            {
                serialMain("TARGET Invalid \r\n");
            }
            else
            { 
                serialMain("TARGET DEPARTING \r\n");
            }
        }
        CyDelay(10);
        
        
    }
}

/* [] END OF FILE */
