#include "lab1p1header.h"
#include "SSD2119.h"

#include <stdint.h>
#include <stdio.h>
//#include <stdbool.h>


int bx = 62;//the bias of a rectangle* 1.5 + middle of screen vs y
int by = 22;//the bias of a rectangle* 1.5 = 22
int freeze =0;
int GameOver = 0;

unsigned short Color6[16] = {
  0,                                            //0 – black                   (#000000) 	000000 	0
 ((0x00>>3)<<11) | ((0x00>>2)<<5) | (0xAA>>3),  //1 – blue                    (#0000AA) 	000001 	1
 ((0x00>>3)<<11) | ((0xAA>>2)<<5) | (0x00>>3),  //2 – green                   (#00AA00) 	000010 	2
 ((0x00>>3)<<11) | ((0xAA>>2)<<5) | (0xAA>>3),  //3 – cyan                    (#00AAAA) 	000011 	3
 ((0xAA>>3)<<11) | ((0x00>>2)<<5) | (0x00>>3),  //4 – red                     (#AA0000) 	000100 	4
 ((0xAA>>3)<<11) | ((0x00>>2)<<5) | (0xAA>>3),  //5 – magenta                 (#AA00AA) 	000101 	5
 ((0xAA>>3)<<11) | ((0x55>>2)<<5) | (0x00>>3),  //6 – brown                   (#AA5500) 	010100 	20
 ((0xAA>>3)<<11) | ((0xAA>>2)<<5) | (0xAA>>3),  //7 – white / light gray      (#AAAAAA) 	000111 	7
 ((0x55>>3)<<11) | ((0x55>>2)<<5) | (0x55>>3),  //8 – dark gray /bright black (#555555) 	111000 	56
 ((0x55>>3)<<11) | ((0x55>>2)<<5) | (0xFF>>3),  //9 – bright blue             (#5555FF) 	111001 	57
 ((0x55>>3)<<11) | ((0xFF>>2)<<5) | (0x55>>3),  //10 – bright green           (#55FF55) 	111010 	58
 ((0x55>>3)<<11) | ((0xFF>>2)<<5) | (0xFF>>3),  //11 – bright cyan            (#55FFFF) 	111011 	59
 ((0xFF>>3)<<11) | ((0x55>>2)<<5) | (0x55>>3),  //12 – bright red             (#FF5555) 	111100 	60
 ((0xFF>>3)<<11) | ((0x55>>2)<<5) | (0xFF>>3),  //13 – bright magenta         (#FF55FF) 	111101 	61
 ((0xFF>>3)<<11) | ((0xFF>>2)<<5) | (0x55>>3),  //14 – bright yellow          (#FFFF55) 	111110 	62
 ((0xFF>>3)<<11) | ((0xFF>>2)<<5) | (0xFF>>3)   //15 – bright white           (#FFFFFF) 	111111 	63
};



int MAZE[13][13] =  {
{1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,0,1,1,0,1,1,0,1},
{1,0,1,0,0,0,1,0,0,0,0,0,1},
{1,1,1,0,1,0,1,1,1,1,1,1,1},
{1,0,0,0,1,0,1,0,0,0,0,0,1},
{1,0,1,1,1,1,1,0,1,1,1,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,1},
{1,1,1,1,1,1,1,0,1,0,1,0,1},
{1,0,0,0,0,0,1,0,1,0,1,0,1},
{1,0,1,1,1,0,1,1,1,0,1,0,1},
{1,0,0,0,1,0,0,0,0,0,1,0,1},
{1,1,1,1,1,1,1,1,1,1,1,0,1}/////This is an array for the Maze. 0's represent path, and 1's are walls
};







int PlayerX = 1;///initial coordinates
int PlayerY = 1;
int PlayerDirection = RIGHT;





void PortF_Init5(){


RCGCGPIO |= PORT_F; // enable Port F GPIO
PortF_DIR |= 0xE; // set PF1,2,3 as output
PortF_DEN = 0xFF; // enable digital pin PF1-F5
GPIO_PORTF_DATA_R = 0x0; // set PF1 to 1 and the other port F pins to 0
GPIO_LOCK = 0x4C4F434B;
GPIO_CMT=0xFF;
GPIO_PUR=0x11;





}




