/*
 * Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "weplatform.h"

#include "weplatform_i2c.h"
#include "weplatform_spi.h"

/**
 * @brief Read data starting from the addressed register
 * @param[in] interface Sensor interface
 * @param[in] regAdr The register address to read from
 * @param[in] numBytesToRead Number of bytes to read
 * @param[out] data The read data will be stored here
 * @retval Error code
 */
inline int8_t WE_ReadReg(WE_sensorInterface_t *interface, uint8_t regAdr,
			 uint16_t numBytesToRead, uint8_t *data)
{
	switch (interface->interfaceType) {
	case WE_i2c:
		return WE_ReadReg_I2C(interface, regAdr, numBytesToRead, data);

	case WE_spi:
		return WE_ReadReg_SPI(interface, regAdr, numBytesToRead, data);
	
	default:
		return WE_FAIL;
	}
}

/**
 * @brief Write data starting from the addressed register
 * @param[in] interface Sensor interface
 * @param[in] regAdr Address of register to be written
 * @param[in] numBytesToWrite Number of bytes to write
 * @param[in] data Data to be written
 * @retval Error code
 */
inline int8_t WE_WriteReg(WE_sensorInterface_t *interface, uint8_t regAdr,
			  uint16_t numBytesToWrite, uint8_t *data)
{
	switch (interface->interfaceType) {
	case WE_i2c:
		return WE_WriteReg_I2C(interface, regAdr, numBytesToWrite, data);

	case WE_spi:
		return WE_WriteReg_SPI(interface, regAdr, numBytesToWrite, data);
	
	default:
		return WE_FAIL;
	}
}
