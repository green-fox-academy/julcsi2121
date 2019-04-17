//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
private:
    int value;
    int initialValue;
public:
    Counter();
    Counter(int value);
    int get();
    void setValue(int value);
    void add();
    void add(int number);
    void reset();

};


#endif //COUNTER_COUNTER_H
