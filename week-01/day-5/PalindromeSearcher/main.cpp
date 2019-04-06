#include <iostream>

bool palindromeDecider(std::string substring, int size);
void substringFinder(std::string, int size);

/* --pseudo code ---
 * 1. function: palindrome decider
 *      -megnézi hogy egy string palindrome - e
 *      - palindrom = a string első fele egyezik a 2. felével megfordítva
 *      -return true vagy false
 * 2. function
 *      - find every substring of a string
 *      -mentse el a substringeket egy listába???
 *      -subtringek megtalálása: 1. for ciklus megadja a kezdőhelyet, a 2. for megadja a befejező helyet
 *      -pro example: "dog goat dad duck doodle never"
 */


int main() {
    std::string example = "Madam In Eden Im Adam";
    int size = example.length();
    bool palindrome = palindromeDecider(example, size);
    std::cout << palindrome;
    //substringFinder(example, size);
    return 0;
}

bool palindromeDecider(std::string substring, int size)
{
    for (int i = 0; i < size / 2; ++i) {
        if (substring[i] != substring[size-i-1]){
            std::cout << substring[i] << " " << substring[size-i-1] << std::endl;
            return false;
        }
    return true;
    }
}

void substringFinder(std::string example, int size)
{
    std::string palindromeSubStrings;
    for (int i = 0; i < size; ++i) {// counter starts from 1 calculate length of substring
        //std::cout << example[i];   //waiting the starting points
        for (int j = i; j < size; ++j) {
            //std::cout << example[i] << " " << example[j] << std::endl;  // waiting end points: a and t in this case
            std::string subString;
            for (int k = i; k <= j; ++k) {
                subString += example[k];
                //std::cout << example[k];
            }
            int subStringLength = subString.length();
            if(palindromeDecider(subString, subStringLength) == 1) {
                palindromeSubStrings += subString;
                palindromeSubStrings += ", ";
            }

        }

    }
    std::cout << palindromeSubStrings << std::endl;

}