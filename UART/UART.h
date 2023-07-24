#include "tm4c123gh6pm.h"
#include "BitMask.h"
#include "GPIO.h"
#include "SysTick.h"

#define   CR             0x0D                 

void UART2_Init(void);
char UART2_Receive(void);
void UART2_Send(char data);
void UART2_SendString(char*);
void getCommand(char*,int);