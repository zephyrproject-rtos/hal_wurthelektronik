# Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
# SPDX-License-Identifier: Apache-2.0

# Hardware Abstraction Layer for WE sensors
if(CONFIG_HAS_WESENSORS OR CONFIG_HAS_WEMODULES)
    add_subdirectory(common)
endif()
add_subdirectory_ifdef(CONFIG_HAS_WESENSORS sensors)
add_subdirectory_ifdef(CONFIG_HAS_WEMODULES modules)
