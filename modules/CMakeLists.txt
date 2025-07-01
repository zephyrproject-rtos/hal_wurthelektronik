# Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(
  .
  WCON_Drivers
)

zephyr_library_sources(
  debug.c
  global.c
  WCON_Drivers/global/ATCommands.c
)

if(CONFIG_WSEN_DAPHNISI)
  zephyr_library_sources(
    WCON_Drivers/DaphnisI/DaphnisI.c
    WCON_Drivers/DaphnisI/ATCommands/ATCommon.c
    WCON_Drivers/DaphnisI/ATCommands/ATDevice.c
    WCON_Drivers/DaphnisI/ATCommands/ATUserSettings.c
    WCON_Drivers/DaphnisI/ATCommands/P2P.c
  )
endif()


