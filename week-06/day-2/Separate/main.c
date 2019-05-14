#include <stdio.h>
#include <stdlib.h>
#include "header.h"



int main()
{
    float result = area_of_circle(2);
    printf("Area of circle is: %.2f\n", result);

    float result2 = calculate_circumference(2);
    printf("Circumference of circle is: %.2f\n", result2);

    return 0;
}

float area_of_circle(int radius)
{
    float result = PI * radius * radius;
    return result;
}

float calculate_circumference(int radius)
{
    float result = PI * radius * 2;
    return result;
}