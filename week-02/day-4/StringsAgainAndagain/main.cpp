#include <iostream>
#include <string>

void strings(std::string example);

int main() {
    std::string example = "remmmove";
    strings(example);
    return 0;
}
void strings(std::string example)
{
    int size = example.size();
    if ( size <= 0) {
        return;
    } else if ( example.substr(0, 1) == example.substr(1, 1)) {
        std::cout << example.substr(0, 1) << "*";
        strings(example.substr(1, size-1));
    } else {
        std::cout << example.substr(0, 1);
        strings(example.substr(1, size-1));
    }
}