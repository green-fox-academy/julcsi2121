#include <iostream>

int fibonacci(int n, int x);

int main() {
    int x = 0;
    int fib = fibonacci(5, x);
    std::cout << fib << std::endl;
    return 0;
}


int fibonacci(int n, int x )
{
    if (x == n){
        return 1;
    }
    else {
        std::cout << "Im here" << x << std::endl;
        return (fibonacci(x-1) + fibonacci(x-2));
    }
}