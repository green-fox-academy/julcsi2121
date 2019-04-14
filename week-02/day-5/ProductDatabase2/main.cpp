#include <iostream>
#include <map>
#include <vector>

int main() {
    //task1
    std::map<std::string, int> productDb = {
            {"eggs", 200},
            {"milk", 200},
            {"fish", 400},
            {"apples", 150},
            {"bread", 50},
            {"chicken", 550},
    };

    //task2
    std::vector<std::string> lessThan201;
    std::map<std::string, int>::iterator it = productDb.begin();
    for (; it != productDb.end(); ++it) {
        if (it->second < 300 == true) {
            lessThan201.push_back(it->first);
        }
    }
    std::cout << "Products with price below 201: ";
    for (unsigned int i = 0; i < lessThan201.size(); ++i) {
        std::cout << lessThan201.at(i) << ", ";
    }
    std::cout << std::endl;

    //task3
    std::map<std::string, int> moreThan150;
    it = productDb.begin();
    for (; it != productDb.end(); ++it) {
        if (it->second > 150 == true) {
            moreThan150.insert(std::make_pair(it->first, it->second));
        }
    }
    std::cout << "Products with price over 150: " << std::endl;
    it = moreThan150.begin();
    for (; it != moreThan150.end(); ++it) {
        std::cout << "\t - " << it->first << " - " << it->second << std::endl;
    }
    return 0;
}