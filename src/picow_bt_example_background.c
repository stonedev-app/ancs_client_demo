/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "btstack_run_loop.h"
#include "pico/stdlib.h"
#include "picow_bt_example_common.h"
#include "pico/binary_info.h"

#include "ansc_client_display.h"

int main() {
    stdio_init_all();

    // useful information for picotool
    bi_decl(bi_program_description("ancs client demo for the Raspberry Pi Pico w"));

    // display init
    ansc_display_init();
    // Starting up
    ansc_display_string("Starting up.");

    int res = picow_bt_example_init();
    if (res){
        // Startup failure
        ansc_display_string("Failure.");
        return -1;
    }

    // Startup successful
    ansc_display_string("Successful.");

    picow_bt_example_main();
    btstack_run_loop_execute();
}
