//
// Created by Varga Júlia on 2019-04-17.
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    this->color = color;
    this->width = width;
    this->inkAmount = 100;
}

std::string Sharpie::getColor() {
    return color;
}

void Sharpie::setColor(std::string color) {
    Sharpie::color = color;
}

float Sharpie::getWidth() {
    return width;
}

void Sharpie::setWidth(float width) {
    Sharpie::width = width;
}

float Sharpie::getInkAmount() {
    return inkAmount;
}

void Sharpie::setInkAmount(float inkAmount) {
    Sharpie::inkAmount = inkAmount;
}

void Sharpie::use() {
    inkAmount--;
}

void Sharpie::printAmount() {
    std::cout << "Color " << getColor() << " has " << getInkAmount() << " amount of ink left." << std::endl;
}
