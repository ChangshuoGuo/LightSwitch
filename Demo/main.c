/*
	舵机控制原理:0~180度
	0.5ms-----0度
	1.0ms-----45度
	1.5ms-----90度
	2.0ms-----135度
	2.5ms-----180度
*/
#include <REGX52.H>
#include "timer0.h"
#include "delay.h"

sbit SG90=P2^0;				//PWM信号
unsigned char count=0;
unsigned char PWM_count=0;       

void main()
{
  Timer0_Init();
  while(1)
  {
			PWM_count=1;	  //舵机转动0度
			Delay(1000);
			PWM_count=2;	  //舵机转动45度
			Delay(1000);
			PWM_count=3;	  //舵机转动90度
			Delay(1000);
			PWM_count=4;	  //舵机转动135度
			Delay(1000);
			PWM_count=5;	  //舵机转动180度
			Delay(1000);
   }
}




void Timer0() interrupt 1      //特别注意此处，0--外部中断0，1--定时器中断0，2--外部中断1，3--定时器中断1，4--串行口中断1
{
  
  TL0 = 0x33;		
  TH0 = 0xFE;			 	//重新赋计数初值为0.5ms
  
  count++;					//计次，每500us  count+1
	count%=40;				//周期为20ms
	
  if(count<PWM_count)
  {									
    SG90=1;
  }
  else
  {
    SG90=0;
  }
}
