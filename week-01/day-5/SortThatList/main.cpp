#include <iostream>
#include <string>

void bubbleSort(int list[], int size);
void reverseBubbleSort(int list[], int size);
bool choose(bool value, int list[], int size);

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending

 int main(int argc, char* args[])
{

    int size;
    std::cout << "Give me the size of your array" << std::endl;
    std::cin >> size;
    int list[size];
    std::cout << "Now give the elements of the array one by one" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << ". elementh: ";
        std::cin >> list[i];
    }
    bool descendingOrder;
    std::cout << "Do you want descending order? Please answer with 1 for true and 0 for false.";
    std::cin >> descendingOrder;

    choose(descendingOrder, list, size);

    return 0;
}

void bubbleSort(int list[], int size) {
     //sort:
    for (int l = 0; l < size; ++l) {
         std::cout << "This is the start of an outer cycle" << std::endl;
        for (int j = 0; j < size-1 ; ++j) {
            if (list[j] > list[j + 1]) {
                list[j] = list[j] - list[j + 1];
                list[j + 1] = list[j] + list[j + 1];
                list[j] = list[j + 1] - list[j];
            }
            for (int k = 0; k < size; ++k) {
                std::cout << list[k] << " ";
            }
            std::cout << std::endl;
        }
     }
    //print:
     std::cout << "Sorted list: " << std::endl;
     for (int k = 0; k < size ; ++k) {
        std::cout << list[k] << std::endl;
    }
 }

void reverseBubbleSort(int list[], int size) {
    //sort:
    for (int l = 0; l < size; ++l) {
        std::cout << "This is the start of an outer cycle" << std::endl;
        for (int j = 0; j < size-1 ; ++j) {
            if (list[j] < list[j + 1]) {
                list[j] = list[j] - list[j + 1];
                list[j + 1] = list[j] + list[j + 1];
                list[j] = list[j + 1] - list[j];
            }
            for (int k = 0; k < size; ++k) {
                std::cout << list[k] << " ";
            }
            std::cout << std::endl;
        }
    }
    //print:
    std::cout << "Sorted list: " << std::endl;
    for (int k = 0; k < size ; ++k) {
        std::cout << list[k] << std::endl;
    }
}

bool choose(bool value, int list[], int size)
{
     if (value == true){
         reverseBubbleSort(list, size);
     } else{
         bubbleSort(list, size);
     }
}