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

int main(){
    
    /*Enables port D using clock gating register*/
    SYSCTL_RCGCGPIO_R|=(0x1U<<3);
    GPIO_PORTD_DIR_R |= 0x08;         // PD3 output
    GPIO_PORTD_DIR_R &= ~0x01;        // PD0 input
    //GPIO_PORTD_AFSEL_R &= ~0x09;      // not alternative
    GPIO_PORTD_AMSEL_R &= ~0x09;      // no analog
    //GPIO_PORTD_PCTL_R &= ~0x0000F00F; // bits for PD3, PD0
    GPIO_PORTD_DEN_R |= 0x09;         // enable PD3, PD0
    
    while(1){
        in = (GPIO_PORTD_DATA_R&0x01); // in 0 if not pressed, 1 if pressed
        out = (in^0x01)<<3;   // out 8 if not pressed, 0 if switch pressed
        GPIO_PORTD_DATA_R = out;
    }  
    return 0;
}
