# Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(
  .
  WeSensorsSDK
)

zephyr_library_sources(
  weplatform.c
  weplatform_i2c.c
  weplatform_spi.c
)

if(CONFIG_WSEN_HIDS_2525020210001)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_HIDS_2525020210001_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_HIDS_2525020210001_hal/WSEN_HIDS_2525020210001_hal.c
  )
endif()


if(CONFIG_WSEN_HIDS_2525020210002)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_HIDS_2525020210002_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_HIDS_2525020210002_hal/WSEN_HIDS_2525020210002_hal.c
  )
endif()

if(CONFIG_WSEN_ITDS_2533020201601)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_ITDS_2533020201601_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_ITDS_2533020201601_hal/WSEN_ITDS_2533020201601_hal.c
  )
endif()

if(CONFIG_WSEN_PADS_2511020213301)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_PADS_2511020213301_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_PADS_2511020213301_hal/WSEN_PADS_2511020213301_hal.c
  )
endif()

if(CONFIG_WSEN_PDUS_25131308XXXXX)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_PDUS_25131308XXX01_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_PDUS_25131308XXX01_hal/WSEN_PDUS_25131308XXX01_hal.c
  )
endif()

if(CONFIG_WSEN_TIDS_2521020222501)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_TIDS_2521020222501_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_TIDS_2521020222501_hal/WSEN_TIDS_2521020222501_hal.c
  )
endif()

if(CONFIG_WSEN_ISDS_2536030320001)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_ISDS_2536030320001_hal
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_ISDS_2536030320001_hal/WSEN_ISDS_2536030320001_hal.c
  )
endif()