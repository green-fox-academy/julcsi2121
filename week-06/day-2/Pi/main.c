#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

float area_of_circle(int radius);

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

int main()
{
    float result = area_of_circle(2);
    printf("Area of circle is: %.2f", result);

    return 0;
}

float area_of_circle(int radius)
{
    float result = PI * radius * radius;
    return result;
}