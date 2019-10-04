void initializelab2p1();
void initialize_Port_F_LED();
void Timer0_Init(int clock);
void PortF_Init();
void PLL_Init();
void lab3p1();
void lab3p1TH();
void lab3p1PFH();
void Go4MHz();
void Go40MHz();
void ADC_Init();
void lab4p1();
void lab4p2();
void lab4p3();
void lab4p3PFH();
void lab5();
void LCD_DrawRightTriangle(unsigned short x, unsigned short y, short radius, unsigned short color);
void LCD_DrawFilledTriangle(unsigned short x, unsigned short y, short radius, int direction,unsigned short color);
void lab5PFH();
//unsigned short const Color4[16];
//void printf();//might instead include the header;
//void ADC0_Handler();

//void lab2p1();
//void Timer_Handler( void );///me I jordan Added this 


#define GPIO_PORTF_DATA_R (*((volatile uint32_t *)0x400253FC))//from the lab handout
#define RCGCGPIO (*((unsigned long *)0x400fE608))
  #define PORT_F ((unsigned long)0x20)
  #define PORT_A ((unsigned long)0x1)
  #define PORT_B ((unsigned long) 0x2)
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
#define GPIO_PORTB_DIR_R (*((volatile uint32_t *)0x40005400))

//Alternate Functions
#define GPIO_PORTA_AFSEL_R (*((volatile uint32_t *)0x40004420))
#define GPIO_PORTB_AFSEL_R (*((volatile uint32_t *)0x40005420))


//Digital Enable
#define GPIO_PORTA_DEN_R (*((volatile uint32_t *)0x4000451C))
#define GPIO_PORTB_DEN_R (*((volatile uint32_t *)0x4000551C))



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




# define RCGCADC (*((volatile uint32_t *) 0x400FE638))
# define RCC2 (*((volatile uint32_t *) 0x400FE070))
  # define USERCC2 ((unsigned long) 1<<31)
  # define DIV400 ((unsigned long) 1<<30)
  # define PWRDN2 ((unsigned long) 1<<13)
  # define BYPASS2 ((unsigned long) 1<<11)

# define ADCACTSS (*((volatile uint32_t *) 0x40038000))
# define ADCEMUX (*((volatile uint32_t *) 0x40038014))
# define ADCSSFIFO3 (*((volatile uint32_t *) 0x400380A8))
# define ADCSSCTL3 (*((volatile uint32_t *) 0x400380A4))
# define ADCIM (*((volatile uint32_t *) 0x40038008))
# define ADCRIS (*((volatile uint32_t *) 0x40038004))
# define RCC (*((volatile uint32_t *) 0x400FE060))

//
//GPIO Port F (APB) base: 0x4002.5000 offset 51C [Digital enable]
//GPIO Port F (APB) base: 0x4002.5000 offset 400 [Control direction - input/output]
//General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO) Base 0x400F.E000 Offset 0x608



//GPIO Port A (APB) base: 0x4000.4000
//GPIO Port A (AHB) base: 0x4005.8000
//GPIO Port B (APB) base: 0x4000.5000
//GPIO Port B (AHB) base: 0x4005.9000
//GPIO Port C (APB) base: 0x4000.6000
//GPIO Port C (AHB) base: 0x4005.A000
//GPIO Port D (APB) base: 0x4000.7000
//GPIO Port D (AHB) base: 0x4005.B000
//GPIO Port E (APB) base: 0x4002.4000
//GPIO Port E (AHB) base: 0x4005.C000
//GPIO Port F (APB) base: 0x4002.5000
//GPIO Port F (AHB) base: 0x4005.D000


