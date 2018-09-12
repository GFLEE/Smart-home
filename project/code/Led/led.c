#include <ioCC2530.h>


#define uint unsigned int
#define uchar unsigned char


#define LED1 P1_0 
#define LED2 P1_1 
#define LED3 P0_7 
 

void Delay(uint ms)
{
   uint i,j;
    for(i=ms;i>0;i--)
     for(j=587;j>0;j--);   
}


void Init(void)
{
  P1DIR |= 0x03;  
  P0DIR |= 0x10; 
  
  P0SEL =0;
  P1SEL =0;
  
  LED1 = 1;
  LED2 = 1;
  LED3 = 1; 
 
}

int main(void)
{
  Init();           
  while(1)           
  {
    LED1 = !LED1;    
    Delay(200);
    LED2 = !LED2;   
    Delay(200);
    LED3 = !LED3;    
 
    
  }
}



