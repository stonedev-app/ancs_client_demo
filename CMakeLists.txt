# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(ancs_client_demo C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Specified the source folder
file(GLOB SOURCES "src/*.c")

# Add executable. Default name is the project name, version 0.1

add_executable(ancs_client_demo
      ${SOURCES}
)

pico_set_program_name(ancs_client_demo "ancs_client_demo")
pico_set_program_version(ancs_client_demo "0.1")

pico_enable_stdio_uart(ancs_client_demo 1)
pico_enable_stdio_usb(ancs_client_demo 0)

# Add the standard library to the build
target_link_libraries(ancs_client_demo
        pico_stdlib
        pico_btstack_ble
        pico_btstack_classic #not needed for BLE only demos
        pico_btstack_cyw43
        pico_cyw43_arch_none
)

# Create gatt header file 
pico_btstack_make_gatt_header(ancs_client_demo PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/ancs_client_demo.gatt")

# Add the include files to the build
target_include_directories(ancs_client_demo PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/lib/ssd1306/ssd1306rp/include
)

# Add subdirectory
add_subdirectory(lib/ssd1306)

# Add any user requested libraries
target_link_libraries(ancs_client_demo 
        ssd1306_rp
)

pico_add_extra_outputs(ancs_client_demo)

