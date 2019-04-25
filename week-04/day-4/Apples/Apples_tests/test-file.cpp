//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Apple.h"

TEST(firsttest, firstTest) {
    std::string result;
    result = getApple();
    ASSERT_EQ(result, "Apple");
}

