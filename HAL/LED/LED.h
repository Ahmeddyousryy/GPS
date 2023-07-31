#ifndef LED_H
#define LED_H
#include "tm4c123gh6pm.h"
#include "BitMask.h"
#include "GPIO.h"
#define RED              1
#define BLUE             2
#define GREEN            3
#define YELLOW           4   

void GPIO_LED_Init();
void GPIO_LED_On(unsigned char);
void GPIO_LED_Off(unsigned char);
void GPIO_LED_Off_All();

#endif
