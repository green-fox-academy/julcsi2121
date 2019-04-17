//
// Created by Varga Júlia on 2019-04-17.
//

#include "Counter.h"

Counter::Counter() {
    initialValue = 0;
    value = 0;
}

Counter::Counter(int value) {
    this->initialValue = value;
    this->value = value;
}

int Counter::get() {
    return value;
}

void Counter::setValue(int value) {
    this->value = value;
}

void Counter::add(){
    this->value++;
}
void Counter::add(int number) {
    this->value += number;
}
void Counter::reset(){
    value = initialValue;
}