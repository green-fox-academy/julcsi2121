#include <iostream>

void sumDigit (int n, int sum);

int main() {
    int n = 1234;
    int sum = 0;
    sumDigit(123456, sum);
    return 0;
}

void sumDigit (int n, int sum)
{
    if ( n == 0) {
        std::cout << "base condition " << sum << std::endl;
        return;
    } else {
        sum += n % 10;
        std::cout << "i'm in the else " << sum << std::endl;
        return sumDigit(n / 10, sum);
    }
}