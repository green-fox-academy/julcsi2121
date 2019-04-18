//
// Created by Varga Júlia on 2019-04-18.
//

#include "Blog.h"

void Blog::add(BlogPost& post){
    myBlog.push_back(post);
}

BlogPost* Blog::getBlogPost(int i){
    return &myBlog[i];
}

void Blog::printPosts(){
    for (int j = 0; j < myBlog.size(); ++j) {
        myBlog[j].printNicely();
    }
}

void Blog::deletePost(int i) {
    myBlog.erase(myBlog.begin() + i);
}

void Blog::update(int i, BlogPost post) {
    myBlog.insert(myBlog.begin() + i, post);
}