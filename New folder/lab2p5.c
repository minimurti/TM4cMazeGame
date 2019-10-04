void initlab2p5(){
RCGCTIMER = 0x1;//set timer0 to 1. Enableing the use of the time
GPTMCTL_Timer_0 &= ~0x1;//pauses the timer
GPTMCFG_Timer_0 = 0x0;//sets the 16bit it to 32 bit.
GPTMCAMR_Timer_0 = 0x2;//pet to periodic timer mode - 0x1 = one shot, 0x3 = capture
GPTMCAMR_Timer_0 &= ~0x10;//set timer to count down
GPTMTAILR_Timer_0 = Seconds;//countdown to begin at 160000000

  
  
  
// RCGCGPIO = 0x1; // enable Port A GPIO clock
 volatile unsigned long delay;
 SYSCTL_RCGC2_R |= 0x01; // activate clock for Port A//Do I really need this?Ill assume so 
 delay = SYSCTL_RCGC2_R; // allow time for clock to start//Do I really need this? 
 GPIO_PORTA_PCTL_R &= ~0x00000F00; // regular GPIO//no idea what this does but i moved the F to the port A spot
 GPIO_PORTA_AMSEL_R &= ~0xF4; // disable analog function of ALL PA Used - 11101100
 GPIO_PORTA_DIR_R |= 0xE0; // set PA7-5 to output 1110000
 GPIO_PORTA_AFSEL_R &= ~0xF4; // regular port function
 GPIO_PORTA_DEN_R |= 0xF4; // enable digital on ALL PA USED
 

En0 |= 0x80000;//enable Timer0A interupt
//En0 |= 0x100000;//enable Timber0B interupt
En0 |= 0x1;//enable PortA interupt

GPTMIMR_Timer_0 |= 0x1;//enable interupt TimerA AND TimerB
GPIOM_Port_A |= 0x14;






//En0 |= 0x40000000;///new enable PortF Interupt
//GPIOM_Port_F = 0x11;  //enable SWITCH 0,4 interup

//GPIOM_Port_F = hello;
GPTMCTL_Timer_0 |= 0x1;//starts the timer


 
 
 
}


//////////////////////////////////////////////this needs to be commented out for the other labs to workd
// void Timer_Handler( void ){
//  GPTMICR_Timer_0 |= 0x1;//resetsA  
//  //GPTMIMR_Timer_0 |= 0x101;//enable interupt TimerA AND TimerB
//   
//  
//  switch(state){//////Look at the last bits
//  case GO:
//    /////////////////////////////////////////////////////////////////ON
//    state=STOP;
//    GoLED();
//    /////////////////////////////////////////////////////////////////ON
//      break;
//   case STOP:
//    /////////////////////////////////////////////////////////////////stop
//    state=GO;
//    StopLED();
//    /////////////////////////////////////////////////////////////////STOP
//      break;
//   default:
//      break;
//  }
//  
// 
//}






void lab2p5(){
  
  initlab2p5();
  state = OFF;
  
  while (1) {} 
  }
  
  
  
  
