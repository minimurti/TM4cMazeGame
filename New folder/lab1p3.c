#include "lab1p1header.h"
#include <stdint.h>
int j;

#define GO 0x0
#define WAIT 0x1
#define STOP 0x2
#define OFF 0x3//for the state machine
int state;


void LED_initALLLL(void)
{
// RCGCGPIO = 0x1; // enable Port A GPIO clock
 volatile unsigned long delay;
 SYSCTL_RCGC2_R |= 0x01; // activate clock for Port A//Do I really need this?Ill assume so 
 delay = SYSCTL_RCGC2_R; // allow time for clock to start//Do I really need this? 
 GPIO_PORTA_PCTL_R &= ~0x00000F00; // regular GPIO//no idea what this does but i moved the F to the port A spot
 GPIO_PORTA_AMSEL_R &= ~0xF4; // disable analog function of ALL PA Used - 11101100
 GPIO_PORTA_DIR_R |= 0xE0; // set PA7-5 to output 1110000
 GPIO_PORTA_AFSEL_R &= ~0xF4; // regular port function
 GPIO_PORTA_DEN_R |= 0xF4; // enable digital on ALL PA USED
}



// turn on LED connected to PA7
void LED_onR(void)
{
 GPIO_PORTA_DATA_R |= 0x80;
}
// turn off LED connected to PA7
void LED_offR(void)
{
 GPIO_PORTA_DATA_R &= ~0x80;
}

void LED_onY(void)
{
 GPIO_PORTA_DATA_R |= 0x40;
}
// turn off LED connected to PA6
void LED_offY(void)
{
 GPIO_PORTA_DATA_R &= ~0x40;
}
 // turn on LED connected to PA5
void LED_onG(void)
{
 GPIO_PORTA_DATA_R |= 0x20;
}
// turn off LED connected to PA5
void LED_offG(void)
{
 GPIO_PORTA_DATA_R &= ~0x20;
}


unsigned long switch_inputPED(void)///slight modification of given code that outputs a 1 instead of a specific value
{
if((GPIO_PORTA_DATA_R & 0x10) == 0x10)
  return 0x1;
else
  return 0x0;
  
}

unsigned long switch_inputSS(void)
{
if((GPIO_PORTA_DATA_R & 0x04) == 0x04) // 0x04 (pressed) or 0 (not pressed)
  return 0x1;
else
  return 0x0;
}


void GoLED(){
  LED_onG();
  LED_offY();
  LED_offR();
}

void WaitLED(){
  LED_offG();
  LED_onY();
  LED_offR();
}

void StopLED(){
  LED_offG();
  LED_offY();
  LED_onR();
}

void OffLED(){
  LED_offG();
  LED_offY();
  LED_offR();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lab1p3(){////////////////////////////////////MAIN FOR THE 3RD LAB PART(THE NUMBER is swapped out for use )
  LED_initALLLL();
  state = GO;
  

  while(1){
    if(state == GO){////////////////start
      GoLED();
      state = STOP;
      for (j = 0; j < 500000; j++) {////only 250000 for two ifs 
        
        if (switch_inputPED() == 0x1) {///////////////interupt if pedestrian light pressed
          state = WAIT;
          j = 5000000;
        }
        
        
        if (switch_inputSS() == 0x1){////////////// interupt if OFF light pressed
          state = OFF;
          j = 5000000;
        }
      }
      
      
     }/////////
    
    if(state == WAIT){////////////////wait
      WaitLED();
      state = STOP;
      for (j = 0; j < 500000; j++) {/////////500000 for 1 if
        if (switch_inputSS() == 0x1){
          state = OFF;
          j = 50000000;
        }
      }
   
     }/////////
    if(state == STOP){////////////////STOP

      StopLED();
      state = GO;
      for (j = 0; j < 500000; j++) {/////////500000 for 1 if
        if (switch_inputSS() == 0x1){
          state = OFF;
          j = 50000000;
        }
      }
   
     }/////////
    

            
    if(state == OFF){////////////////OFF no for loop, infinit until switch is pressed
      OffLED();
      if (switch_inputSS() == 0x0){
        state = GO;
      }
    }      


  }
 
  
 // return 0;
}