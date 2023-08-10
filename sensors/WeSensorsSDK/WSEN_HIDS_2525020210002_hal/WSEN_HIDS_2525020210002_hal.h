/*
 * Copyright (c) 2023 Wuerth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Header file for the WSEN-HIDS-2525020210002 sensor driver.
 */

#ifndef _WSEN_HIDS_2525020210002_H
#define _WSEN_HIDS_2525020210002_H

/*         Includes         */

#include <stdint.h>
#include "../WeSensorsSDK.h"

/*         Register address definitions         */
#define CRC8_INIT 0xFF
#define CRC8_POLYNOMIAL 0x31
#define CRC8_LEN 1
#define HIDS_WORD_SIZE 2

typedef enum
{
	HIDS_ADDRESS = 0x44,  /**< Sensor Address */
	HIDS_MEASURE_HPM = 0xFD,  /**< High precision measurement for T & RH */
	HIDS_MEASURE_MPM = 0xF6,  /**< Medium precision measurement for T & RH */
	HIDS_MEASURE_LPM = 0xE0,  /**< Low precision measurement for T & RH */
	HIDS_SOFT_RESET = 0x94,  /**< Soft reset */
	HIDS_HEATER_200_MW_01_S = 0x39,  /**< activate heater with 200mW for 1s, including a high precision measurement just before deactivation */
	HIDS_HEATER_200_MW_100_MS = 0x32,  /**< activate heater with 200mW for 0.1s, including a high precision measurement just before deactivation */
	HIDS_HEATER_110_MW_01_S = 0x2F,  /**< activate heater with 110mW for 1s, including a high precision measurement just before deactivation */
	HIDS_HEATER_110_MW_100_MS = 0x24,  /**< activate heater with 110mW for 0.1s, including a high precision measurement just before deactivation */
	HIDS_HEATER_20_MW_01_S = 0x1E,  /**< activate heater with 20mW for 01s, including a high precision measurement just before deactivation */
	HIDS_HEATER_20_MW_100_MS = 0x15,  /**< activate heater with 20mW for 0.1s, including a high precision measurement just before deactivation */
	HIDS_MEASURE_SERIAL_NUMBER = 0x89 /**< Device */
} hids_measureCmd_t;

#ifdef __cplusplus
extern "C"
{
#endif
int8_t HIDS_Set_Measurement_Type(WE_sensorInterface_t* sensorInterface, hids_measureCmd_t precision);
int8_t HIDS_Sensor_Read_SlNo(WE_sensorInterface_t* sensorInterface, uint32_t* serialNo);
int8_t HIDS_Sensor_Init(WE_sensorInterface_t* sensorInterface);
int8_t HIDS_Reset(WE_sensorInterface_t* sensorInterface);
int8_t HIDS_Sensor_Measure_Raw(WE_sensorInterface_t* sensorInterface, hids_measureCmd_t meausureCmd, int32_t* temperatureRaw, int32_t* humidityRaw);
int8_t HIDS_Get_Default_Interface(WE_sensorInterface_t* sensorInterface);
#ifdef __cplusplus
}
#endif

#endif /* _WSEN_HIDSNEW_H */
