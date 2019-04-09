#include <iostream>
#include <map>

int main() {
    //task1
    std::map<std::string, std::string> example;
    example["978-1-60309-452-8"] = "A letter to Jo";
    example["978-1-60309-459-7"] = "Lupus";
    example["978-1-60309-444-3"] = "Red Panda and Moon Bear";
    example["978-1-60309-461-0"] = "The Lab";

    //task2
    std::map<std::string, std::string>::iterator it = example.begin();
    for (; it !=example.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first <<")" << std::endl;
    }

    //task3
    it = example.begin();
    for (; it !=example.end(); ++it) {
        if(it->first == "978-1-60309-444-3"){
            example.erase(it);
        }
    }

    std::cout << "After 1st deletion:" << std::endl;
    it = example.begin();
    for (; it !=example.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first <<")" << std::endl;
    }

    //task4
    it = example.begin();
    for (; it !=example.end(); ++it) {
        if(it->second == "The Lab"){
            example.erase(it);
        }
    }

    std::cout << "After 2nd deletion:" << std::endl;
    it = example.begin();
    for (; it !=example.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first <<")" << std::endl;
    }

    //task5
    example["978-1-60309-450-4"] = "They Called Us Enemy";
    example["978-1-60309-453-5"] = "Why Did We Trust Him?";

    std::cout << "After addition:" << std::endl;
    it = example.begin();
    for (; it !=example.end(); ++it) {
        std::cout << it->second << " (ISBN: " << it->first <<")" << std::endl;
    }

    //task6
    if(example.count("478-0-61159-424-8") == 1) {
        std::cout << "It's int the map!" << std::endl;
    }else {
        std::cout << "It not in the map." << std::endl;
    }

    //task7
    std::cout << "The book you're looking for: " << example["978-1-60309-453-5"] << std::endl;


    return 0;
}