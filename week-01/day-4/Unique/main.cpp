#include <iostream>
#include <string>

void unique(int numbers[], int size);

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    unique(numbers, 8);
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}


void unique(int numbers[], int size) {
    int newNumbers[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (newNumbers[j] == numbers[i]) {
                break;
            } else if (newNumbers[j] == 0) {
                newNumbers[j] = numbers[i];
                break;
            }
        }
    }
    for (int k = 0; k < size ; ++k) {
        if(newNumbers[k] != 0) {
            std::cout << newNumbers[k] << std::endl;
        }
    }
}