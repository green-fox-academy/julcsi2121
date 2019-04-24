//
// Created by Varga Júlia on 2019-04-24.
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENTS_H
#define INSTRUMENTS_STRINGEDINSTRUMENTS_H

#include "instrument.h"


class StringedInstruments : public Instrument {
public:
    virtual std::string sound() = 0;
    void play() override;
protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENTS_H
