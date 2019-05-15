#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;
    computer.bits = 8;
    computer.ram_size_GB = 1;
    computer.cpu_speed_GHz = 1.7;
    printf("My computer has a %.2f Hz CPU, %d GB of RAM and %d bits\n", computer.cpu_speed_GHz, computer.ram_size_GB, computer.bits);

    Notebook notebook;
    notebook.cpu_speed_GHz = 2.3;
    notebook.ram_size_GB = 4;
    notebook.bits = 4;
    printf("My Notebook has a %.2f Hz CPU, %d GB of RAM and %d bits\n", notebook.cpu_speed_GHz, notebook.ram_size_GB, notebook.bits);

    return 0;
}