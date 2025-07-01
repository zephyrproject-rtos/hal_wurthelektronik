/*
 * Copyright (c) 2025 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <stdint.h>

/**
 * @brief Provides delay
 * @param[in] Delay in milliseconds
 */
void WE_Delay(uint32_t Delay)
{
	k_sleep(K_MSEC(Delay));
}

/**
 * @brief Delays the microcontoller for the specified time.
 *
 * @param[in] sleepForMs: time in microseconds.
 *         
 */
__weak void WE_DelayMicroseconds(uint32_t sleepForUsec)
{
	/* Microsecond tick is disabled: round to ms */
	WE_Delay(((sleepForUsec + 500) / 1000));
}