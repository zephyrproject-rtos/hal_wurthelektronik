/*
 * Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "weplatform_i2c.h"

#include <errno.h>

#ifdef CONFIG_I2C
#include <zephyr/drivers/i2c.h>
#endif /* CONFIG_I2C */

/**
 * @brief Read data starting from the addressed register via I2C
 * @param[in] interface Sensor interface
 * @param[in] regAdr The register address to read from
 * @param[in] numBytesToRead Number of bytes to read
 * @param[out] data The read data will be stored here
 * @retval Error code
 */
inline int8_t WE_ReadReg_I2C(WE_sensorInterface_t *interface, uint8_t regAdr,
			     uint16_t numBytesToRead, uint8_t *data)
{
	int status = 0;

#ifdef CONFIG_I2C
	if (numBytesToRead > 1 && interface->options.i2c.useRegAddrMsbForMultiBytesRead) {
		/*
		 * Register address most significant bit is used to
		 * enable multi bytes read
		 */
		WRITE_BIT(regAdr, 7, 1);
	}
	if (interface->options.i2c.slaveTransmitterMode) {
		status = i2c_read_dt(interface->handle, data, numBytesToRead);
	} else {
		status = i2c_burst_read_dt(interface->handle, regAdr, data, numBytesToRead);
	}
#else
	status = -EIO;
#endif /* CONFIG_I2C */

	return status == 0 ? WE_SUCCESS : WE_FAIL;
}

/**
 * @brief Write data starting from the addressed register via I2C
 * @param[in] interface Sensor interface
 * @param[in] regAdr Address of register to be written
 * @param[in] numBytesToWrite Number of bytes to write
 * @param[in] data Data to be written
 * @retval Error code
 */
inline int8_t WE_WriteReg_I2C(WE_sensorInterface_t *interface, uint8_t regAdr,
			      uint16_t numBytesToWrite, uint8_t *data)
{
	int status = 0;

#ifdef CONFIG_I2C
	status = i2c_burst_write_dt(interface->handle, regAdr, data, numBytesToWrite);
#else
	status = -EIO;
#endif /* CONFIG_I2C */

	return status == 0 ? WE_SUCCESS : WE_FAIL;
}
