//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Fibonacci.h"

TEST(fibonacciTests, test0) {
    int result;
    result = fibonacci(0);
    ASSERT_EQ(result, 0);
}

TEST(fibonacciTests, test1) {
    int result;
    result = fibonacci(1);
    ASSERT_EQ(result, 1);
}

TEST(fibonacciTests, test6) {
    int result;
    result = fibonacci(6);
    ASSERT_EQ(result, 8);
}

TEST(fibonacciTests, testNegative) {
    int result;
    result = fibonacci(-6);
    ASSERT_EQ(result, -1);
}