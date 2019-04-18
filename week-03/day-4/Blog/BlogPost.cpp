//
// Created by Varga Júlia on 2019-04-18.
//

#include "BlogPost.h"

BlogPost::BlogPost(std::string authorName, std::string title, std::string text, std::string publicationDate) {
    setAuthorName(authorName);
    setTitle(title);
    setText(text);
    setPublicationDate(publicationDate);

}

void BlogPost::setAuthorName(std::string authorName) {
    this->authorName = authorName;
}

void BlogPost::setTitle(std::string title) {
    this->title = title;
}

void BlogPost::setText(std::string text) {
    this->text = text;
}

void BlogPost::setPublicationDate(std::string publicationDate) {
    this->publicationDate = publicationDate;
}

std::string BlogPost::getAuthorName() {
    return authorName;
}

std::string BlogPost::getTitle() {
    return title;
}

std::string BlogPost::getText() {
    return text;
}

std::string BlogPost::getPublicationDate() {
    return publicationDate;
}

void BlogPost::printNicely() {
    std::cout << "Author: " << getAuthorName() << "\nTitle: " << getTitle() << "\nDescription: " << getText() << "\nPublication Date: " << getPublicationDate();
}

