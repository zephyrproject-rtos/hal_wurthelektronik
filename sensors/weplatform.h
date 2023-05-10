/*
 * Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef WEPLATFORM_H_INCLUDED
#define WEPLATFORM_H_INCLUDED

#include <stdint.h>

#include <WeSensorsSDK.h>

/* Read a register's content */
extern int8_t WE_ReadReg(WE_sensorInterface_t *interface, uint8_t regAdr,
			 uint16_t numBytesToRead, uint8_t *data);

/* Write a register's content */
extern int8_t WE_WriteReg(WE_sensorInterface_t *interface, uint8_t regAdr,
			  uint16_t numBytesToWrite, uint8_t *data);

#endif /* WEPLATFORM_H_INCLUDED */
