#ifndef GPIO_H
#define GPIO_H


#include "tm4c123gh6pm.h"
#include "BitMask.h"


void GPIO_SetPinDirection(unsigned char , unsigned char);
void GPIO_SetPinValue(unsigned char , unsigned char);

#define OUTPUT                          1
#define INPUT                           0

#define HIGH                            1
#define LOW                             0

#define PA0_PIN                        10
#define PA1_PIN                        11
#define PA2_PIN                        12
#define PA3_PIN                        13
#define PA4_PIN                        14
#define PA5_PIN                        15
#define PA6_PIN                        16
#define PA7_PIN                        17

#define PB0_PIN                        20
#define PB1_PIN                        21
#define PB2_PIN                        22
#define PB3_PIN                        23
#define PB4_PIN                        24
#define PB5_PIN                        25
#define PB6_PIN                        26
#define PB7_PIN                        27

#define PC0_PIN                        30
#define PC1_PIN                        31
#define PC2_PIN                        32
#define PC3_PIN                        33
#define PC4_PIN                        34
#define PC5_PIN                        35
#define PC6_PIN                        36
#define PC7_PIN                        37

#define PD0_PIN                        40
#define PD1_PIN                        41
#define PD2_PIN                        42
#define PD3_PIN                        43
#define PD4_PIN                        44
#define PD5_PIN                        45
#define PD6_PIN                        46
#define PD7_PIN                        47

#define PE0_PIN                        50
#define PE1_PIN                        51
#define PE2_PIN                        52
#define PE3_PIN                        53
#define PE4_PIN                        54
#define PE5_PIN                        55


#define PF0_PIN                        60
#define PF1_PIN                        61
#define PF2_PIN                        62
#define PF3_PIN                        63
#define PF4_PIN                        64

#endif