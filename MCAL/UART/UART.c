#include "UART.h"


void UART2_Init(void)
{
	SET_BIT(SYSCTL_RCGCUART_R,2); // TO ACTIVATE UART2 CLOCK
        //while(GET_BIT(SYSCTL_PRUART_R,2)==0); // TO WAIT TILL ACTIVATION OF UART2
	Systick_Delay_ms(1);
	
	SET_BIT(SYSCTL_RCGCGPIO_R,3); // TO ACTIVATE PORTD CLOCL          
	while(GET_BIT(SYSCTL_PRGPIO_R,3)==0);   // TO WAIT TILL ACTIVATION OF PORTD
	
	CLR_BIT(UART2_CTL_R,0);  // TO DISABLE UART2
	
	UART2_IBRD_R = 104 ;         // TO CALCULATE BAUDRATE VALUE [9600]
	UART2_FBRD_R = 11 ;
	
	UART2_LCRH_R = 0x70;  // TO SELECT 8 BIT WORD LENGTH AND 1 STOP BIT , ENABLE FIFO
        UART2_CTL_R = 0x301 ;  // TO ENABLE RX , TX , UART2  
	GPIO_PORTD_LOCK_R =  0x4C4F434B;      // TO UNLOCK PORTD PINS
	GPIO_PORTD_CR_R |= 0xC0 ;             // TO MAKE PINS CHANGABLE
	GPIO_PORTD_AFSEL_R |= 0xC0;  // TO ENABLE ALTERNATE FUNCTION
	GPIO_PORTD_AMSEL_R &=~ 0xC0 ;  // TO DISABLE ANALOG FUNCTION
	
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF) + 0x11000000; // TO CONFIGURE PINS AS UART
	
	GPIO_PORTD_DEN_R |= 0xC0;  // ENABLE OUTPUT DIRECTION
	
}
char UART2_Receive(void)
{
	 while((GET_BIT(UART2_FR_R,4))!=0);
	 return (char)(UART2_DR_R & 0xFF);
	
}
void UART2_SendString(char* ptr)
{
	while(*ptr != '\0')
	{
		UART2_Send(*ptr);
		ptr++;
	}
}
 void UART2_Send(char data)
 {
	 while(GET_BIT(UART2_FR_R,5)!=0);
	 UART2_DR_R = data ;
 }
 
 void getCommand(char* command, int length)
 {  
	 char character ;
	 int i ;
	 for(i =0 ;i<length;i++)
	 {
		 character = UART2_Receive();
		 if(character!= CR)
		 {
			 command[i] = character ;
			 UART2_Send(command[i]);
		 }
		 else if (character == CR || i == length )
		 break;
	 }	 
	 
 }
 

 