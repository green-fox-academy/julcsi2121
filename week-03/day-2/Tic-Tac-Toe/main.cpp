#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    //std::cout << ticTacResult("../win-o.txt") << std::endl;
    // should print O

    //std::cout << ticTacResult("../win-x.txt") << std::endl;
    // should print X

    //std::cout << ticTacResult("../draw.txt") << std::endl;
    // should print draw


    std::vector<std::vector<char>> gameResult;

    std::ifstream result;
    result.open("../win-x.txt");

    std::string line;

    for (int i = 0; getline(result, line); ++i) {
        std::vector<char> temp;
        for (int j = 0; j < line.length(); ++j) {
            char character = line[j];
            temp.push_back(character);
        }
        gameResult.push_back(temp);
    }

    result.close();

    for (int k = 0; k < gameResult.size(); ++k) {
        for (int i = 0; i < gameResult.at(k).size(); ++i) {
            std::cout << gameResult[k][i];
        }
        std::cout << std::endl;
    }

    //checking rows
    char startingCharacter;
    for (int k = 0; k < gameResult.size(); ++k) {
        startingCharacter = gameResult.at(k).at(0);
        bool match = true;
        for (int i = 0; i < gameResult.at(k).size(); ++i) {
            if (startingCharacter != gameResult[k][i]) {
                match = false;
            }
        }
        if(match) {
            std::cout << "There is a winner: " << std::endl;
        } else {
            std::cout << "No winner by ckecking rows" << std::endl;
        }
    }

    //checking columns
    for (int k = 0; k < gameResult.size(); ++k) {
        startingCharacter = gameResult.at(0).at(k);
        bool match = true;
        for (int i = 0; i < gameResult.at(k).size(); ++i) {
            if (startingCharacter != gameResult[i][k]) {
                match = false;
            }
        }
        if(match) {
            std::cout << "There is a winner: " << std::endl;
        } else {
            std::cout << "No winner by ckecking columns" << std::endl;
        }
    }

    //checking diagonal1
    bool match = true;
    for (int k = 0; k < gameResult.size(); ++k) {
        startingCharacter = gameResult.at(0).at(0);
        if (startingCharacter != gameResult[k][k]) {
            match = false;
        }
    }
    if (match) {
        std::cout << "There is a winner: " << std::endl;
    } else {
        std::cout << "No winner by ckecking 1st diagonal" << std::endl;
    }

    //checking 2nd diagonal

    match = true;
    for (int k = 0; k < gameResult.size(); ++k) {
        startingCharacter = gameResult.at(0).at(gameResult.size() - 1);
        if (startingCharacter != gameResult[k][gameResult.size() - 1 - k]) {
            match = false;
        }
    }
    if (match) {
        std::cout << "There is a winner: " << std::endl;
    } else {
        std::cout << "No winner by ckecking 2nd diagonal" << std::endl;
    }
    return 0;
}
