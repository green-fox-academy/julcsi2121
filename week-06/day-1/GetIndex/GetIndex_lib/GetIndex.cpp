//
// Created by Varga Júlia on 2019-04-25.
//

#include "GetIndex.h"

int getIndex(std::vector<int> list, int value)
{
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == value) {
            return i;
        }
    }
    return -1;
}