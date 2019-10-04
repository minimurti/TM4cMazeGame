void initializelab2p1();
//void lab2p1();
//void Timer_Handler( void );///me I jordan Added this 


#define GPIO_PORTF_DATA_R (*((volatile uint32_t *)0x400253FC))//from the lab handout
#define RCGCGPIO (*((unsigned long *)0x400fE608))
#define PORT_F ((unsigned long)0x20)
#define PortF_DIR (*((unsigned long *)0x40025400))
#define PortF_DEN (*((unsigned long *)0x4002551C))
#define PortF_DATA (*((unsigned long *)0x40025000))
#define GPIO_LOCK (*((unsigned long *)0x40025520))
#define UNLOCKED ((unsigned long)0x4C4F434B))
#define GPIO_CMT (*((unsigned long *)0x40025524))
#define GPIO_PUR (*((unsigned long *)0x40025510))
#define GPIO_PORTA_AMSEL_R (*((volatile uint32_t *)0x40004528))/////FOR port A, I decided to stick to convention since I used the code copied from the lab... but then i unused it... so... well the convention is probably good. 
#define SYSCTL_RCGC2_R (*((volatile uint32_t *)0x400FE108))///whats volitile unit 32? why not unsigned log... well the first thing i used was volitle so VOLITLE it is... 
#define GPIO_PORTA_PCTL_R (*((volatile uint32_t *)0x4000452C))
#define GPIO_PORTA_DIR_R (*((volatile uint32_t *)0x40004400))
#define GPIO_PORTA_AFSEL_R (*((volatile uint32_t *)0x40004420))
#define GPIO_PORTA_DEN_R (*((volatile uint32_t *)0x4000451C))///that was easy, I already know the bias so..... 
#define GPIO_PORTA_DATA_R (*((volatile uint32_t *)0x400043FC))
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))

#define GPTMCTL_Timer_0 (*((volatile uint32_t *)0x4003000C))//controlling pausing, ect
#define GPTMCFG_Timer_0 (*((volatile uint32_t *)0x40030000))//bittype set

#define GPTMCAMR_Timer_0 (*((volatile uint32_t *)0x40030004))//modeset
#define GPTMCBMR_Timer_0 (*((volatile uint32_t *)0x40030008))//modeset

#define GPTMTAILR_Timer_0 (*((volatile uint32_t *)0x40030028))//load time value
#define GPTMTBILR_Timer_0 (*((volatile uint32_t *)0x4003002C))//load time value


#define GPTMTAV_Timer_0 (*((volatile uint32_t *)0x40030050))// time value


#define GPTMRIS_Timer_0 (*((volatile uint32_t *)0x4003001C))// time value Poll
#define GPTMICR_Timer_0 (*((volatile uint32_t *)0x40030024))// time value CLEAR

#define GPTMIMR_Timer_0 (*((volatile uint32_t *)0x40030018))// time value CLEAR


#define Seconds 16000000// Seconds unit for CPU


#define En0 (*((volatile uint32_t *)0xE000E100))//

#define GPIOM_Port_F (*((volatile uint32_t *)0x40025410))//GPIOInterupt MASK,
#define GPIOM_Port_A (*((volatile uint32_t *)0x40004410))//GPIOInterupt MASK,


//
//GPIO Port F (APB) base: 0x4002.5000 offset 51C [Digital enable]
//GPIO Port F (APB) base: 0x4002.5000 offset 400 [Control direction - input/output]
//General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO) Base 0x400F.E000 Offset 0x608


