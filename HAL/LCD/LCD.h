#include "tm4c123gh6pm.h"
#include "BitMask.h"
#include "GPIO.h"
#include "SysTick.h"

void GPIO_LCD_Init();
void GPIO_LCD_WriteCharacter(unsigned char);
void GPIO_LCD_WriteCommand(unsigned char);
void GPIO_LCD_WriteString(unsigned char *);
void GPIO_LCD_WriteNumber(signed int);
void GPIO_LCD_Clear();
 
// PORTB PINS FOR LCD // 
#define LCD_RS                 PB0_PIN
#define LCD_RW                 PB1_PIN
#define LCD_EN                 PB2_PIN

#define LCD_D4                 PB4_PIN
#define LCD_D5                 PB5_PIN
#define LCD_D6                 PB6_PIN
#define LCD_D7                 PB7_PIN