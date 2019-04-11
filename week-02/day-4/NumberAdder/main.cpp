#include <iostream>

int numberAdder(int n);

int main() {
    std::cout << numberAdder(5) << std::endl;
    return 0;
}

int numberAdder(int n) {
    if (n < 1) {
        return 0;
    } else {
        return n + numberAdder(n - 1);
    }
}