void lab2p4();

void initializelab2p4(){
RCGCTIMER = 0x1;//set timer0 to 1. Enableing the use of the time
GPTMCTL_Timer_0 &= ~0x1;//pauses the timer
GPTMCFG_Timer_0 = 0x0;//sets the 16bit it to 32 bit.
GPTMCAMR_Timer_0 = 0x2;//pet to periodic timer mode - 0x1 = one shot, 0x3 = capture
GPTMCAMR_Timer_0 &= ~0x10;//set timer to count down
GPTMTAILR_Timer_0 = Seconds;//countdown to begin at 160000000


RCGCGPIO = PORT_F; // enable Port F GPIO
PortF_DIR = 0xE; // set PF1,2,3 as output
PortF_DEN = 0xFF; // enable digital pin PF1-F5
//GPIO_PORTF_DATA_R = 0x0; // set PF1 to 1 and the other port F pins to 0
GPIO_LOCK = 0x4C4F434B;
GPIO_CMT=0xFF;
GPIO_PUR=0x11;



GPTMIMR_Timer_0 |= 0x1;//enable interupt A
En0 |= 0x80000;

En0 |= 0x40000000;///new enable PortF Interupt
GPIOM_Port_F = 0x11;  //enable SWITCH 0,4 interup

//GPIOM_Port_F = hello;
GPTMCTL_Timer_0 |= 0x1;//starts the timer



}



//
//////////////////////////////////////////////this needs to be commented out for the other labs to workd
// void Timer_Handler( void ){
//  
//     GPIO_PORTF_DATA_R ^= 0x4;
//  while((GPTMRIS_Timer_0 & 0x1) == 0x0){
//   //do nothing but wait... 
//  }
//  
//  GPTMICR_Timer_0 |= 0x1;
//  
//  //GPTMTAILR_Timer_0 = 0xF42400;//reloads countdown to begin at 160000000
//
//  
//  }



void PortF_Handler (void ){
  
  switch(GPIO_PORTF_DATA_R & 0x11){//////Look at the last bits
  case 0x01:
      GPIO_PORTF_DATA_R = 0x4;///if button1 go green...or red... whichever it is
       GPTMICR_Timer_0 |= 0x1;
      GPTMCTL_Timer_0 |= 0x1;//starts the timer

      break;
   case 0x10:
      GPIO_PORTF_DATA_R = 0x2;///other button do other color
      GPTMCTL_Timer_0 &= ~0x1;//stops the timer
      //lab2p4();
      break;
   default:
      break;
  }
  //return;
}



void lab2p4(){

  initializelab2p4();
  //GPIO_PORTF_DATA_R = 0x4;
    
    
  while(1){
    ///do nothing,
    // dont worry you still have value
  }
  
  
  
  
  
}