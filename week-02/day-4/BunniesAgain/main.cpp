#include <iostream>

int bunnies(int bunny);

int main() {
    int count = 0;
    std::cout << "Total number of ears: " << bunnies(6) << std::endl;
    return 0;
}


int bunnies(int bunny)
{
    if (bunny <= 0) {
        return 0;
    } else if ( bunny % 2 ==0 ) {
        return 3 + bunnies(bunny - 1);
    } else {
        return 2 + bunnies(bunny - 1);


    }
}