#include <iostream>

int bunnies(int bunny);

int main() {
    int count = 0;
    std::cout << "Total number of bunny-ears: " << bunnies(4) << std::endl;
    return 0;
}

int bunnies(int bunny)
{
    if( bunny <= 0){
        return 0;

    } else {
        return 2 + bunnies(bunny-1);
    }
}