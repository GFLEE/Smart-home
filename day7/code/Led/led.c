#include <ioCC2530.h>


#define uint unsigned int
#define uchar unsigned char


#define LED1 P1_0 
#define LED2 P1_1 

 

void Delay(uint ms)
{
   uint i,j;
    for(i=ms;i>0;i--)
     for(j=587;j>0;j--);   
}


void Init(void)
{
  P1DIR |= 0x03;  
  P0DIR |= 0x03; 
  
  P0SEL =0x00;
  P1SEL =0x00;
  
  LED1 = 1;
  LED2 = 1;
 
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
 
  }
}



