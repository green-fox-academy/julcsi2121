//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "Extension.h"


TEST(add, _2and3is5) {
    ASSERT_EQ(5, add(2, 3));
}

TEST(add, _1and4is5) {
    ASSERT_EQ(5, add(1, 4));
}

TEST(add, 2and2is4) {
    ASSERT_EQ(4, add(2, 2));
}

TEST(add, minus2plus5is3) {
    ASSERT_EQ(3, add(-2, 5));
}

TEST(max_of_three, first) {
    ASSERT_EQ(5, maxOfThree(5, 4, 3));
}

TEST(max_of_three, third) {
    ASSERT_EQ(5, maxOfThree(3, 4, 5));
}

TEST(max_of_three, second) {
    ASSERT_EQ(5, maxOfThree(3, 5, 4));
}

TEST(median, five) {
    ASSERT_EQ(3, median({1, 2, 3, 4, 5}));
}

TEST(median, fourOrdered) {
    ASSERT_EQ(4, median({2, 3, 5, 6}));
}

TEST(median, fiveOrdered) {
    ASSERT_EQ(4, median({2, 3, 4, 5, 6}));
}

/*
TEST(median, fourUnordered) {
    ASSERT_EQ(5, median({6, 2, 3, 5}));
}
 */

TEST(is_vowel, a) {
    ASSERT_TRUE(isVowel('a'));
}

TEST(is_vowel, u) {
    ASSERT_TRUE(isVowel('u'));
}

TEST(is_vowel, I) {
    ASSERT_TRUE(isVowel('I'));
}

TEST(is_vowel, t) {
    ASSERT_FALSE(isVowel('t'));
}

TEST(translate, bemutatkozik) {
    ASSERT_EQ("bevemuvutavatkovozivik", translate("bemutatkozik"));
}

TEST(translate, lagopus) {
    ASSERT_EQ("lavagovopuvus", translate("lagopus"));
}

TEST(translate, efi) {
    ASSERT_EQ("evefivi", translate("efi"));
}

TEST(translate, eui) {
    ASSERT_EQ("eveuvuivi", translate("eui"));
}