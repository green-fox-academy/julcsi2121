//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H


class Car {
public:
    Car(int gasAmount, int capacity);
    bool isFull();
    void fill();

private:
    int gasAmount;
    int capacity;

};


#endif //PETROLSTATION_CAR_H
