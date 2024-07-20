#include <ctime>
#include <string>
#include <iostream>
#include <libusb-1.0/libusb.h>


int main(int argc, char** argv) {
    libusb_device **devs;
    libusb_context *ctx = NULL;
    int r;
    ssize_t cnt;

    // Initialize the libusb library
    r = libusb_init(&ctx);
    if (r < 0) {
        fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(r));
        return 1;
    }

    // Set verbosity level to 3, as suggested in the documentation
    libusb_set_debug(ctx, 3);

    // Get the list of USB devices
    cnt = libusb_get_device_list(ctx, &devs);
    if (cnt < 0) {
        fprintf(stderr, "Error getting device list: %s\n", libusb_error_name(cnt));
        return 1;
    }

    printf("Devices Found: %ld\n", cnt);

    // Iterate through the list of devices and print details
    for (ssize_t i = 0; i < cnt; i++) {
        libusb_device *dev = devs[i];
        struct libusb_device_descriptor desc;

        if (libusb_get_device_descriptor(dev, &desc) < 0) {
            fprintf(stderr, "Error getting device descriptor\n");
            continue;
        }

        printf("Device %ld: Vendor ID: %04x, Product ID: %04x\n", i, desc.idVendor, desc.idProduct);
    }

    // Free the list of devices
    libusb_free_device_list(devs, 1);

    // Deinitialize libusb
    libusb_exit(ctx);

    return 0;
}
