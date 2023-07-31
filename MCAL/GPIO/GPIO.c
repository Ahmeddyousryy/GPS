#include "GPIO.h"


void GPIO_SetPinDirection(unsigned char number,unsigned char state)
{
	unsigned  char port = number /10 ;
	unsigned  char pin = number %10 ;
	
	if(state == OUTPUT)
	{
		switch(port) 
		{
			case 1 : SET_BIT(GPIO_PORTA_DIR_R,pin);     break;
			case 2 : SET_BIT(GPIO_PORTB_DIR_R,pin);     break;
			case 3 : SET_BIT(GPIO_PORTC_DIR_R,pin);     break;
			case 4 : SET_BIT(GPIO_PORTD_DIR_R,pin);     break;
			case 5 : SET_BIT(GPIO_PORTE_DIR_R,pin);     break;
			case 6 : SET_BIT(GPIO_PORTF_DIR_R,pin);     break;
      default :                                   break;
		}
	}
	else
	{
		switch(port) 
		{
			case 1 : CLR_BIT(GPIO_PORTA_DIR_R,pin);     break;
			case 2 : CLR_BIT(GPIO_PORTB_DIR_R,pin);     break;
			case 3 : CLR_BIT(GPIO_PORTC_DIR_R,pin);     break;
			case 4 : CLR_BIT(GPIO_PORTD_DIR_R,pin);     break;
			case 5 : CLR_BIT(GPIO_PORTE_DIR_R,pin);     break;
			case 6 : CLR_BIT(GPIO_PORTF_DIR_R,pin);     break;
      default :                                   break;
		}
	}
	
	
}

void GPIO_SetPinValue(unsigned char number,unsigned char state)
{
	unsigned  char port = number /10 ;
	unsigned  char pin = number %10 ;
	
	if(state == HIGH)
	{
		switch(port) 
		{
			case 1 : SET_BIT(GPIO_PORTA_DATA_R,pin);     break;
			case 2 : SET_BIT(GPIO_PORTB_DATA_R,pin);     break;
			case 3 : SET_BIT(GPIO_PORTC_DATA_R,pin);     break;
			case 4 : SET_BIT(GPIO_PORTD_DATA_R,pin);     break;
			case 5 : SET_BIT(GPIO_PORTE_DATA_R,pin);     break;
			case 6 : SET_BIT(GPIO_PORTF_DATA_R,pin);     break;
      default :                                    break;
		}
	}
	else
	{
		switch(port) 
		{
			case 1 : CLR_BIT(GPIO_PORTA_DATA_R,pin);     break;
			case 2 : CLR_BIT(GPIO_PORTB_DATA_R,pin);     break;
			case 3 : CLR_BIT(GPIO_PORTC_DATA_R,pin);     break;
			case 4 : CLR_BIT(GPIO_PORTD_DATA_R,pin);     break;
			case 5 : CLR_BIT(GPIO_PORTE_DATA_R,pin);     break;
			case 6 : CLR_BIT(GPIO_PORTF_DATA_R,pin);     break;
      default :                                    break;
		}
	}
	
	
}