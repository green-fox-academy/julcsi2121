#include <iostream>
#include <vector>

int main() {
    //task1
    std::vector<std::string> listA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

    //task2
    std::vector<std::string> listB;
    for (unsigned int i =0; i < listA.size(); ++i) {
        listB.push_back(listA.at(i));
        //std::cout << listB.at(i) << std::endl;
    }

    //task3
    std::vector<std::string>::iterator itA = listA.begin();
    for (; itA != listA.end(); ++itA) {
        if (*itA == "Durian"){
            std::cout << "It contains Durian!" << std::endl;
        }
    }

    //task4
    std::vector<std::string>::iterator itB = listB.begin();
    for (; itB != listB.end(); ++itB) {
        if (*itB == "Durian"){
            listB.erase(itB);
        }
    }

    std::cout << "List B after erasing Durian: " << std::endl;
    itB = listB.begin();
    for (; itB != listB.end(); ++itB) {
        std::cout << *itB << std::endl;
    }

    //task5
    listA.insert(listA.begin() + 4, "Kiwifruit");
    std::cout << "List A after adding Kiwi:" << std::endl;
    itA = listA.begin();
    for (; itA != listA.end(); ++itA) {
        std::cout << *itA << std::endl;
    }

    //task6
    if (listA.size() < listB.size()) {
        std::cout << "List B is bigger, it's size is: " << listB.size() << std::endl;
    } else if (listB.size() < listA.size()) {
        std::cout << "List A is bigger, it's size is: " << listA.size() << std::endl;
    } else {
        std::cout << "They're equal!" << std::endl;
    }

    //task7
    for (unsigned int j = 0; j < listA.size()-1; ++j) {
        if(listA.at(j) == "Avocado") {
            std::cout << "Index of avocado: " << j << std::endl;
        }
    }

    //task8: durian is already deleted from List B!

    //task9
    listB.insert(listB.end(), {"Passion Fruit", "Pummelo"});
    std::cout << "Appended List B: " << std::endl;
    itB = listB.begin();
    for (; itB != listB.end(); ++itB) {
        std::cout << *itB << std::endl;
    }


    return 0;
}