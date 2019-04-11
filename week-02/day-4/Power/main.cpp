#include <iostream>

int power(int base, int szam);

int main() {
    std::cout << power(2, 3) << std::endl;
    return 0;
}

int power(int base, int szam)
{
    if ( szam == 0){
        return 1;
    } else {
        return base * power(base, szam-1);
    }
}