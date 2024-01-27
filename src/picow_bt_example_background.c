/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "btstack_run_loop.h"
#include "pico/stdlib.h"
#include "picow_bt_example_common.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "ssd1306rp.h"

#define I2C_SDA 8
#define I2C_SCL 9
#define I2C_PORT i2c0
#define I2C_CLK 400 * 1000 // 400Khz
#define I2C_SSD1306_ADDRESS 0x3C

int main() {
    stdio_init_all();

    // useful information for picotool
    bi_decl(bi_2pins_with_func(I2C_SDA, I2C_SCL, GPIO_FUNC_I2C));
    bi_decl(bi_program_description("ancs client demo for the Raspberry Pi Pico w"));

    // I2C Initialisation.
    i2c_init(I2C_PORT, I2C_CLK);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    SSD1306Disp disp;

    // init
    ssd1306_init(&disp, SSD1306_WIDTH_128, SSD1306_HEIGHT_64,
                 I2C_SSD1306_ADDRESS, I2C_PORT);
    // clear
    ssd1306_clear(&disp);
    ssd1306_show(&disp);

    // draw char
    ssd1306_write_string(&disp, 20, 32, "Hello World.");
    ssd1306_show(&disp);

    int res = picow_bt_example_init();
    if (res){
        return -1;
    }

    picow_bt_example_main();
    btstack_run_loop_execute();
}
