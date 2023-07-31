#include "GPS.h"

char GPS[12][20];


float toDegree(float angle)
{
	int degree = (int)angle/100;
	float minutes = angle - (float)degree*100;
	return (degree + (minutes/60));
}
float toRad(float angle)
{
	return angle *PI /180 ;
}
 float degToLat(float latitude)
{
	return (int)(latitude / 100) + (latitude - (int)(latitude / 100) * 100) / 60.0;
    
}
float degToLong(float longitude)
{
	return (int)(longitude / 100) + (longitude - (int)(longitude / 100) * 100) / 60.0;
}




float getDistance(float currentLat,float currentLong , float destLat , float destLong)
{
	// TO CONVERT LAT AND LONG INTO RAD ANGLES
	float currentLatRad = toRad(currentLat);
	float currentLongRad = toRad(currentLong);
	float destLatRad = toRad(destLat);
	float destLongRad = toRad(destLong);
	// TO GET DIFF BETWEEN CURRENT AND DESTINATION
	float Long =  destLongRad - currentLongRad ;
	float Lat = destLatRad - currentLatRad ;
	// TO CALCULATE DISTANCE
	float a = pow(sin(Lat/2),2) + cos(currentLatRad) * cos(destLatRad) * pow(sin(Long/2),2);
		
	double c = 2 * atan2(sqrt(a),sqrt(1-a));
	
	return EARTH_RADIUS * c ;

}

void GPS_Read()
{
	
       char GPS_logName[] = "$GPRMC,";
       char character ;
       char dataName;
       char data;   
       char i ;
       char flag = 0;
	
	
	 while(flag==0)                                  //THIS PART TO CHECK THE CORRECT LOG NAME
        {
            flag = 1;
            
        for(i = 0 ;i<7;i++)
        {
            character = UART2_Receive();
        //    UART2_Send(character);					
            if(character != GPS_logName[i])
            {
                flag = 0;
                break;
            }
        }
    }
				
         character = 0;
         dataName = 0;
         data = 0;
    while(character!='*')
    {
        character = UART2_Receive();
    //  UART2_Send(character);

       if(character != ',')
       {
           GPS[dataName][data] = character;
           data++;
       }
       else if(character == ',')
       {
           dataName++;
           data = 0;
       }

    }
		
			
	
}



