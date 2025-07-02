# Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(
  .
  SensorsSDK
)

zephyr_library_sources(
  weplatform.c
  weplatform_i2c.c
  weplatform_spi.c
)

if(CONFIG_WSEN_HIDS_2525020210001)
  zephyr_include_directories(
    SensorsSDK/WSEN_HIDS_2525020210001
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_HIDS_2525020210001/WSEN_HIDS_2525020210001.c
  )
endif()


if(CONFIG_WSEN_HIDS_2525020210002)
  zephyr_include_directories(
    SensorsSDK/WSEN_HIDS_2525020210002
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_HIDS_2525020210002/WSEN_HIDS_2525020210002.c
  )
endif()

if(CONFIG_WSEN_ITDS_2533020201601)
  zephyr_include_directories(
    SensorsSDK/WSEN_ITDS_2533020201601
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_ITDS_2533020201601/WSEN_ITDS_2533020201601.c
  )
endif()

if(CONFIG_WSEN_PADS_2511020213301)
  zephyr_include_directories(
    SensorsSDK/WSEN_PADS_2511020213301
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_PADS_2511020213301/WSEN_PADS_2511020213301.c
  )
endif()

if(CONFIG_WSEN_PDUS_25131308XXXXX)
  zephyr_include_directories(
    SensorsSDK/WSEN_PDUS_25131308XXX01
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_PDUS_25131308XXX01/WSEN_PDUS_25131308XXX01.c
  )
endif()

if(CONFIG_WSEN_TIDS_2521020222501)
  zephyr_include_directories(
    SensorsSDK/WSEN_TIDS_2521020222501
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_TIDS_2521020222501/WSEN_TIDS_2521020222501.c
  )
endif()

if(CONFIG_WSEN_ISDS_2536030320001)
  zephyr_include_directories(
    SensorsSDK/WSEN_ISDS_2536030320001
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_ISDS_2536030320001/WSEN_ISDS_2536030320001.c
  )
endif()


if(CONFIG_WSEN_GCDS_2526101040301)
  zephyr_include_directories(
    SensorsSDK/WSEN_GCDS_2526101040301
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_GCDS_2526101040301/WSEN_GCDS_2526101040301.c
  )
endif()


if(CONFIG_WSEN_PDMS_25131308XXX05)
  zephyr_include_directories(
    SensorsSDK/WSEN_PDMS_25131308XXX05
  )
  zephyr_library_sources(
    SensorsSDK/WSEN_PDMS_25131308XXX05/WSEN_PDMS_25131308XXX05.c
  )
endif()