#include "lab1p1header.h"
//#include "lab2p1.c"

#include <stdint.h>

//unsigned long COLOR = 0x2;
//int j;
//int stay;



void initializelab2p3(){
RCGCTIMER = 0x1;//set timer0 to 1. Enableing the use of the time
GPTMCTL_Timer_0 &= ~0x1;//pauses the timer
GPTMCFG_Timer_0 = 0x0;//sets the 16bit it to 32 bit.
GPTMCAMR_Timer_0 = 0x2;//pet to periodic timer mode - 0x1 = one shot, 0x3 = capture
GPTMCAMR_Timer_0 &= ~0x10;//set timer to count down
GPTMTAILR_Timer_0 = Seconds;//countdown to begin at 160000000


GPTMIMR_Timer_0 |= 0x1;//enable interupt A
En0 |= 0x80000;


GPTMCTL_Timer_0 |= 0x1;//starts the timer

RCGCGPIO = PORT_F; // enable Port F GPIO
PortF_DIR = 0xE; // set ALL OF PF as output
PortF_DEN = 0xE; // enable digital pin ALL PF 
GPIO_PORTF_DATA_R = COLOR; // set PF1 to 1 and the other port F pins to 0

}


//////////////////////////////////////////////this needs to be commented out for the other labs to workd
// void Timer_Handler( void ){
//  
//   
////   int i;
//   
//   
//   
//  if(COLOR<0xE)//I figured the pins next to it were the other lights, turns out my lucky guess of left shifting was right, 
//     COLOR += 0x2;//counting from 0010 to 1110 should cover all the values
//  else
//    COLOR=0x2;//then reset after 111
//  
//  GPIO_PORTF_DATA_R = COLOR;
//  GPTMICR_Timer_0 |= 0x1;///reset the timer
//  
//  }


void lab2p3(){

  initializelab2p3();
  COLOR=0x2;
  
  GPIO_PORTF_DATA_R = COLOR;
  
  while(1)
  {
    ///do nothing,
    // dont worry you still have value
  }
    
  
  

  
}