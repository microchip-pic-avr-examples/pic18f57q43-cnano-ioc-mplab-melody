<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Interrupt On Change feature of GPIO

This code example demonstrates how to use the Interrupt on change feature of the GPIO module. This code example was created for a Microchip University Class with the name GPIO

## Related Documentation

- [MPLAB Code Configurator](https://www.microchip.com/en-us/development-tools-tools-and-software/embedded-software-center/mplab-code-configurator)
- [PIC18-Q43 Family Product Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic18-q43)
## Software Used

- MPLAB® X IDE 6.0.0 or newer [(MPLAB® X IDE 6.0)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-ioc-mplab-melody-github)
- MPLAB® XC8 2.35.0 or newer compiler [(MPLAB® XC8 2.35)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-ioc-mplab-melody-github)
- MPLAB® Code Configurator (MCC) 5.1.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- MPLAB® Code Configurator (MCC) Melody 2.0.46 or newer [(microchip.com/en-us/tools-resources/configure/mplab-code-configurator/melody)](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator/melody)
- Microchip PIC18F-Q Series Device Support (1.13.211) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/)

## Hardware Used

- [Microchip PIC18F57Q43 Curiosity Nano Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/DM164150)
- [Microchiop Curiosity Nano Base for Click boards](https://www.microchip.com/developmenttools/ProductDetails/AC164162)
- [Breadboard](https://www.mouser.com/ProductDetail/426-FIT0008)
- [Switches](https://www.mouser.com/ProductDetail/506-FSM2JRT)
- [LED](https://www.mouser.com/ProductDetail/941-C5SMFRJECT0W0BB2)
- [Resistor](https://www.mouser.com/ProductDetail/603-CFR-25JB-52-330R)
- [Wire Kit](https://www.mouser.com/ProductDetail/424-WIRE-KIT)

### Hardware User Guide

This example code will show how to setup the microcontroller to interrupt when it sees a change on the specified pin. RF3 will be the indicator for the interrupt and RB4 for the SW0 on the Curiosity nano to change the state of the pin.


In order to configure pin RB4 to generate an interrupt when its state changes, the GPIO must be programmed to enable Interrupt-on-change. Additionally, pin RB4 should be configured such that an Interrupt-on-change is triggered on a negative edge since SW0 is active-low. The image below shows the complete hardware setup needed for all the code examples for the GPIO Class. The only component needed for this code example is the PIC18F57Q43 Curiosity Nano. 

  
<img src="images/gpio_setup.png" width="600"/></a>
## Setup

Attach the PIC18F57Q43 Curiosity Nano to the Curiosity Nano Adapter Board with supplied pins. 
Place the switches in the bread board as shown in the hardware setup figure. Connect one switch to the pin labeled AN2 and the other switch to the pin labeled AN3 on the Curiosity Nano Adapter board. Connect the other pins of both switches to a ground on the Curiosity Nano Adapter board.
There are a few different ways to connect the LED and resistor. The first option is to solder the LED in series with the resistor, and connect it to the input labeled as PWM3 on the Curiosity Nano adapter. The other end should be connected to ground in this option. It is important to ensure the polarity of the LED is correct (anode to the pin and the cathode towards ground). The second option is to place them into the breadboard and connect them in series similar to option one but with jumper wires going to the Curiosity Nano adapter. 
Once this hardware setup has been completed, connect the Curiosity Nano to the PC.

MCC with the Melody library was used to implement this example as shown in the following section.
## Clock Control Configuration
In the *Project Resources* window select "Clock Control" as shown in the figure below.

![Melody - Clock Control](images/ioc_clock_control.png)

After selecting the "Clock Control" option, a window on the right side of the MPLAB-IDE will appear called *Clock Control Easy View*. Use the Dropdown boxes to select HFINTOSC, 4MHz, and divide by 4 as shown in the figure below.

![Melody - Clock Control Easy View](images/ioc_clock_control_easy_view.png)

## Pin Configuration
In the *Pins Grid View* window, find "RB4" which is used as the input pins for SW0. Select this pin by clicking the corresponding padlock symbol as shown in the figure below.

**Pins Grid View**

![Melody - SW0 and LED0 connections](images/ioc_pin_grid_view.png)

## Pin Control Configuration
In the *Project Resources* window selecting the "Pins" option.

![Melody - ](images/ioc_pins.png)

After selecting the "Pins" option, a window on the right side of the MPLAB-IDE will appear called "Pins". Slide the bar on the left side to view more of the window.
De-select the "Analog" checkbox on all pins in this window to disable analog functionality, which is not needed for this example. 

![Melody - De-select analog](images/ioc_deselect_analog.png)

Use the "Custom Name" field to rename pin "RB4" to "SW0" and "RF3" to "LED0". 
Select the "Start High" option for pin RF3 (LED0), so that the LED does not light up until the button has been pushed.

![Melody - Rename inputs and outputs start high for LED0 and Negative edge IOC select](images/ioc_sw0_led0_start_high_led0.png)

## IOC Configuration
In the "Pins" configuration window, open the dropdown menu to select from the Interrupt-on-Change options, and choose "Negative" to enable Interrupt-on-Change on a negative edge for this pin.

![Melody - Negative edge IOC select](images/ioc_negative_edge_selection.png)

In the *Project Resources* window click the "Generate" button.

![Melody - Negative edge IOC select](images/ioc_click_generate.png)



Add the following code snippet to the Interrupt-on-Change interrupt handler for pin RB4 in order to Light LED0 when the interrupt occurs. To do this, open the pins.c source file. The code will go in the function called RB4_DefaultInterruptHandler() right after the commented line that says "add your RB4 interrupt custom code". Inset the function called *LED0_SetLow();* as shown below.

![Melody - add Code to light LED0 when Interrupt occurs](images/ioc_interrupt_code.png)

The next step is to open the main.c source file and to add code to do two things; enable global interrupts and to reset the LED when SW0 goes into its default state.
Copy the function called INTERRUPT_GlobalInterruptEnable(); and paste it into the main.c after SYSTEM_Initialize();

![Melody - Negative edge IOC select](images/ioc_interrupt_enable_copy.png)

In addition to this, also copy the code snippet shown below into the main while(1) loop.


        __delay_ms(2000);
        LED0_SetHigh(); //turn off LED0 to wait for next interrupt

The main.c file should look this this after completing these steps: 
![Melody - paste interrupt enble code into main](images/ioc_main_code_to_reset_led0_white.png)

Click the "Clean and Build" button once the routine has been copied into the main loop.

![Melody - clean and build](images/ioc_click_clean_and_build.png)

Once the project has been successfully built the output window should show the following message:

![Melody - build successful](images/ioc_build_successful.png)

Click the "Program Device" button.

![Melody - click program](images/ioc_click_program.png)

Once the device has been successfully programmed, the output window should show the following message:

![Melody - program successful](images/ioc_program_successful.png)
## Operation

To operate this demo, press the pushbutton named SW0. LED0 should light up for 2 seconds indicating that an interrupt-on-change has occurred (negative edge has been detected) and then the LED should shut off until a negative edge is detected on this pin again. .

<img src="images/ioc_nano_demo.gif" width="600"/></a>

## Summary

The example has shown how Melody can be used to easily configure a pin, using the Interrupt on Change feature of the GPIO module module of the PIC18F57Q43 device. 