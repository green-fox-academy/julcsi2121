#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int numbers[5];
    for (int i = 0; i < 5; ++i) {
        std::cout << "Write your " << i+1 << ". number:";
        std::cin >> numbers[i];
    }
    int sum;
    for (int j = 0; j < 5; ++j) {
        sum += numbers[j];
    }
    std::cout << "Sum is: " << sum << "and average is: " << sum / 5 << std::endl;

    return 0;
}