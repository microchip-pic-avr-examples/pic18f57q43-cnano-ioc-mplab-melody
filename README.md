<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Update the title for pic18f57q43-cnano-ioc-mplab-melody here

<!-- This is where the introduction to the example goes, including mentioning the peripherals used -->

## Related Documentation

<!-- Any information about an application note or tech brief can be linked here. Use unbreakable links!
     In addition a link to the device family landing page and relevant peripheral pages as well:
     - [AN3381 - Brushless DC Fan Speed Control Using Temperature Input and Tachometer Feedback](https://microchip.com/00003381/)
     - [PIC18F-Q10 Family Product Page](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family) -->

## Software Used

<!-- All software used in this example must be listed here. Use unbreakable links!
     - MPLAB® X IDE 5.30 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
     - MPLAB® XC8 2.10 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
     - MPLAB® Code Configurator (MCC) 3.95.0 or newer [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
     - Microchip PIC18F-Q Series Device Support (1.4.109) or newer [(packs.download.microchip.com/)](https://packs.download.microchip.com/) -->

- MPLAB® X IDE 6.0.0 or newer [(MPLAB® X IDE 6.0)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-ioc-mplab-melody-github)
- MPLAB® XC8 2.35.0 or newer compiler [(MPLAB® XC8 2.35)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic18f57q43-cnano-ioc-mplab-melody-github)

## Hardware Used

<!-- All hardware used in this example must be listed here. Use unbreakable links!
     - PIC18F47Q10 Curiosity Nano [(DM182029)](https://www.microchip.com/Developmenttools/ProductDetails/DM182029)
     - Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/Developmenttools/ProductDetails/AC164162)
     - POT Click board™ [(MIKROE-3402)](https://www.mikroe.com/pot-click) -->
- [Microchip PIC18F57Q43 Curiosity Nano Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/DM164150)
- [Microchiop Curiosity Nano Base for Click boards](https://www.microchip.com/developmenttools/ProductDetails/AC164162)

### Hardware User Guide

In this project we will read the analog signal from the potentiometer and send it to the PC.


To be able to read the value we would have to configure the Analog Digital Converter (ADC) to read the value from the correct pin.  
When using the *Curiosity Nano Adapter* with the *POT 3 click* in space **1** we can read that Analog 1 - AN1 is connected to PORTA - RA0 on the **PIC18F57Q43**
  
![Nano Adapter](images/nano_adapter.jpg)
## Setup

<!-- Explain how to connect hardware and set up software. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->
MCC with the Melody library was used to implement this example as shown in the following section.
## Clock Control Configuration
In the *Project Resources* window click Clock Control. 

![MCC - Clock Control](images/ioc_clock_control.png)

A window on the right side of the MPLAB-IDE will appear called Clock Control Easy View use the Dropdown boxes to select HFINTOSC, 4MHz, and devide by 4.

![MCC - Clock Control Easy View](images/ioc_clock_control_easy_view.png)

## Pin Configuration
In the *Pins Grid View* find ANx for the input pin to the ADC module. AN1 coming from the Click 1 postition is connected to RA0. selected as an output by clicking the corresponding padlock symbol.

**Pins Grid View**
![MCC - UART3 connections](images/IOC_Pin_grid_view.png)

## Pin Control Configuration
In the *Project Resources* window click Pins. 

![MCC - Clock Control](images/IOC_Pins.png)


A window on the right side of the MPLAB-IDE will appear called pins slide the bar on the left side to view more of the window. 
De-select analog. 

![MCC - De-select analog](images/IOC_deselect_analog.png)

Rename RB4 to SW0 and RF3 to LED0. Start high for LED0 so it doesn't light till the interrupt. 
![MCC - Rename inputs and outputs start high for LED0 and Negative edge IOC select](images/IOC_sw0_led0_start_high_led0.png)
## IOC Configuration
Choose from dropdown arrow Negative Edge for IOC.
![MCC - Negative edge IOC select](images/ioc_negative_edge_selection.png)

In the *Project Resources* window click Generate.
![MCC - Negative edge IOC select](images/IOC_click_generate.png)

Next, copy the global interrupt enable from the interrupt.h file so I can use it in the main.c.
![MCC - Negative edge IOC select](images/ioc_interrupt_enable_copy.png)

Paste into the Main.c after SYSTEM_Initialize();
![MCC - paste interrupt enble code into main](images/ioc_interrupt_enable.png)

Add code to the Interrupt handler in pins.c.
![MCC - paste interrupt enble code into main](images/ioc_interrupt_enable.png)

## Operation

<!-- Explain how to operate the example. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->

## Summary

<!-- Summarize what the example has shown -->
