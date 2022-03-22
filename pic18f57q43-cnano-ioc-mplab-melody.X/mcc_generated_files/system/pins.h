/**
  Generated Pins header File

  Company:
    Microchip Technology Inc.

  File Name:
    pins.h

  Summary:
    This is generated driver header for pins. 

  Description:
    This header file provides APIs for all pins selected in the GUI.

  Generation Information:
    Driver Version:  3.0.0

*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB4 aliases
#define SW0_TRIS                 TRISBbits.TRISB4
#define SW0_LAT                  LATBbits.LATB4
#define SW0_PORT                 PORTBbits.RB4
#define SW0_WPU                  WPUBbits.WPUB4
#define SW0_OD                   ODCONBbits.ODCB4
#define SW0_ANS                  ANSELBbits.ANSELB4
#define SW0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW0_GetValue()           PORTBbits.RB4
#define SW0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RF3 aliases
#define LED0_TRIS                 TRISFbits.TRISF3
#define LED0_LAT                  LATFbits.LATF3
#define LED0_PORT                 PORTFbits.RF3
#define LED0_WPU                  WPUFbits.WPUF3
#define LED0_OD                   ODCONFbits.ODCF3
#define LED0_ANS                  ANSELFbits.ANSELF3
#define LED0_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define LED0_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define LED0_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define LED0_GetValue()           PORTFbits.RF3
#define LED0_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define LED0_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the RB4 pin functionality
 * @Example
    RB4_ISR();
 */
void RB4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for RB4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for RB4 at application runtime
    
  @Preconditions
    Pins intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    RB4_SetInterruptHandler(MyInterruptHandler);

*/
void RB4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for RB4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the RB4_SetInterruptHandler() method.
    This handler is called every time the RB4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pins intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    RB4_SetInterruptHandler(RB4_InterruptHandler);

*/
extern void (*RB4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for RB4 pin

  @Description
    This is a predefined interrupt handler to be used together with the RB4_SetInterruptHandler() method.
    This handler is called every time the RB4 ISR is executed. 
    
  @Preconditions
    Pins intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    RB4_SetInterruptHandler(RB4_DefaultInterruptHandler);

*/
void RB4_DefaultInterruptHandler(void);




#endif // PINS_H
/**
 End of File
*/