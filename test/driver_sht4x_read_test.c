/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_sht4x_read_test.c
 * @brief     driver sht4x read test source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-06-25
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/06/25  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_sht4x_read_test.h"

static sht4x_handle_t gs_handle;        /**< sht4x handle */

/**
 * @brief     read test
 * @param[in] addr is the iic device address
 * @param[in] times is test times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t sht4x_read_test(sht4x_address_t addr, uint32_t times)
{
    uint8_t res;
    uint8_t num[4];
    uint32_t i;
    sht4x_info_t info;
    
    /* link functions */
    DRIVER_SHT4X_LINK_INIT(&gs_handle, sht4x_handle_t);
    DRIVER_SHT4X_LINK_IIC_INIT(&gs_handle, sht4x_interface_iic_init);
    DRIVER_SHT4X_LINK_IIC_DEINIT(&gs_handle, sht4x_interface_iic_deinit);
    DRIVER_SHT4X_LINK_IIC_READ_COMMAND(&gs_handle, sht4x_interface_iic_read_cmd);
    DRIVER_SHT4X_LINK_IIC_WRITE_COMMAND(&gs_handle, sht4x_interface_iic_write_cmd);
    DRIVER_SHT4X_LINK_DELAY_MS(&gs_handle, sht4x_interface_delay_ms);
    DRIVER_SHT4X_LINK_DEBUG_PRINT(&gs_handle, sht4x_interface_debug_print);
    
    /* sht4x info */
    res = sht4x_info(&info);
    if (res != 0)
    {
        sht4x_interface_debug_print("sht4x: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        sht4x_interface_debug_print("sht4x: chip is %s.\n", info.chip_name);
        sht4x_interface_debug_print("sht4x: manufacturer is %s.\n", info.manufacturer_name);
        sht4x_interface_debug_print("sht4x: interface is %s.\n", info.interface);
        sht4x_interface_debug_print("sht4x: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        sht4x_interface_debug_print("sht4x: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        sht4x_interface_debug_print("sht4x: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        sht4x_interface_debug_print("sht4x: max current is %0.2fmA.\n", info.max_current_ma);
        sht4x_interface_debug_print("sht4x: max temperature is %0.1fC.\n", info.temperature_max);
        sht4x_interface_debug_print("sht4x: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start read test */
    sht4x_interface_debug_print("sht4x: start read test.\n");
    
    /* set address */
    res = sht4x_set_addr(&gs_handle, addr);
    if (res != 0)
    {
        sht4x_interface_debug_print("sht4x: set addr failed.\n");
       
        return 1;
    }
    
    /* sht4x init */
    res = sht4x_init(&gs_handle);
    if (res != 0)
    {
        sht4x_interface_debug_print("sht4x: init failed.\n");
       
        return 1;
    }
    
    /* get serial number */
    res = sht4x_get_serial_number(&gs_handle, num);
    if (res != 0)
    {
        sht4x_interface_debug_print("sht4x: get serial number failed.\n");
        (void)sht4x_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    sht4x_interface_debug_print("sht4x: serial number is 0x%02X 0x%02X 0x%02X 0x%02X.\n", num[0], num[1], num[2], num[3]);
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: high precision without heater.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_NO_HEATER,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: medium precision without heater.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_MEDIUM_PRECISION_WITH_NO_HEATER,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: lowest precision without heater.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_LOWEST_PRECISION_WITH_NO_HEATER,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 200mW for 1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_200MW_1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 200mW for 0.1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_200MW_0P1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 110mW for 1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_110MW_1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 110mW for 0.1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_110MW_0P1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 20mW for 1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_20MW_1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* wait 1000 ms */
    sht4x_interface_delay_ms(1000);
    
    /* output */
    sht4x_interface_debug_print("sht4x: activate heater with 20mW for 0.1s, high precision.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        uint16_t temperature_raw;
        float temperature_s;
        uint16_t humidity_raw;
        float humidity_s;
        
        /* read data */
        res = sht4x_read(&gs_handle, SHT4X_MODE_HIGH_PRECISION_WITH_HEATER_20MW_0P1S,
                        (uint16_t *)&temperature_raw, (float *)&temperature_s,
                        (uint16_t *)&humidity_raw, (float *)&humidity_s);
        if (res != 0)
        {
            sht4x_interface_debug_print("sht4x: read failed.\n");
            (void)sht4x_deinit(&gs_handle);
            
            return 1;
        }
        sht4x_interface_debug_print("sht4x: temperature is %0.2fC.\n", temperature_s);
        sht4x_interface_debug_print("sht4x: humidity is %0.2f%%.\n", humidity_s);
    
        /* wait 1000 ms */
        sht4x_interface_delay_ms(1000);
    }
    
    /* output */
    sht4x_interface_debug_print("sht4x: soft reset.\n");
    
    /* soft reset */
    res = sht4x_soft_reset(&gs_handle);
    if (res != 0)
    {
        sht4x_interface_debug_print("sht4x: soft reset failed.\n");
        (void)sht4x_deinit(&gs_handle);
        
        return 1;
    }
    
    /* finish read test */
    sht4x_interface_debug_print("sht4x: finish read test.\n");
    (void)sht4x_deinit(&gs_handle);

    return 0;
}
