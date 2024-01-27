#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "ssd1306rp.h"

#include "ansc_client_display.h"

// I2S define
#define ANSC_CLIENT_I2C_SDA 8
#define ANSC_CLIENT_I2C_SCL 9
#define ANSC_CLIENT_I2C_PORT i2c0
#define ANSC_CLIENT_I2C_CLK 400 * 1000 // 400Khz
#define ANSC_CLIENT_I2C_SSD1306_ADDRESS 0x3C

// SSD1306 Display
static SSD1306Disp disp;

/// @brief Display init
void ansc_display_init()
{
    // useful information for picotool
    bi_decl(bi_2pins_with_func(
        ANSC_CLIENT_I2C_SDA, 
        ANSC_CLIENT_I2C_SCL, 
        GPIO_FUNC_I2C)
    );

    // I2C Initialisation.
    i2c_init(ANSC_CLIENT_I2C_PORT, ANSC_CLIENT_I2C_CLK);
    gpio_set_function(ANSC_CLIENT_I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(ANSC_CLIENT_I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(ANSC_CLIENT_I2C_SDA);
    gpio_pull_up(ANSC_CLIENT_I2C_SCL);

    // init
    ssd1306_init(
        &disp, 
        SSD1306_WIDTH_128, SSD1306_HEIGHT_64,
        ANSC_CLIENT_I2C_SSD1306_ADDRESS, ANSC_CLIENT_I2C_PORT);

    // clear
    ssd1306_clear(&disp);
    ssd1306_show(&disp);
}

/// @brief Show string
/// @param str string
void ansc_display_string(char *str)
{
    // draw char
    ssd1306_write_string(&disp, 5, 32, str);
    ssd1306_show(&disp);
}