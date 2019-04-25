//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Apple.h"

TEST(appleTests, checkApple) {
    std::string result;
    result = getApple();
    ASSERT_EQ(result, "Apple");
}

TEST(sumTests, testWithMultipleElements) {
    std::vector<int> numbers {2, 4, 6};
    int result = sum(numbers);
    ASSERT_EQ(result, 12);
}

TEST(sumTests, testOneElement) {
    std::vector<int> numbers {2};
    int result = sum(numbers);
    ASSERT_EQ(result, 2);
}

TEST(sumTests, testEmptyList) {
    std::vector<int> numbers {};
    int result = sum(numbers);
    ASSERT_EQ(result, 0);
}

TEST(sumTests, testNegativeNumbers) {
    std::vector<int> numbers {-2, -4};
    int result = sum(numbers);
    ASSERT_EQ(result, -6);
}