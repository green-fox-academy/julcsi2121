#include <stdio.h>
#include <stdlib.h>

int is_old_enough(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("Give me your age\n");
    scanf("%d", &age);

    if (is_old_enough(age)) {
        printf("You are old enough to buy alcohol legally");
    } else {
        printf("You are not old enough to buy alcohol legally");
    }

    return 0;
}

int is_old_enough(int age)
{
    if (age >= 18) {
        return 1;
    } else {
        return 0;
    }

}