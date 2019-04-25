//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "CountLetters.h"

TEST(countLetterTests, checkLength) {
    std::map<char, int> result = countLetters("str");
    int size = result.size();

    ASSERT_EQ(size, 3);
}

TEST(countLetterTests, checkLengthWithDuplicates) {
    std::map<char, int> result = countLetters("sstr");
    int size = result.size();

    ASSERT_EQ(size, 3);
}

TEST(countLetterTests, checkKeys) {
    std::string input = "str";
    std::map<char, int> result = countLetters(input);
    std::map<char, int>::iterator it = result.begin();
    bool match = true;

    for (; it != result.end(); ++it) {
        if (input.find(it->first) == -1) {
            match = false;
        }
    }

    ASSERT_EQ(match, true);
}

TEST(countLetterTests, checkValues) {
    std::string input = "str";
    std::map<char, int> result = countLetters(input);
    std::map<char, int>::iterator it = result.begin();
    bool match = true;

    for (; it != result.end(); ++it) {
        if (it->second != 1) {
            match = false;
        }
    }

    ASSERT_EQ(match, true);
}

TEST(countLetterTests, checkWithDuplicates) {
    std::string input = "sstr";
    std::map<char, int> result = countLetters(input);
    std::map<char, int>::iterator it = result.begin();
    bool match = true;

    for (; it != result.end(); ++it) {
        if (it->second != 1) {
            match = false;
        }
    }

    ASSERT_EQ(match, false);
}