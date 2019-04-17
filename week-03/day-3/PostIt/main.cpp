#include <iostream>
#include "PostIt.h"

int main() {
    PostIt postIt1("orange", "Idea1", "blue");
    PostIt postIt2("pink", "Awesome", "black");
    PostIt postIt3("yellow", "Superb", "green");
    std::cout << postIt1.print() << std::endl;
    std::cout << postIt2.print() << std::endl;
    std::cout << postIt3.print() << std::endl;
    return 0;
}