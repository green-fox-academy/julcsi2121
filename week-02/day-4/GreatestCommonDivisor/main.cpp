#include <iostream>

void greatestCommonDivisor(int x, int y);

int main() {
    greatestCommonDivisor(84, 18);
    return 0;
}

void greatestCommonDivisor(int x, int y)
{
    if(y == 0) {
        std::cout << "Greatest common divisor is: " << x << std::endl;
        return;
    }else {
        return greatestCommonDivisor(y, x%y);
    }

}