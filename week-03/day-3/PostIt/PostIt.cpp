//
// Created by Varga Júlia on 2019-04-17.
//

#include "PostIt.h"
#include <string>

PostIt::PostIt(std::string backgroundColor, std::string text, std::string textColor)
{
    setBackgroundColor(backgroundColor);
    setText(text);
    setTextColor(textColor);
}

void PostIt::setBackgroundColor(std::string backgroundColor) {
    PostIt::backgroundColor = backgroundColor;
}

void PostIt::setText(std::string text) {
    PostIt::text = text;
}

void PostIt::setTextColor(std::string textColor) {
    PostIt::textColor = textColor;
}

std::string PostIt::getBackgroundColor() {
    return backgroundColor;
}

std::string PostIt::getText() {
    return text;
}

std::string PostIt::getTextColor() {
    return textColor;
}

std::string PostIt::print() {
    return ("Background color: " + getBackgroundColor() + ", Text: " + getText() + ", Text color: " + getTextColor());
}