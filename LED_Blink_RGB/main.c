#include "tm4c123gh6pm.h"
#define RED_LED (0x1U << 1)
#define BLUE_LED (0x1U << 2)
#define GREEN_LED (0x1U << 3)

unsigned int in,out;

void delay(){
  int i=0;  
  for(i=0;i<1000000;++i){
  }
}

void portFInit(){
    SYSCTL_RCGCGPIO_R|=(0x1<<5);//Enables PortF using clock gating register
    GPIO_PORTF_LOCK_R |= 0x4C4F434B;//unlocks GPIO CR register
    GPIO_PORTF_CR_R |= 0xFF;//required for using PF0
    GPIO_PORTF_DIR_R |= 0x0E;//Set direction 1-output, 0-input
    GPIO_PORTF_DEN_R |= 0x1F;//enable PF4-PF0
    GPIO_PORTF_PUR_R |=0x11//enable pull-up resistors for the onboard switches
}
int main(){
    
    //Call PortF init function
    portFInit();
    
    while(1){
        GPIO_PORTF_DATA_R=RED_LED;
        delay();
        GPIO_PORTF_DATA_R=GREEN_LED;
        delay();
        GPIO_PORTF_DATA_R=BLUE_LED;
        delay();
    }  
    return 0;
}
