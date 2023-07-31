#include "LED.h"
#include "GPIO.h"
#include "SysTick.h"
#include "LCD.h"
#include "BitMask.h"
#include "UART.h"
#include "GPS.h"
#include <stdlib.h>
#include "string.h"

 extern char GPS[12][20];
 
 // THE COORDINATES OF MY DESTINATION
 const float destLat  = 30.0635748;
 const float destLong = 31.2784473;
 float currentLong;
 float currentLat;
 float distance;
  
int main(void)
{ 

       GPIO_LED_Init();
       UART2_Init();
       GPIO_LCD_Init();
	
   while(1)
        {
      GPS_Read();                            // DETERMINE COORDINATES OF CURRENT LOCATION
	   
		 
      currentLat = degToLat(atof(GPS[LAT]));             // RETURN LATITUDE OF CURRENT LOCATION
      currentLong	= degToLong(atof(GPS[LONG]));           // RETURN LONGITUDE OF CURRENT LOCATION
		
  	
	  distance = getDistance(currentLat,currentLong,destLat,destLong);       // CALCULATE DISTANCE BETWEEN CURREN LOCATION AND DESTINATION
	  GPIO_LCD_Clear();
  	    if(distance>8)
	  {
  	   GPIO_LED_Off_All();		
  	   GPIO_LED_On(RED);
	   GPIO_LCD_WriteString("MORE THAN : 5m");
	   //Systick_Delay_ms(300);
	   //GPIO_LCD_Clear();
		 // Systick_Delay_ms(300);
	  }
            else if(distance<8 && distance>5)
	     {
	  	GPIO_LED_Off_All();
	    GPIO_LED_On(BLUE);
      GPIO_LCD_WriteString("MORE THAN 2m");
	   // Systick_Delay_ms(300);
		 // GPIO_LCD_Clear();
		 // Systick_Delay_ms(300);
	     }
	else 
	{
	    GPIO_LED_Off_All();
	    GPIO_LED_On(GREEN);
            GPIO_LCD_WriteString("YOU REACHED YOUR");
	    GPIO_LCD_WriteCommand(0xC0);
	    GPIO_LCD_WriteString("DESTINATION");
	   // Systick_Delay_ms(300);
	   // GPIO_LCD_Clear();
           // Systick_Delay_ms(300);

	}			
 }
}


