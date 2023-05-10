# Copyright (c) 2023 Würth Elektronik eiSos GmbH & Co. KG
# SPDX-License-Identifier: Apache-2.0

# Hardware Abstraction Layer for WE sensors
add_subdirectory_ifdef(CONFIG_HAS_WESENSORS sensors)
