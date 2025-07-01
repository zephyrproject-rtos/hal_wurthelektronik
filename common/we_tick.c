/*
 * Copyright (c) 2025 Würth Elektronik eiSos GmbH & Co. KG
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <stdint.h>

/**
 * @brief Gets the elapsed time since startup
 *
 * @return returns elapsed in ms
 *         
 */
uint32_t WE_GetTick() { return (uint32_t)k_uptime_get(); }

/**
 * @brief Gets the elapsed time since startup
 *
 * @return returns elapsed in microseconds
 *         
 */
__weak uint32_t WE_GetTickMicroseconds()
{
    /* Microsecond tick is disabled: return ms tick * 1000 */
    return WE_GetTick() * 1000;
}