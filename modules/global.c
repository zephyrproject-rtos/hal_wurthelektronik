/*
 ***************************************************************************************************
 * This file is part of WIRELESS CONNECTIVITY SDK for STM32:
 *
 *
 * THE SOFTWARE INCLUDING THE SOURCE CODE IS PROVIDED “AS IS”. YOU ACKNOWLEDGE THAT WÜRTH ELEKTRONIK
 * EISOS MAKES NO REPRESENTATIONS AND WARRANTIES OF ANY KIND RELATED TO, BUT NOT LIMITED
 * TO THE NON-INFRINGEMENT OF THIRD PARTIES’ INTELLECTUAL PROPERTY RIGHTS OR THE
 * MERCHANTABILITY OR FITNESS FOR YOUR INTENDED PURPOSE OR USAGE. WÜRTH ELEKTRONIK EISOS DOES NOT
 * WARRANT OR REPRESENT THAT ANY LICENSE, EITHER EXPRESS OR IMPLIED, IS GRANTED UNDER ANY PATENT
 * RIGHT, COPYRIGHT, MASK WORK RIGHT, OR OTHER INTELLECTUAL PROPERTY RIGHT RELATING TO ANY
 * COMBINATION, MACHINE, OR PROCESS IN WHICH THE PRODUCT IS USED. INFORMATION PUBLISHED BY
 * WÜRTH ELEKTRONIK EISOS REGARDING THIRD-PARTY PRODUCTS OR SERVICES DOES NOT CONSTITUTE A LICENSE
 * FROM WÜRTH ELEKTRONIK EISOS TO USE SUCH PRODUCTS OR SERVICES OR A WARRANTY OR ENDORSEMENT
 * THEREOF
 *
 * THIS SOURCE CODE IS PROTECTED BY A LICENSE.
 * FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
 * IN THE ROOT DIRECTORY OF THIS DRIVER PACKAGE.
 *
 * COPYRIGHT (c) 2025 Würth Elektronik eiSos GmbH & Co. KG
 *
 ***************************************************************************************************
 */

/**
 * @file
 * @brief Contains global function definitions for the Wireless Connectivity SDK for STM32.
 */

#include <global/global.h>
#include <string.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#ifdef __cplusplus
extern "C"
{
#endif

    /*              Functions              */

    /**
 * @brief Initialise the microcontroller and setup system clock 
 */

    void WE_Platform_Init(void)
    {
        return;
    }

    /**
 * @brief Disables the interrupts
 */
    void WE_Error_Handler(void)
    {
        return;
    }

    /**
 * @brief Initialises the pins
 *
 * @param[in] pins: pins to be initialised
 * @param[in] numPins: number of pins
 *
 * @return true if request succeeded,
 *         false otherwise
 */
    bool WE_InitPins(WE_Pin_t pins[], uint8_t numPins)
    {
        for (uint8_t i = 0; i < numPins; i++)
        {
            if (IS_WE_PIN_UNDEFINED(pins[i]))
            {
                /* Unused */
                continue;
            }

            const struct gpio_dt_spec zephyr_pin = (*(const struct gpio_dt_spec*)pins[i].pin_def);

            if (!gpio_is_ready_dt(&zephyr_pin)) {
                return false;
            }

            gpio_flags_t pin_config = GPIO_DISCONNECTED;

            switch(pins[i].type)
            {
                case WE_Pin_Type_Input:
                {
                    pin_config |= GPIO_INPUT;
                    break;
                }
                case WE_Pin_Type_Output:
                {
                    pin_config |= GPIO_OUTPUT_LOW;
                    break;
                }
                default:
                {
                    return false;
                }
            }

            if (gpio_pin_configure_dt(&zephyr_pin, pin_config) < 0) {
                return false;
	        }
            
        }

        return true;
    }

    bool WE_Reconfigure(WE_Pin_t pin)
    {
        return false;
    }

    /**
 * @brief Deinitialises the pin to their default reset values
 *
 * @param[in] pin: pin to be deinitialised
 *
 * @return true if request succeeded,
 *         false otherwise
 */
    bool WE_DeinitPin(WE_Pin_t pin)
    {
        if (IS_WE_PIN_UNDEFINED(pin))
        {
            return false;
        }

        const struct gpio_dt_spec zephyr_pin = (*(const struct gpio_dt_spec*)pin.pin_def);

        if (gpio_pin_configure_dt(&zephyr_pin, GPIO_DISCONNECTED) < 0) {
            return false;
        }

        return true;
    }

    /**
 * @brief Switch pin to output high/low
 *
 * @param[in] pin Output pin to be set
 * @param[in] out Output level to be set
 * @return true if request succeeded, false otherwise
 */

    bool WE_SetPin(WE_Pin_t pin, WE_Pin_Level_t out)
    {
        if (IS_WE_PIN_UNDEFINED(pin))
        {
            return false;
        }

        if(pin.type != WE_Pin_Type_Output)
        {
            return false;
        }

        const struct gpio_dt_spec zephyr_pin = (*(const struct gpio_dt_spec*)pin.pin_def);

        int value = 0;

        switch (out)
        {
            case WE_Pin_Level_High:
                value = 1;
                break;

            case WE_Pin_Level_Low:
                value = 0;
                break;

            default:
                return false;
        }

        if(gpio_pin_set_dt(&zephyr_pin, value) < 0)
        {
            return false;
        }

        return true;
    }

    /**
 * @brief Gets the pin level
 *
 * @param[in] pin: the pin to be checked
 *
 * @param[out] pin_levelP: the pin level
 *
 * @return true if request succeeded,
 *         false otherwise
 *         
 */
    bool WE_GetPinLevel(WE_Pin_t pin, WE_Pin_Level_t* pin_levelP)
    {
        if (IS_WE_PIN_UNDEFINED(pin) || (pin_levelP == NULL))
        {
            return false;
        }

        const struct gpio_dt_spec zephyr_pin = (*(const struct gpio_dt_spec*)pin.pin_def);

        int read_value = gpio_pin_get_dt(&zephyr_pin);

        if(read_value < 0)
        {
            return false;
        }

        *pin_levelP = ((read_value == 0) ? WE_Pin_Level_Low : WE_Pin_Level_High);

        return true;
    }

    /**
 * @brief Gets the Driver version
 *
 * @param[out] version: will contain the version value
 *
 * @return true if request succeeded,
 *         false otherwise        
 */
    bool WE_GetDriverVersion(uint8_t* version)
    {
        uint8_t help[3] = WE_WIRELESS_CONNECTIVITY_SDK_VERSION;
        memcpy(version, help, 3);
        return true;
    }

#ifdef __cplusplus
}
#endif
