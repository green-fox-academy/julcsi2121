//
// Created by Varga Júlia on 2019-04-24.
//

#include "USBDevice.h"


USBDevice::USBDevice(std::string id, USBType type) : Device(id) {
    _type = type;
}

std::string USBDevice::getType() {
    if (_type == USBType::USB_TYPE_2) {
        return "Type 2";
    } else {
        return "Type 3";
    }
}