#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int i;
    int temp;
    int sum;
    std::cout << "Tell me how many number do you want calculate with" << std::endl;
    std::cin >> i;

    for (int j = 0; j < i; ++j) {
        std::cout << "Give me the next number!" << std::endl;
        std::cin  >> temp;
        sum += temp;
    }
    std::cout << "Sum is: " << sum << ", and average is: " << sum / i << std::endl;

    return 0;
}