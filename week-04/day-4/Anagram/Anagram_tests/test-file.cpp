//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Anagram.h"

TEST(bubbleSortTests, testWholeFunction) {
    std::string result = "sort";
    bubbleSort(result);
    ASSERT_EQ(result, "orst");
}

TEST(bubbleSortTests, testWithCapitals) {
    std::string result = "SoRt";
    bubbleSort(result);
    ASSERT_EQ(result, "RSot");
}

TEST(bubbleSortTests, testWithOtherChars) {
    std::string result = "So Rt";
    bubbleSort(result);
    ASSERT_EQ(result, " RSot");
}

TEST(anagramTests, testTrueCase) {
    std::string string1 = "sort";
    std::string string2 = "srot";
    bool result = anagram(string1, string2);
    ASSERT_EQ(result, true);
}

TEST(anagramTests, testFalseCase) {
    std::string string1 = "sort";
    std::string string2 = "sret";
    bool result = anagram(string1, string2);
    ASSERT_EQ(result, false);
}

TEST(anagramTests, testCapitals) {
    std::string string1 = "sort";
    std::string string2 = "sOrt";
    bool result = anagram(string1, string2);
    ASSERT_EQ(result, false);
}

TEST(anagramTests, testUnequalLength) {
    std::string string1 = "sort";
    std::string string2 = "sortee";
    bool result = anagram(string1, string2);
    ASSERT_EQ(result, false);
}

TEST(anagramTests, testUnequalLengthLastCharDiffers) {
    std::string string1 = "sorte";
    std::string string2 = "sortez";
    bool result = anagram(string1, string2);
    ASSERT_EQ(result, false);
}
