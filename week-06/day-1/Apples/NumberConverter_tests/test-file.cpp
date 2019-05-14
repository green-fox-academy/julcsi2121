//
// Created by Varga Júlia on 2019-04-25.
//

#include "gtest/gtest.h"
#include "NumberConverter.h"

//TEST(numberConverterTest, oneDigit) {
//    NumberConverter example;
//    std::string result = example.numToText(4);
//    ASSERT_EQ(result, "four");
//}

TEST(numberConverterTest, moreDigits) {
    NumberConverter example;
    std::string result = example.numToText(43);
    ASSERT_EQ(result, "four thousand two hundred and eleve ");
}
