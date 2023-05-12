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
	GPIO_LED_On(BLUE);
}