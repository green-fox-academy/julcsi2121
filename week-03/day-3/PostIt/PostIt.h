//
// Created by Varga Júlia on 2019-04-17.
//

#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H

#include <string>


class PostIt {
private:
    std::string backgroundColor;
    std::string text;
    std::string textColor;
public:
    PostIt(std::string backgroundColor, std::string text, std::string textColor);
    void setBackgroundColor(std::string backgroundColor);
    void setText(std::string text);
    void setTextColor(std::string textColor);
    std::string getBackgroundColor();
    std::string getText();
    std::string getTextColor();
    std::string print();

};


#endif //POSTIT_POSTIT_H
