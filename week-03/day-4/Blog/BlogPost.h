//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef BLOG_BLOGPOST_H
#define BLOG_BLOGPOST_H


#include <string>
#include <iostream>


class BlogPost {
public:
    BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate);
    void setAuthorName(std::string authorName);
    void setTitle(std::string title);
    void setText(std::string text);
    void setPublicationDate(std::string publicationDate);
    std::string getAuthorName();
    std::string getTitle();
    std::string getText();
    std::string getPublicationDate();
    void printNicely();

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;
};


#endif //BLOGPOST_BLOGPOST_H

