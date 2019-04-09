#include <iostream>
#include <map>

int main() {
    //task1
    std::map<int, char> example;

    //task2
    if (example.empty() == true) {
        std::cout << "It's empty" << std::endl;
    } else {
        std::cout << "It's not empty" << std::endl;
    }

    //task3
    example[97] = 'a';
    example[98] = 'b';
    example[99] = 'c';
    example[65] = 'A';
    example[66] = 'B';
    example[67] = 'C';

    //task4
    std::map<int, char>::iterator it = example.begin();
    std::cout << "Keys:" << std::endl;
    for (; it != example.end(); ++it) {
        std::cout << it->first << std::endl;
    }

    //task5
    it = example.begin();
    std::cout << "Values:" << std::endl;
    for (; it != example.end(); ++it) {
        std::cout << it->second << std::endl;
    }

    //task6
    example[68] = 'D';

    //task7
    it = example.begin();
    int i = 0;
    for (; it != example.end(); ++it) {
        i++;
    }
    std::cout << "There are " << i << " key-value pairs in your map." << std::endl;

    //task8
    std::cout << "Value under key 99: " <<example[99] << std::endl;

    //task9
    it = example.begin();
    for (; it != example.end(); ++it) {
        if (it->first == 97) {
            example.erase(it);
        }
    }

    //task10
    if (example.count(100) == 0){
        std::cout << "There is no such key" << std::endl;
    } else {
        std::cout << "Key exists" << std::endl;
    }

    //task11
    example.clear();
    if (example.empty() == true) {
        std::cout << "It's empty" << std::endl;
    } else {
        std::cout << "It's not empty" << std::endl;
    }

    return 0;
}