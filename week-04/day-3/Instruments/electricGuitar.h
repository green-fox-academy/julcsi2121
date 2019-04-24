//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H


#include "stringedInstruments.h"

class ElectricGuitar : public StringedInstruments {
public:
    ElectricGuitar();
    ElectricGuitar(int numberOfStrings);
    std::string sound() override;

};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
