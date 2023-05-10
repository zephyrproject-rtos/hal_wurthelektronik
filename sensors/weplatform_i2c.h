/*
 * Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef WEPLATFORM_I2C_H_INCLUDED
#define WEPLATFORM_I2C_H_INCLUDED

#include <stdint.h>

#include <WeSensorsSDK.h>

/* Read a register's content via I2C */
extern int8_t WE_ReadReg_I2C(WE_sensorInterface_t *interface, uint8_t regAdr,
			     uint16_t numBytesToRead, uint8_t *data);

/* Write a register's content via I2C */
extern int8_t WE_WriteReg_I2C(WE_sensorInterface_t *interface, uint8_t regAdr,
			      uint16_t numBytesToWrite, uint8_t *data);

#endif /* WEPLATFORM_I2C_H_INCLUDED */
