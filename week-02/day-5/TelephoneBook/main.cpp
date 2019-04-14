#include <iostream>
#include <map>

int main() {
    //task1
    std::map<std::string, std::string> telephoneBook = {
            {"William A. Lathan", "405-709-1865"},
            {"John K. Miller", "402-247-8568"},
            {"Hortensia E. Foster", "606-481-6467"},
            {"Amanda D. Newland", "319-243-5613"},
            {"Brooke P. Askew", "307-687-2982"},
    };

    //task2
    std::cout << "John K. Miller's phone number: " << telephoneBook["John K. Miller"] << std::endl;

    //task3
    std::map<std::string, std::string>::iterator it = telephoneBook.begin();
    for (; it != telephoneBook.end(); ++it) {
        if (it->second == "307-687-2982") {
            std::cout << "Number " << it->second << " belongs to: " << it->first << std::endl;
        }
    }

    //task4
    if (telephoneBook.count("Chris E. Myers") == 0) {
        std::cout << "There is no entry belonging to Chris E. Myers." << std::endl;
    } else {
        std::cout << "Chris E. Myers has at least one entry in the telephone book." << std::endl;
    }
    return 0;
}