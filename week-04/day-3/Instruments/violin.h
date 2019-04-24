//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H


#include "instrument.h"
#include "stringedInstruments.h"

class Violin : public StringedInstruments {
public:
    Violin();
    Violin(int numberOfStrings);
    std::string sound() override;
};


#endif //INSTRUMENTS_VIOLIN_H
