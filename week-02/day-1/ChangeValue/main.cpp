#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    std::cout <<  "Value of temperature is: " << temperature << std::endl;
    float *pointerOfTemperature = &temperature;
    *pointerOfTemperature = 24.5;
    std::cout <<  "New value of temperature is: " << *pointerOfTemperature << std::endl;

    return 0;
}