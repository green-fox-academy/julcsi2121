//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef SHARPIESET_SHARPIE_H
#define SHARPIESET_SHARPIE_H

#include <string>
#include <iostream>


class Sharpie {
public:
    Sharpie(std::string color, float width);
    std::string getColor();
    void setColor(std::string color);
    float getWidth();
    void setWidth(float width);
    float getInkAmount();
    void setInkAmount(float inkAmount);
    void use();
    void printAmount();


private:
    std::string color;
    float width;
    float inkAmount;

};

#endif //SHARPIESET_SHARPIE_H
