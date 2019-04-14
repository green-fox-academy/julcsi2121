#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    //task1
    std::vector<std::string> shoppingList = {"eggs", "milk", "fish", "apples", "bread", "chicken"};

    //task2
    if (std::find(shoppingList.begin(), shoppingList.end(), "milk") != shoppingList.end()) {
        std::cout << "There is milk on the list!" << std::endl;
    } else {
        std::cout << "There is no milk on the list!" << std::endl;
    }

    //task3
    if (std::find(shoppingList.begin(), shoppingList.end(), "bananas") != shoppingList.end()) {
        std::cout << "There is bananas on the list!" << std::endl;
    } else {
        std::cout << "There is no bananas on the list!" << std::endl;
    }

    return 0;
}