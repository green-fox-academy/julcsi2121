//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

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


#endif //SHARPIE_SHARPIE_H
