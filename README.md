# Embedded Systems project
## A simple GPS Using TM4C123GH6PM Mircocontroller [ Tiva C Board ]

### Objectives 
* This project aims to detect a destination using its Latitude and Longitude.
  

### Description
* The microcontroller communicates with GPS module using UART communication protocol
* GPS module sends the latitude and lonigtude of the current location
* The current location is compared to the destination
* The software calculates the distance
* The LED turns red when user is away by more than 5m
* turns blue when user is away by less than 5m
* turns green when user reaches its destination
* And a LCD displays the three cases
  


### Hardware 
* Tiva C Board [ARM cortex M4 based]
* GPS module
* LCD

### Software Layered Architecture
#### App --> Application
* main
#### HAL --> Hardware abstraction layer
* GPS
* LCD
* LED
#### MCAL --> Mircocontroller abstraction layer
* GPIO    --> Digital input output
* UART    --> Universal Asynchronous Receiver Transmitter
* SYSTICK --> A Core peripheral to develop a delay function

### Driver files
* .c       --> program
* .h     --> contains function prototype , configurations and macros
