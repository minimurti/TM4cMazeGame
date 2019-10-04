#include "lab1p1header.h"
#include <stdint.h>

void lab1p2()////////////////////////////////////////////////////LAB PART TWO
{

RCGCGPIO = PORT_F; // enable Port F GPIO
PortF_DIR = 0xE; // set PF1,2,3 as output
PortF_DEN = 0xFF; // enable digital pin PF1-F5
GPIO_PORTF_DATA_R = 0x0; // set PF1 to 1 and the other port F pins to 0
GPIO_LOCK = 0x4C4F434B;
GPIO_CMT=0xFF;
GPIO_PUR=0x11;

 while(1)
 {
 GPIO_PORTF_DATA_R = 0x0;
   switch(GPIO_PORTF_DATA_R & 0x11){//////Look at the last bits
   case 0x01:
      GPIO_PORTF_DATA_R |= 0x2;///if button1 go green...or red... whichever it is
      break;
   case 0x10:
      GPIO_PORTF_DATA_R |= 0x8;///other button do other color
      break;
   default:
      break;
    
        
      
   }
 }

 //return 0;
}