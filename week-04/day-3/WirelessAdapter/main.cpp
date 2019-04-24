#include <iostream>
#include "WirelessAdapter.h"
#include "NetworkDevice.h"
#include "USBDevice.h"
#include "Device.h"

int main() {
    WirelessAdapter adapter("da4c32fb21", USB_TYPE_2, 100);
    adapter.info();
    return 0;
}