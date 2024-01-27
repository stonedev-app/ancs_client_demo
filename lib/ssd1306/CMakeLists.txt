cmake_minimum_required(VERSION 3.13)

# library.
add_library(ssd1306_rp
    ssd1306rp/src/ssd1306rp.c
)

# Add the standard library to the build
target_link_libraries(ssd1306_rp
        pico_stdlib
)

# Add any user requested libraries
target_link_libraries(ssd1306_rp
        hardware_i2c
)

# Add the include files to the build
target_include_directories(ssd1306_rp PRIVATE
        ssd1306rp/include
)