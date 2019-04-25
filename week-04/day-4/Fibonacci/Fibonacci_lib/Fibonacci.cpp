//
// Created by Varga Júlia on 2019-04-25.
//

#include "Fibonacci.h"

int fibonacci(int x)
{
    if (x == 1 || x == 0){
        return x;
    } else if (x < 0) {
        return -1;
    } else {
        return (fibonacci(x-1)+fibonacci(x-2));
    }
}