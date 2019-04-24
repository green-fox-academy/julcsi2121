//
// Created by Varga Júlia on 2019-04-24.
//

#include "USBDevice.h"


USBDevice::USBDevice(std::string id, USBType type) : Device(id) {
    _type = type;
}

std::string USBDevice::getType() {
    if (_type == USB_TYPE_2) {
        return "USB Type 2";
    } else {
        return "USB Type 3";
    }
}