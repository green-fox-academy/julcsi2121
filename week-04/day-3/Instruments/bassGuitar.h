//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H


#include "stringedInstruments.h"

class BassGuitar : public StringedInstruments {
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    std::string sound() override;
};


#endif //INSTRUMENTS_BASSGUITAR_H
