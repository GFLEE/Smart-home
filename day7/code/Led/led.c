#include <ioCC2530.h>


#define uint unsigned int
#define uchar unsigned char

//定义控制灯的端口
#define LED1 P1_0 //定义 LED1 为 P10 口控制
#define LED2 P1_1 //定义 LED2 为 P11 口控制
#define LED3 P0_4 //定义 LED3 为 P04 口控制

void Delay(uint);  //延时函数
void InitIO(void); //初始化 LED 控制 IO 口函数


void main(void)
{
  InitIO();           
  while(1)           //死循环
  {
    LED1 = !LED1;    // LED1 灯闪一次
    Delay(200);
    LED2 = !LED2;    // LED2 灯闪一次
    Delay(200);
    LED3 = !LED3;    // LED3 灯闪一次
    Delay(200);
  }
}


void Delay(uint xms)
{
   uint i,j;
    for(i=xms;i>0;i--)
     for(j=587;j>0;j--);   
}


void InitIO(void)
{
  P1DIR |= 0x03;  //P10、 P11 定义为输出
  P0DIR |= 0x10;  //P04定义为输出
  LED1 = 1;
  LED2 = 1;
  LED3 = 1;       //LED 灯初始化为关
}