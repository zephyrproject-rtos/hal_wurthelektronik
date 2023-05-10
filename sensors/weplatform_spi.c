/*
 * Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "weplatform_spi.h"

#include <errno.h>

#ifdef CONFIG_SPI
#include <zephyr/drivers/spi.h>
#endif /* CONFIG_SPI */

/**
 * @brief Read data starting from the addressed register via SPI
 * @param[in] interface Sensor interface
 * @param[in] regAdr The register address to read from
 * @param[in] numBytesToRead Number of bytes to read
 * @param[out] data The read data will be stored here
 * @retval Error code
 */
inline int8_t WE_ReadReg_SPI(WE_sensorInterface_t *interface, uint8_t regAdr,
			     uint16_t numBytesToRead, uint8_t *data)
{
	int status = 0;

#ifdef CONFIG_SPI
	uint8_t bytesStep = interface->options.spi.burstMode ? numBytesToRead : 1;

	for (uint8_t i = 0; i < numBytesToRead; i += bytesStep) {
		uint8_t buffer_tx[2] = { (regAdr + i) | (1 << 7), 0 };

		/*  Write 1 byte containing register address (MSB=1) + 1 dummy byte */
		const struct spi_buf tx_buf = { .buf = buffer_tx, .len = 2 };
		const struct spi_buf_set tx_buf_set = { .buffers = &tx_buf, .count = 1 };

		/* Skip first byte, then read "bytesStep" bytes of data */
		const struct spi_buf rx_buf[2] = { { .buf = NULL, .len = 1 },
						   { .buf = data + i, .len = bytesStep } };
		const struct spi_buf_set rx_buf_set = { .buffers = rx_buf, .count = 2 };

		status = spi_transceive_dt(interface->handle, &tx_buf_set, &rx_buf_set);
		if (status != 0) {
			/* Error, abort */
			break;
		}
	}
#else
	status = -EIO;
#endif /* CONFIG_SPI */

	return status == 0 ? WE_SUCCESS : WE_FAIL;
}

/**
 * @brief Write data starting from the addressed register via SPI
 * @param[in] interface Sensor interface
 * @param[in] regAdr Address of register to be written
 * @param[in] numBytesToWrite Number of bytes to write
 * @param[in] data Data to be written
 * @retval Error code
 */
inline int8_t WE_WriteReg_SPI(WE_sensorInterface_t *interface, uint8_t regAdr,
			      uint16_t numBytesToWrite, uint8_t *data)
{
	int status = 0;

#ifdef CONFIG_SPI
	uint8_t bytesStep = interface->options.spi.burstMode ? numBytesToWrite : 1;

	for (uint8_t i = 0; i < numBytesToWrite; i += bytesStep) {
		uint8_t buffer_tx[1] = { (regAdr + i) & ~(1 << 7) };

		/*
		 * First write 1 byte containing register address (MSB=0), then
		 * write "bytesStep" bytes of data
		 */
		const struct spi_buf tx_buf[2] = { { .buf = buffer_tx, .len = 1 },
						   { .buf = data + i, .len = bytesStep } };
		const struct spi_buf_set tx_buf_set = { .buffers = tx_buf, .count = 2 };

		status = spi_write_dt(interface->handle, &tx_buf_set);

		if (status != 0) {
			/* Error, abort */
			break;
		}
	}
#else
	status = -EIO;
#endif /* CONFIG_SPI */

	return status == 0 ? WE_SUCCESS : WE_FAIL;
}
