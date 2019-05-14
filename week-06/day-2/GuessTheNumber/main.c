#include <stdio.h>

int main() {
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8

    int goal_number = 12;
    int guess;

    while (guess != goal_number) {
        printf("Make a guess!\n");
        scanf("%d", &guess);

        if(guess > goal_number) {
            printf("The stored number is lower\n");
        } else if (goal_number > guess) {
            printf("The stored number is higher\n");
        }
    }

    printf("You found the number: %d", guess);

    return 0;
}