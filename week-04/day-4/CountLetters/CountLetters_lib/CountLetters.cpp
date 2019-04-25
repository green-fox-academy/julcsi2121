//
// Created by Varga Júlia on 2019-04-25.
//

#include "CountLetters.h"

std::map<char, int> countLetters(std::string input)
{
    std::map<char, int> result;
    int count = 0;

    for (int i = 0; i < input.size(); ++i) {
        if(result.count(input[i]) == 0) {
            result.insert(std::make_pair(input[i], count));
        }
    }

    std::map<char, int>::iterator it;

    for (int j = 0; j < input.size(); ++j) {
        it = result.find(input[j]);
        it->second++;
    }

    it = result.begin();
    for (; it != result.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return result;
}