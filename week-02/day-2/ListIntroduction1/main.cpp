#include <iostream>
#include <vector>

int main() {
    //task1
    std::vector<std::string> names;
    //task2
    std::cout << "Length of list: " << names.size() << std::endl;
    //task3
    names.push_back("William");
    //task4
    if(names.empty() == true){
        std::cout << "It's empty!" << std::endl;
    }else{
        std::cout << "It's not empty!" << std::endl;
    }
    //task5
    names.push_back("John");
    //task6
    names.push_back("Amanda");
    //task7
    std::cout << "Length of list now: " << names.size() << std::endl;
    //task8
    std::cout << "3rd elementh is: " << names.at(2) << std::endl;
    //task9
    for (unsigned int i = 0; i !=names.size(); ++i) {
        std::cout << names.at(i) << std::endl;
    }
    //task10
    for (unsigned int i = 0; i !=names.size(); ++i) {
        std::cout << i+1 << ". " << names.at(i) << std::endl;
    }
    //task11
    names.erase(names.begin() + 1);
    //task12
    std::cout << "Length of list: " << names.size() << std::endl;
    for (unsigned int i = names.size(); i >= 1; --i) {    //unsigned i caused problems when reaching 0
        std::cout << names.at(i-1) << std::endl;
    }
    //task13
    names.clear();

    return 0;
}