#include "LED.h"


void GPIO_LED_Init(void)             // ACTIVATE PORTF PINS AS I/0   PF1,2,3 -> RED,BLUE,GREEN LEDS   
{
         SET_BIT(SYSCTL_RCGCGPIO_R,5);         // TO ACTIVATE CLOCK OF PORTF 
         while(GET_BIT(SYSCTL_PRGPIO_R,5)==0); // DELAY TO CLOCK TO BE STABLIZED
 
         GPIO_PORTF_LOCK_R = 0x4C4F434B;     // TO UNLOCK PORTF PINS
         GPIO_PORTF_AFSEL_R &=~ 0x0E;        // TO DISABLE ALTERNATE FUNCTION
 	 GPIO_PORTF_AMSEL_R &=~ 0x0E;       // TO DISABLE ANALOG FUNCTION 
  	 GPIO_PORTF_CR_R |= 0x0E;            // TO MAKE PINS CHANGABLE
	 GPIO_PORTF_PCTL_R &=~ 0x0000FFF0;   // MAKE PIN 1-3 GPIO
         GPIO_PORTF_DEN_R |= 0x0E;           // ENABLE DIGITAL I/O
	
	       // ENABLE OUTPUT DIRECTION FOR PF1 PF2 PF3 [RED,BLUE,GREEN] //
	
	  GPIO_SetPinDirection(PF1_PIN,OUTPUT);
	  GPIO_SetPinDirection(PF2_PIN,OUTPUT);
	  GPIO_SetPinDirection(PF3_PIN,OUTPUT);
}


void GPIO_LED_On(unsigned char led)
{
	switch(led)
	{
	  case RED    : GPIO_SetPinValue(PF1_PIN,HIGH) ;          break;
	  case BLUE   : GPIO_SetPinValue(PF2_PIN,HIGH) ;          break;
	  case GREEN  : GPIO_SetPinValue(PF3_PIN,HIGH) ;          break;
	  case YELLOW : GPIO_SetPinValue(PF1_PIN,HIGH);
		              GPIO_SetPinValue(PF3_PIN,HIGH);     break;	
	  default     :                                           break;
	}
}
void GPIO_LED_Off(unsigned char led)
{
	switch(led)
	{
	  case RED    : GPIO_SetPinValue(PF1_PIN,LOW) ;           break;
	  case BLUE   : GPIO_SetPinValue(PF2_PIN,LOW) ;           break;
	  case GREEN  : GPIO_SetPinValue(PF3_PIN,LOW) ;           break;
       	  case YELLOW : GPIO_SetPinValue(PF1_PIN,LOW);
		              GPIO_SetPinValue(PF3_PIN,LOW);      break;
	  default     :                                           break;
	}
}
void GPIO_LED_Off_All()                            // THIS FUNCTION TO TURN OFF ALL LEDS
{
	GPIO_SetPinValue(PF1_PIN,LOW);
	GPIO_SetPinValue(PF2_PIN,LOW);
	GPIO_SetPinValue(PF3_PIN,LOW);
}
	