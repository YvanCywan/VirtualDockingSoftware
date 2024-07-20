/*
 * This source file was generated by the Gradle 'init' task
 */

#include <iostream>
#include "app.h"
#include <libusb-1.0/libusb.h>

int main () {
    libusb_context *ctx = nullptr;
    int ret = libusb_init(&ctx);

    if (ret > 0) {
        std::cerr << "Error Initialising libusb: " << libusb_error_name(ret) << std::endl;
        return 1;
    }

    libusb_exit(ctx);
    return 0;
}

