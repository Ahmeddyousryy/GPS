#include "tm4c123gh6pm.h"
#include "GPIO.h"
#include <math.h>
#include "UART.h"





#define PI                       3.14159265358979323846
#define EARTH_RADIUS             6371000




#define LAT               2
#define LONG              4

float toDegree(float);
float toRad(float);
float getDistance(float,float, float,float);
void GPS_Read();
 float degToLat(float);
 float degToLong(float);
