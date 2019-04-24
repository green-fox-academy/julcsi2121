//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef WIRELESSADAPTER_DEVICE_H
#define WIRELESSADAPTER_DEVICE_H

#include <iostream>
#include <string>


class Device {
public:
    Device(std::string id);
    std::string getID();
private:
    std::string _id;
};


#endif //WIRELESSADAPTER_DEVICE_H
