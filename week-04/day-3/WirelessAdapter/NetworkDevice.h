//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H

#include "Device.h"


class NetworkDevice : virtual public Device {
public:
    NetworkDevice(std::string id, int bandwidth);
    int getBandwidth();
private:
    int _bandwidth;
};


#endif //WIRELESSADAPTER_NETWORKDEVICE_H
