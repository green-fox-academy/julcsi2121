//
// Created by Varga Júlia on 2019-04-24.
//

#include "stringedInstruments.h"


void StringedInstruments::play() {
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}