void DrawPlayer(){
  
    LCD_DrawFilledCircle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 7 , Color6[12]);///Player is a circle
  
      switch(PlayerDirection){
        case UP:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,UP, Color6[9]);
          break;
        case RIGHT:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,RIGHT, Color6[9]);
          break;
        case DOWN:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,DOWN, Color6[9]);
          break;
        case LEFT:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,LEFT, Color6[9]);//with a triangle pointing in it's direction
          break;
        
        default:
          break;
  
      }
  
}

void ErasePlayer(){
  
    LCD_DrawFilledCircle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 7 , Color6[15]);//clears it's old location
    
  
      switch(PlayerDirection){
        case UP:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,UP, Color6[15]);
          break;
        case RIGHT:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,RIGHT, Color6[15]);
          break;
        case DOWN:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,DOWN, Color6[15]);
          break;
        case LEFT:
          LCD_DrawFilledTriangle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 4 ,LEFT, Color6[15]);
          break;
        
        default:
          break;
  
      }
  LCD_DrawFilledCircle(PlayerX*15 + bx+7, PlayerY*15 + by+7, 3 , Color6[0]);//leave's a breadcrumb
}


int checkBadDirection(){
    switch(PlayerDirection){
    case UP:
    return MAZE[PlayerX][PlayerY+1];//makes sure the player never faces a wall
    break;
    case RIGHT:
    return MAZE[PlayerX+1][PlayerY];
    break;
    case DOWN:
    return MAZE[PlayerX][PlayerY-1];
    break;
    case LEFT:
    return MAZE[PlayerX-1][PlayerY];
    break;
  default:
    PlayerDirection = UP;///just incase somthing went wrong;
    break;
    }
  
}



void rotatePlayer(){
  ErasePlayer();
  switch(PlayerDirection){
    case UP:
    PlayerDirection = RIGHT;//changes the direction clockwise
    break;
    case RIGHT:
    PlayerDirection = DOWN;
    break;
    case DOWN:
    PlayerDirection = LEFT;
    break;
    case LEFT:
    PlayerDirection = UP;
    break;
  default:
    PlayerDirection = UP;///just incase somthing went wrong;
    break;
    
  }
  
  while(checkBadDirection() == 1)
    rotatePlayer();//recursively called until valid direction
  
  DrawPlayer();
  
}

void movePlayer(){
  ErasePlayer();
    switch(PlayerDirection){
    case UP:
      PlayerY++;//changes the coordinate based on direction
    break;
    case RIGHT:
      PlayerX++;
    break;
    case DOWN:
    PlayerY--;
    break;
    case LEFT:
    PlayerX--;
    break;
  default:
    break;
    
  }
  
  while(checkBadDirection() == 1)
    rotatePlayer();
  
  DrawPlayer();
}





void DrawMaze(){
  LCD_ColorFill(Color6[15]);
  

  

  int CordX;
  int CordY;
  for(CordY = 0;CordY < 13; CordY++){
    for(CordX = 0;CordX < 13; CordX++){
      if(MAZE[CordX][CordY] == 1)
      LCD_DrawFilledRect(CordX*15 + bx, CordY*15 + by, 15, 15, Color6[0]); //cascaded for loop iterates along the Maze Array, placing rectangles shifted by bx and by to be at the center of the screen
    }
  }
    
  
  
  
}


void lab5(){
  PortF_Init5();
  LCD_Init();
  DrawMaze();
  DrawPlayer();
  char Congratulations[16] = {'C','O','N','G','R','A','T','U','L','A','T','I','O','N','S','!'};
  
  while(1){
      
    if(GameOver == 0){
     switch(GPIO_PORTF_DATA_R & 0x11){//////Look at the last bits
            case 0x10:
              if(freeze == 0)//freese makes sure that it doesnt go to fast. the player has to let go to move again. 
                movePlayer();
                freeze = 1;
                break;
                
             case 0x01:
               if(freeze == 0)
                rotatePlayer();
                freeze = 1;
                break;
                
             case 0x11://idk why but for this lab the 0 was for high and 1 for low, dont wanna question.
                freeze = 0;
                break;
             default:
                break;
        }
     

     
     if(PlayerX == 12 && PlayerY ==11){//coordinates of end
      LCD_ColorFill(Color6[0]);
      LCD_PrintString(Congratulations);
      GameOver = 1;
     }
     
    }
  }
  
return;

}




  
