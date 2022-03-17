/*
	�������ԭ��:0~180��
	0.5ms-----0��
	1.0ms-----45��
	1.5ms-----90��
	2.0ms-----135��
	2.5ms-----180��
*/
#include <REGX52.H>
#include "timer0.h"
#include "delay.h"

sbit SG90=P2^0;				//PWM�ź�
unsigned char count=0;
unsigned char PWM_count=0;       

void main()
{
  Timer0_Init();
  while(1)
  {
			PWM_count=1;	  //���ת��0��
			Delay(1000);
			PWM_count=2;	  //���ת��45��
			Delay(1000);
			PWM_count=3;	  //���ת��90��
			Delay(1000);
			PWM_count=4;	  //���ת��135��
			Delay(1000);
			PWM_count=5;	  //���ת��180��
			Delay(1000);
   }
}




void Timer0() interrupt 1      //�ر�ע��˴���0--�ⲿ�ж�0��1--��ʱ���ж�0��2--�ⲿ�ж�1��3--��ʱ���ж�1��4--���п��ж�1
{
  
  TL0 = 0x33;		
  TH0 = 0xFE;			 	//���¸�������ֵΪ0.5ms
  
  count++;					//�ƴΣ�ÿ500us  count+1
	count%=40;				//����Ϊ20ms
	
  if(count<PWM_count)
  {									
    SG90=1;
  }
  else
  {
    SG90=0;
  }
}
