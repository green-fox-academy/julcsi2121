#include <iostream>
#include <vector>

#include "Domino.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...

    std::vector<Domino> orderedDominoes;
    orderedDominoes.push_back(dominoes.at(0));

    for (int i = 0; i < dominoes.size(); ++i) {
        std::pair<int, int> actualPair = orderedDominoes.at(i).getValues();
        for (int j = 0; j < dominoes.size(); ++j) {
            std::pair<int, int> pairToFind = dominoes.at(j).getValues();
            if(actualPair.second == pairToFind.first) {
                orderedDominoes.push_back(dominoes.at(j));
            }
        }
    }

    for (int k = 0; k < orderedDominoes.size(); ++k) {
        std::cout << orderedDominoes.at(k).toString() << std::endl;
    }

    return 0;
}