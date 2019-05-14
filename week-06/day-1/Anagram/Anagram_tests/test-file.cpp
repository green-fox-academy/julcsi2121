//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Anagram.h"

TEST(AnagramCheck, TwoEmptyAnagramTest)
{
    std::string string1 = "";
    std::string string2 = "";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, false);
}

TEST(AnagramCheck, OneSameCharacterAnagramTest)
{
    std::string string1 = "c";
    std::string string2 = "c";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, true);
}

TEST(AnagramCheck, IsAnagramTest)
{
    std::string string1 = "cat";
    std::string string2 = "act";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, true);
}

TEST(AnagramCheck, IsAnagramMoreSameLetterTest)
{
    std::string string1 = "state";
    std::string string2 = "taste";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, true);
}

TEST(AnagramCheck, NumberInStringIsAnagramTest)
{
    std::string string1 = "33cat";
    std::string string2 = "c3a3t";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, true);
}

TEST(AnagramCheck, TestCapitals) {
    std::string string1 = "sort";
    std::string string2 = "sOrt";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, false);
}

TEST(AnagramCheck, TestUnequalLengthLastCharDiffers) {
    std::string string1 = "sorte";
    std::string string2 = "sortez";

    bool result = anagramItIs(string1, string2);

    ASSERT_EQ(result, false);
}