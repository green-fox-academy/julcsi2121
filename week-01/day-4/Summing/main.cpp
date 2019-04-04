#include <iostream>
#include <string>

void sum(int finalNum);

int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter
    sum(4);
    return 0;
}

void sum(int finalNum)
{
    int sum = 0;
    for (int i = 0; i < finalNum + 1; ++i) {
        sum += i;
    }
    std::cout << "Your sum is: " << sum << std::endl;
}