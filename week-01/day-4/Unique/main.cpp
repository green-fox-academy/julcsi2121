#include <iostream>
#include <string>

void unique(int numbers[], int size);

int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    //  Example
    int size;
    std::cout << "Give me a number - this is going to be the length of your list." << std::endl;
    std::cin >> size;

    int numbers[size];
    std::cout << "Now add the numbers one by one." << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i+1 << " : ";
        std::cin >> numbers[i];
    }
    unique(numbers, size);
    //  should print: `[1, 11, 34, 52, 61]`

    return 0;
}


void unique(int numbers[], int size) {
    int newNumbers[size];
    for (int l = 0; l < size; ++l) {   // creates a list filled with zeros
        newNumbers[l] = 0;
    }
    //filling the new list with values
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (newNumbers[j] == numbers[i]) {   //if the element is already in the new list, jump to next element
                break;
            } else if (newNumbers[j] == 0) {  // originally, if the jth value was 0, add the new number
                newNumbers[j] = numbers[i];
                break; // break is needed, if j is not i-1, otherwise it will duplicate the value of index j
            }
        }
    }
    //printing out new list
    std::cout << "Unique list:" << std::endl;
    for (int k = 0; k < size ; ++k) {
        if(newNumbers[k] != 0) {   //condition is needed, because it writes out zeros to the end
            std::cout << newNumbers[k] << std::endl;
        }
    }
}