//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H

#include "NetworkDevice.h"
#include "USBDevice.h"


class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
    WirelessAdapter(std::string id, USBType type, int bandwidth);
    void info();
};


#endif //WIRELESSADAPTER_WIRELESSADAPTER_H
