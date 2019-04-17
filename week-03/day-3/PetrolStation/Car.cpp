//
// Created by Varga Júlia on 2019-04-17.
//

#include "Car.h"

Car::Car(int gasAmount, int capacity) {
    this->gasAmount = gasAmount;
    this->capacity = capacity;
}

bool Car::isFull() {
    if (this->capacity == this->gasAmount) {
        return true;
    } else {
        return false;
    }
}

void Car::fill() {
    this->gasAmount++;
}
