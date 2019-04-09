#include <iostream>
#include <string>
// std::string reverse(std::string text) - pass by value - másolat jön létre, eredeti nem változik
// std::string reverse(std::string& text) - pass by reference - eredeti változóba beleírhat
// std::string reverse(const std::string& text) - const reference - nem jön létre másolat, de csak read-only
std::string reverse(std::string& text);

int main(int argc, char* args[])
{
    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";

    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    return 0;
}

std::string reverse(std::string& text)
{
    //létrehozni belül egy másolatot, és azt swappolni, majd kiíratni?
    for (int i = 0; i < text.length(); ++i) {
        std::swap(text.at(i), text.at(text.length()-i-1));
    }
    std::cout << text;
}