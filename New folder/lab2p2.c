#include "lab1p1header.h"
#include <stdint.h>
//unsigned long COLOR = 0x2;
int j;
//int stay;


void LED_initALLLL2(void)
{
 RCGCGPIO |= 0x1; // enable Port A GPIO clock
volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x01; // activate clock for Port A//Do I really need this?Ill assume so 
delay = SYSCTL_RCGC2_R; // allow time for clock to start//Do I really need this? 
 GPIO_PORTA_PCTL_R &= ~0x00000F00; // regular GPIO//no idea what this does but i moved the F to the port A spot
 GPIO_PORTA_AMSEL_R &= ~0xF4; // disable analog function of ALL PA Used - 11101100
 GPIO_PORTA_DIR_R |= 0xE0; // set PA7-5 to output 1110000
 GPIO_PORTA_AFSEL_R &= ~0xF4; // regular port function
 GPIO_PORTA_DEN_R |= 0xF4; // enable digital on ALL PA USED
}


void initializelab2p2(){
RCGCTIMER = 0x1;//set timer0 to 1. Enableing the use of the time


GPTMCTL_Timer_0 &= ~0x101;//pauses the timer (both a and b)
GPTMCFG_Timer_0 = 0x0;//sets the 16bit it to 32 bit.

GPTMCAMR_Timer_0 = 0x2;//pet to periodic timer mode - 0x1 = one shot, 0x3 = capture
GPTMCAMR_Timer_0 &= ~0x10;//set timer to count down

GPTMCBMR_Timer_0 = 0x2;//set B to periodic timer mode 
GPTMCBMR_Timer_0 &= ~0x10;//set B timer to count down

GPTMTAILR_Timer_0 = Seconds*5;//countdown to begin at 160000000*5
GPTMTBILR_Timer_0 = Seconds*2;//countdown to begin at 160000000*2

GPTMCTL_Timer_0 |= 0x101;//starts both the timers


}


void lab2p2(){////////////////////////////////////MAIN FOR THE 3RD LAB PART(THE NUMBER is swapped out for use )
  LED_initALLLL2();
  initializelab2p2();
  state = GO;

RCGCGPIO |= PORT_F; // enable Port F GPIO//program doesnt work without it, dont ask me why...
PortF_DIR = 0xE; // set ALL OF PF as output
PortF_DEN = 0xE; // enable digital pin ALL PF 
GPIO_PORTF_DATA_R = COLOR; // set PF1 to 1 and the other port F pins to 0
  

 
while(1){

  if (state == GO){
      GoLED();
      state = STOP;
      while(((GPTMRIS_Timer_0 & 0x1) == 0x0)){
         
         if ((switch_inputPED() == 0x0) && (switch_inputSS() == 0x0)) {///////////////interupt if pedestrian light pressed
          GPTMICR_Timer_0 |= 0x100;//resets timer B
        }
        
        
        if ((switch_inputPED() == 0x1)  && (GPTMRIS_Timer_0 & 0x100 == 0x100)) {///////////////interupt if pedestrian light pressed
          //stay = 0;
          state = WAIT;
          GPTMICR_Timer_0 |= 0x1;//resets A 
          GPTMICR_Timer_0 |= 0x100;//resets B
          break;
        }
        
        if ((switch_inputSS() == 0x1)  && (GPTMRIS_Timer_0 & 0x100 == 0x100)) {///////////////interupt if pedestrian light pressed
          state = OFF;
          GPTMICR_Timer_0 |= 0x1;//resets A 
          GPTMICR_Timer_0 |= 0x100;//resets timer B
          break;
        }
        
        
      }
  GPTMICR_Timer_0 |= 0x1;//resetsA
  }
    
  
  
  if (state == STOP){

    StopLED();
    state = GO;

  while((GPTMRIS_Timer_0 & 0x1) == 0x0){

         if ((switch_inputPED() == 0x0) && (switch_inputSS() == 0x0)) {///////////////interupt if pedestrian light pressed
          GPTMICR_Timer_0 |= 0x100;//resets timer B
        }
        
        
        
        if ((switch_inputSS() == 0x1)  && (GPTMRIS_Timer_0 & 0x100 == 0x100)) {///////////////interupt if pedestrian light pressed
          state = OFF;
          GPTMICR_Timer_0 |= 0x1;//resets A 
          GPTMICR_Timer_0 |= 0x100;//resets timer B
          break;
        }
  }
  GPTMICR_Timer_0 |= 0x1;//resets
  }
  
  
 if (state == WAIT){

          WaitLED();
          state = STOP;
        while((GPTMRIS_Timer_0 & 0x1) == 0x0){
                       if ((switch_inputPED() == 0x0) && (switch_inputSS() == 0x0)) {///////////////interupt if pedestrian light pressed
                GPTMICR_Timer_0 |= 0x100;//resets timer B
              }
              
              
              
              if ((switch_inputSS() == 0x1)  && (GPTMRIS_Timer_0 & 0x100 == 0x100)) {///////////////interupt if pedestrian light pressed
                state = OFF;
                GPTMICR_Timer_0 |= 0x1;//resets A 
                GPTMICR_Timer_0 |= 0x100;//resets timer B
                break;
              }
        }

        GPTMICR_Timer_0 |= 0x1;//resets
  }
  
  if(state == OFF){
    
      OffLED();
      if ( switch_inputSS() == 0) {///////////////interupt if pedestrian light pressed
                GPTMICR_Timer_0 |= 0x1;//resets A 
                GPTMICR_Timer_0 |= 0x100;//resets timer B
      }

      
      if ( (switch_inputSS() == 1) && (GPTMRIS_Timer_0 & 0x100 == 0x100)) {///////////////interupt if pedestrian light pressed
          state = STOP;
          GPTMICR_Timer_0 |= 0x1;//resetsA
          GPTMICR_Timer_0 |= 0x100;//resets timer B... yah i guesss i could do both
        }
    
  }
  
  
  
  
  
  
  
}
  
  
  
  
  
  
  
  
}
 
  

