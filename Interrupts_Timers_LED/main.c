#include "tm4c123gh6pm.h"
#define RED_LED (0x1U << 1)
#define BLUE_LED (0x1U << 2)
#define GREEN_LED (0x1U << 3)

unsigned int in,out;

void Timer0A_Handler( void ){
        TIMER0_ICR_R |=0x01;
        //toggles the led
        GPIO_PORTF_DATA_R^=0x02;
}

void delay(){
  int i=0;  
  for(i=0;i<1000000;++i){
  }
}
void timer0Init(){
//INIT : To use a GPTM, the appropriate TIMERn bit must be set in the RCGCTIMER or RCGCWTIMER register
    SYSCTL_RCGCTIMER_R |= (1<<0);
    /*1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
any changes.*/
    TIMER0_CTL_R &= ~(1<<0);
    /*2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.
*/
    TIMER0_CFG_R = 0x00000000;
    /*3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR)
    Write a value of 0x2 for Periodic mode.*/
    TIMER0_TAMR_R |= 0x2;
    /*4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
to select whether to capture the value of the free-running timer at time-out, use an external
trigger to start counting, configure an additional trigger or interrupt, and count up or down.*/
    TIMER0_TAMR_R &= ~(1<<4);
    /*5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).*/
    TIMER0_TAILR_R = 0x01F84800;//16 million cycles (which is 1s since the clock frequency is 16MHz)
    /*6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
(GPTMIMR).*/
      TIMER0_IMR_R |= (1<<0);
      NVIC_EN0_R |= (1<<19);
    /*7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.*/
    TIMER0_CTL_R |= (1<<0);
}
void portFInit(){
    SYSCTL_RCGCGPIO_R|=(0x1<<5);//Enables PortF using clock gating register
    GPIO_PORTF_LOCK_R |= 0x4C4F434B;//unlocks GPIO CR register
    GPIO_PORTF_CR_R |= 0xFF;//required for using PF0
    GPIO_PORTF_DIR_R |= 0x0E;//Set direction 1-output, 0-input
    GPIO_PORTF_DEN_R |= 0x1F;//enable PF4-PF0
    GPIO_PORTF_PUR_R |=0x11;//enable pull-up resistors for the onboard switches
}

int main(){
    
    //Call PortF init function
    portFInit();
    //Timer Init function
    timer0Init();
    //Clear all outputs
    GPIO_PORTF_DATA_R=0x00;
    while(1){
      
    }  
    return 0;
}
