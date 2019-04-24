#include <iostream>
#include "WirelessAdapter.h"
#include "NetworkDevice.h"
#include "USBDevice.h"
#include "Device.h"


int main() {
    WirelessAdapter adapter("da4c32fb21", USBType::USB_TYPE_3, 100);
    adapter.info();
    USBDevice device("idnfd", USBType::USB_TYPE_2);
    std::cout << device.getType();
    return 0;
}