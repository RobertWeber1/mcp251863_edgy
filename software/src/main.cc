/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "tusb_config.h"
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <cstdio>

int main() {
    stdio_usb_init();
    int i = 0;
    while (true) {
        printf("%d: Hello, world!\n", ++i);
        sleep_ms(1000);
    }
    return 0;
}
