#include <iostream>

int numberAdder(int n, int sum);

int main() {
    numberAdder(5, 0);
    return 0;
}

int numberAdder(int n, int sum) {
    if (n < 1) {
        std::cout << "Sum is: " << sum << std::endl;
        return 1;
    }
    sum += n;
    numberAdder(n-1, sum);
}