#include <iostream>
#include <map>

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
    std::cout << "Price of fish: " << productDb["fish"] << std::endl;

    //task3
    std::map<std::string, int>::iterator it = productDb.begin();
    int maxValue = 0;
    std::string maxKey = "";
    for (; it != productDb.end(); ++it) {
        if (it->second >= maxValue) {
            maxValue = it->second;
            maxKey = it->first;
        }
    }
    std::cout << "Product with maximum value: " << maxKey << std::endl;

    //task4
    int sum = 0;
    it = productDb.begin();
    for (; it != productDb.end(); ++it) {
        sum += it->second;
    }
    std::cout << "Sum is: " << sum / productDb.size() << std::endl;

    //task5
    int count = 0;
    it = productDb.begin();
    for (; it != productDb.end(); ++it) {
        if (it->second < 300 == true) {
            count++;
        }
    }
    std::cout << "Number of products with price below 300: " << count << std::endl;

    //task6
    it = productDb.begin();
    bool priceOf125 = false;
    for (; it != productDb.end(); ++it) {
        if (it->second == 125) {
            priceOf125 = true;
        }
    }
    if (priceOf125 == true) {
        std::cout << "There is a product with price of 125." << std::endl;
    } else {
        std::cout << "There is no product with price of 125." << std::endl;
    }

    //task7
    it = productDb.begin();
    int minValue = maxValue;
    std::string minKey = "";
    for (; it != productDb.end(); ++it) {
        if (it->second <= minValue) {
            minValue = it->second;
            minKey = it->first;
        }
    }
    std::cout << "Product with minimum value: " << minKey << std::endl;

    return 0;
}