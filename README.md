# Getting the board
The board can be ordered from [TI website](https://store.ti.com/ProductAccessories.aspx?ProductId=4505) or any other third party vendor.

# Software
The software used is [IAR Embedded Work Bench](https://www.iar.com/iar-embedded-workbench/) Code Limited free version. Alternatively, [Code composer studio (CCS)](http://www.ti.com/tool/CCSTUDIO) from Texas Instruments can also be used.

# Useful Links & Tutorials
* [Microcontroller (TM4C123GH6PM) Data Sheet](http://www.ti.com/lit/ds/symlink/tm4c123gh6pm.pdf)
* [Youtube Tutorial 1](https://www.youtube.com/watch?v=qieNBhmWQbA&list=PLmfT_cdP5PYBWYvK_bCdGyBqQEiRzUPeq&index=3)
* [Youtube Tutorial 2](https://www.youtube.com/watch?v=3V9eqvkMzHA&list=PLPW8O6W-1chwyTzI3BHwBLbGQoPFxPAPM)
* [TI Tutorials](http://processors.wiki.ti.com/index.php/Getting_Started_with_the_TIVA%E2%84%A2_C_Series_TM4C123G_LaunchPad)
* [edx UT 6.01x Course](https://courses.edx.org/courses/UTAustinX/UT.6.01x/1T2014/course/)


# TIVA TM4C123GXL Launch Pad Programs

## LED Blink [Video](https://youtu.be/A0ijtlBGvPw)
The onboard LED cycles through R,G and B colors

## Switch + LED [Video1](https://youtu.be/PD2W7jYPpn8) [Video2](https://youtu.be/Izpt-WET_rg)
The two onboard switches are used to light up one of R,G and B LED. The Switch and LED were also connected externally to PortD. The switch was also used to toggle LED.

## 7 Segment Display (5611AS) [Video](https://youtu.be/ZtxzncycSjI)
The program is a simple counter from 0-9 which is displayed on the 7 segment display.

## Timers [Video](https://youtu.be/4cy1UF1q9_c)
The program is used to configure the general purpose timer to be in periodic mode and count 1 second. After completion of 1 second, the state of the LED is toggled. The timeout can be checked by both polling and interrupts. For polling a specific bit in the register is continuously checked, while for interrupt, a custom interrupt handler function is added to take action on timeout.

## ADC [Video](https://youtu.be/aCUaC6itu9I)
This prograrm takes input from a potentiometer. Using the onboard 12-bit ADC the input voltage is converted to digital data from 0-4095. This data is then mapped onto 5 LEDs.
