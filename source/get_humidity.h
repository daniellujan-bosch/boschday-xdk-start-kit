/*
 * get_humidity.h
 *
 *  Created on: 19/10/2018
 *      Author: CAB1GA
 */

#ifndef SOURCE_GET_HUMIDITY_H_
#define SOURCE_GET_HUMIDITY_H_

#include "Select_Sensor.h"
#include "SensorControllerData.h"
//#include "AppController.h"
#include "XDK_Utils.h"

#include <stdio.h>
#include <math.h>

/* additional interface header files */
#include "XDK_Sensor.h"
#include "BCDS_Assert.h"
#include "BCDS_CmdProcessor.h"
#include "FreeRTOS.h"
#include "task.h"


get_data_humidity()
{
    //BCDS_UNUSED(pvParameters);

    Retcode_T retcode = RETCODE_OK;
    Sensor_Value_T sensorValue;

    memset(&sensorValue, 0x00, sizeof(sensorValue));

    retcode = Sensor_GetData(&sensorValue);
    if (RETCODE_OK == retcode)
    {
	            if (SensorSetup.Enable.Humidity)
	            {
	                printf("BME280 Environmental Conversion Data for Humidity:\n\rh =%ld %%rh\r\n",
	                        (long int) sensorValue.RH);

	                printf("\ \r\n");
	            }
    }
}


#endif /* SOURCE_GET_HUMIDITY_H_ */
