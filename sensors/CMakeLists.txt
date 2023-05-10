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

if(CONFIG_WSEN_HIDS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_HIDS_2523020210001
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_HIDS_2523020210001/WSEN_HIDS_2523020210001.c
  )
endif()

if(CONFIG_WSEN_ISDS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_ISDS_2536030320001
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_ISDS_2536030320001/WSEN_ISDS_2536030320001.c
  )
endif()

if(CONFIG_WSEN_ITDS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_ITDS_2533020201601
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_ITDS_2533020201601/WSEN_ITDS_2533020201601.c
  )
endif()

if(CONFIG_WSEN_PADS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_PADS_2511020213301
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_PADS_2511020213301/WSEN_PADS_2511020213301.c
  )
endif()

if(CONFIG_WSEN_PDUS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_PDUS_25131308XXX01
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_PDUS_25131308XXX01/WSEN_PDUS_25131308XXX01.c
  )
endif()

if(CONFIG_WSEN_TIDS)
  zephyr_include_directories(
    WeSensorsSDK/WSEN_TIDS_2521020222501
  )
  zephyr_library_sources(
    WeSensorsSDK/WSEN_TIDS_2521020222501/WSEN_TIDS_2521020222501.c
  )
endif()