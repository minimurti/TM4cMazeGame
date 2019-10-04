#include "lab1p1header.h"
#include <stdint.h>
unsigned long COLOR = 0x2;
int j;
void lab1p1()///////////////////////////////////////////////////LAB PART ONE
{

RCGCGPIO = PORT_F; // enable Port F GPIO
PortF_DIR = 0xE; // set ALL OF PF as output
PortF_DEN = 0xE; // enable digital pin ALL PF 
GPIO_PORTF_DATA_R = COLOR; // set PF1 to 1 and the other port F pins to 0

 while(1)
 {
  if(COLOR<0xE)//I figured the pins next to it were the other lights, turns out my lucky guess of left shifting was right, 
     COLOR++;//counting from 0010 to 1110 should cover all the values
  else
    COLOR=0x2;//then reset after 111
  
  GPIO_PORTF_DATA_R = COLOR;
   
  for (j = 0; j < 1000000; j++) {}//delay

 }

// return 0;
}
