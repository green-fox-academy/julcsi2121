#include <stdio.h>

int main() {
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    int a;
    int b;
    int c;

    printf("Give me the size of a!\n");
    scanf("%d", &a);

    printf("Give me the size of b!\n");
    scanf("%d", &b);

    printf("Give me the size of c!\n");
    scanf("%d", &c);

    printf("Cuboid's volume: %d\n", a * b * c);
    printf("Cuboid's surface area: %d", ((a * b) + (a * c) + (b * c)) * 2);

    return 0;
}