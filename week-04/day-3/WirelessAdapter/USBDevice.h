//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H

#include "Device.h"

enum USBType{
    USB_TYPE_2,
    USB_TYPE_3
};


class USBDevice : virtual public Device {
public:
    USBDevice(std::string id, USBType type);
    std::string getType();
private:
    USBType _type;
};


#endif //WIRELESSADAPTER_USBDEVICE_H
