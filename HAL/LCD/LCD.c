#include "LCD.h"


void GPIO_LCD_Init()
{
	SET_BIT(SYSCTL_RCGCGPIO_R,1);  //ACTIVATE PORTB CLOCK 
	while(GET_BIT(SYSCTL_PRGPIO_R,1) == 0);  // DELAY FOR CLOCK TO BE STABLIZED
	
	GPIO_PORTB_LOCK_R =  0x4C4F434B;      // TO UNLOCK PORTB PINS
	GPIO_PORTB_AFSEL_R &=~ 0xFF;          // TO DISABLE ALTERNATE FUNCTION
	GPIO_PORTB_AMSEL_R &=~ 0xFF;          // TO DISABLE ANALONG FUNCTION
	GPIO_PORTB_CR_R |= 0x7F ;             // TO MAKE PINS CHANGABLE
	GPIO_PORTB_PCTL_R &=~ 0xFFFFFFFF;     // TO ENABLE GPIO MODE
	GPIO_PORTB_DEN_R |= 0xFF;             // TO ENABLE DIGITAL I/0
	
	GPIO_PORTB_DIR_R |= 0xFF ;            // TO ENABLE OUTPUT DIRECTION
	
  GPIO_SetPinValue(LCD_RW,LOW);      //	TO SELECT WRITE MODE 
	
		
	GPIO_LCD_WriteCommand(0x33); 
  GPIO_LCD_WriteCommand(0x32); 
	GPIO_LCD_WriteCommand(0x28);  
	GPIO_LCD_WriteCommand(0x02);
	GPIO_LCD_WriteCommand(0x0C);
	GPIO_LCD_WriteCommand(0x01);
	
	
}
void GPIO_LCD_WriteCharacter(unsigned char ch)
{
	  GPIO_SetPinValue(LCD_RS,HIGH);    // TO SELECT DATA REGISTER TO SEND DATA
	
	  GPIO_SetPinValue(LCD_D4 , GET_BIT(ch,4));
	  GPIO_SetPinValue(LCD_D5 , GET_BIT(ch,5));
	  GPIO_SetPinValue(LCD_D6 , GET_BIT(ch,6));
	  GPIO_SetPinValue(LCD_D7 , GET_BIT(ch,7));
	
	  GPIO_SetPinValue(LCD_EN,HIGH);
	  Systick_Delay_ms(1);      //DELAY 1ms//
	  GPIO_SetPinValue(LCD_EN,LOW);
	
	  GPIO_SetPinValue(LCD_D4 , GET_BIT(ch,0));
	  GPIO_SetPinValue(LCD_D5 , GET_BIT(ch,1));
	  GPIO_SetPinValue(LCD_D6 , GET_BIT(ch,2));
	  GPIO_SetPinValue(LCD_D7 , GET_BIT(ch,3));
	
	  GPIO_SetPinValue(LCD_EN,HIGH);
	  Systick_Delay_ms(1); //DELAY 1ms//
	  GPIO_SetPinValue(LCD_EN,LOW);
	
    Systick_Delay_ms(5);    //DELAY 5ms//

}
void GPIO_LCD_WriteCommand(unsigned char ch)
{
	  GPIO_SetPinValue(LCD_RS,LOW);    // TO SELECT COMMAND REGISTER TO SEND COMMAND
	
	
	  GPIO_SetPinValue(LCD_D4 , GET_BIT(ch,4));
	  GPIO_SetPinValue(LCD_D5 , GET_BIT(ch,5));
	  GPIO_SetPinValue(LCD_D6 , GET_BIT(ch,6));
	  GPIO_SetPinValue(LCD_D7 , GET_BIT(ch,7));
	
	  GPIO_SetPinValue(LCD_EN,HIGH);
	  Systick_Delay_ms(1); //DELAY 1ms//
	  GPIO_SetPinValue(LCD_EN,LOW);
	
	  GPIO_SetPinValue(LCD_D4 , GET_BIT(ch,0));
	  GPIO_SetPinValue(LCD_D5 , GET_BIT(ch,1));
	  GPIO_SetPinValue(LCD_D6 , GET_BIT(ch,2));
	  GPIO_SetPinValue(LCD_D7 , GET_BIT(ch,3));
	
	  GPIO_SetPinValue(LCD_EN,HIGH);
	  Systick_Delay_ms(1);   //DELAY 1ms//
	  GPIO_SetPinValue(LCD_EN,LOW);
	
	  Systick_Delay_ms(5);   //DELAY 5ms//
}

void GPIO_LCD_WriteString(unsigned char* string)
{
	unsigned int counter = 0 ;
	while(string[counter] != '\0')
	{
		GPIO_LCD_WriteCharacter(string[counter]);
		counter ++ ;
	}
}

void GPIO_LCD_Clear()
  {
	    GPIO_LCD_WriteCommand(0x01);
  }

void GPIO_LCD_WriteNumber(signed int Number)
{
	signed char Counter = 0;
	unsigned char Arr[10] = {0};
	if(Number < 0)
	{
		Number = Number * -1;
		GPIO_LCD_WriteCharacter('-');
	}

	do
	{
        Arr[Counter] = Number % 10;
	Number = Number / 10;
	Counter++;
	}while(Number != 0);

	while(Counter > 0)
	{
		GPIO_LCD_WriteCharacter(Arr[--Counter] + 48);
	}
}
