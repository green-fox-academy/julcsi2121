#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    //adat bekérése
    int row;
    int column;
    std::cout << "How many rows would you like?" << std::endl;
    std::cin >> row;
    std::cout << "How many columns would you like?" << std::endl;
    std::cin >> column;

    //mátrix kitöltése
    int twoDimensionalMatrix[row][column];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if(j ==i) {
                twoDimensionalMatrix[i][j] = 1;
            }else {
                twoDimensionalMatrix[i][j] = 0;
            }
        }
    }

    //mátrix kiírása
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << twoDimensionalMatrix[i][j];
        }
        std::cout << std::endl;
    }


    return 0;
}