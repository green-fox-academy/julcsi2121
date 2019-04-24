//
// Created by Varga Júlia on 2019-04-24.
//

#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(std::string id, USBType type, int bandwidth) : NetworkDevice(id, bandwidth), USBDevice(id, type), Device(id) {}

void WirelessAdapter::info() {
    std::cout << "Your " << getType() << " wireless adapter's ID is: " << getID() << " with " << getBandwidth() << " bandwidth." << std::endl;
}