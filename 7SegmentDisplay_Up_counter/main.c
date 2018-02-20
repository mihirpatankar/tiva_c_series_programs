#include "tm4c123gh6pm.h"
#define RED_LED (0x1U << 1)
#define BLUE_LED (0x1U << 2)
#define GREEN_LED (0x1U << 3)

unsigned int in,out;
unsigned data_7_seg[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0x73};
unsigned int index=0;

void delay(){
  int i=0;  
  for(i=0;i<1000000;++i){
  }
}

void portBInit(){
    SYSCTL_RCGCGPIO_R|=(0x1U<<1);//Enables portB using clock gating register
    GPIO_PORTB_DIR_R |= 0x7F;//all outputs
    GPIO_PORTB_LOCK_R|=0x4C4F434B;//unlocks GPIO CR register
    GPIO_PORTB_CR_R |= 0xFF;//required for PB3-2
    GPIO_PORTB_AMSEL_R &= ~0x7F;//no analog
    GPIO_PORTB_DEN_R |= 0x7F;//enable all pins
}

void portFInit(){
    //Using only PF4-PF0
    SYSCTL_RCGCGPIO_R|=(0x1<<5);//Enables PortF using clock gating register
    GPIO_PORTF_LOCK_R |= 0x4C4F434B;//unlocks GPIO CR register
    GPIO_PORTF_CR_R |= 0xFF;//required for using PF0
    GPIO_PORTF_DIR_R |= 0x0E;//Set direction 1-output, 0-input
    GPIO_PORTF_DEN_R |= 0x1F;//enable PF4-PF0
    GPIO_PORTF_PUR_R |=0x11;//enable pull-up resistors for the onboard switches
}

int main(){
    
    //Call PortD init function
    portBInit();
    
    while(1){
      GPIO_PORTB_DATA_R = data_7_seg[index];
      ++index;
      if(index>9){
        index=0;
      }
      delay();
    }  
    return 0;
}
