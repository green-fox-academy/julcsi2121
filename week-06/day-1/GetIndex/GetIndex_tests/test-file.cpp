//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "GetIndex.h"

TEST(getIndexTest, valueInList) {
    int result = getIndex({2, 4, 5}, 4);
    ASSERT_EQ(result, 1);
}

TEST(getIndexTest, valueNotInList) {
    int result = getIndex({2, 4, 5}, 7);
    ASSERT_EQ(result, -1);
}

TEST(getIndexTest, emptyList) {
    int result = getIndex({}, 7);
    ASSERT_EQ(result, -1);
}

TEST(getIndexTest, negativeValues) {
    int result = getIndex({-4, 4, 7}, -4);
    ASSERT_EQ(result, 0);
}

/*
TEST(getIndexTest, stringList) {
    int result = getIndex({"abc", "fgh", "7"}, 7);
    ASSERT_EQ(result, -1);
}
*/