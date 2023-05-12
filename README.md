Embedded System Project
GPS using tiva C kit " tm4c123 micro controller "

This project aims to detect certain location by its latitude and longitude

Hardware components used are GPS Module , LCD and tiva c

The communication protocol used to connect with gps module is UART with baud rate [ 9600 ] 

The data sent by GPS module is sent in form of characters separated by ' , '  ( '3' , '0' , '.' , '1' , 'A' this indicates to 30.1 and then A letter )
Each group of data is sent after sending a specific logName 
The first 6 character are logName $GPRMC which our software is concerned with by checking it before receiving any data
These data are saved in 2D array ( 12 x 20 )
Each row in that array carry different kind of data sent by GPS module
First row has date which comes after logName
Second row has Verfication letter if the data is correct it will be 'A' 
Third row has latitude in degree form 
Fourth row has either N or S   ( North or South )
Fifth row has longitude in degree form

The Sofware application is designed to :
1 / Initialization the drivers used ( LCD , GPS MODULE , LED )
    each driver is initialized by initalization the PORT needed
    
2 / Read data from GPS Module by GPS_Read function which reads and saves data in GPS array 

3 / Passing GPS[2] , GPS[4] which have the latitude and longitude  read by GPS module to atof function to convert characters into float

4 / Passing latitude and longitudes float into degToLat and degToLong function to convert them into Decimal form instead of degree form

5 / Passing the latitude , longitude of the destination which are global constants in the code and latitude , longitude of current location which come from degToLat and degToLong fucntions to getDistance function to calculate the distance between current location and the destination

6 / Check if the distance more than 5m
RED LED is turned on , and " MORE THAN : 5m " is displayed on LCD

Check if the distance less 5m and more than 1m
BLUE LED is turned on , and " MORE THAN : 2m" is displayed on LCD

Check if the distance less than 1m
GREEN LED is turned on , and " YOU REACHED YOUR DESTINATION " is displayed on LCD

