//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef DEVICES_SCANNER_H
#define DEVICES_SCANNER_H

#include <iostream>
#include <string>

class Scanner {
public:
    Scanner(int speed);
    void scan();
    int _speed;
};


#endif //DEVICES_SCANNER_H
