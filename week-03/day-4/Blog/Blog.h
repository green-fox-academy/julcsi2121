//
// Created by Varga Júlia on 2019-04-18.
//

#ifndef BLOG_BLOG_H
#define BLOG_BLOG_H

#include "BlogPost.h"
#include <vector>


class Blog {
public:
    void add(BlogPost& post);
    void deletePost(int i);
    void update(int i, BlogPost post);
    BlogPost* getBlogPost(int i);
    void printPosts();
private:
    std::vector<BlogPost> myBlog;
};


#endif //BLOG_BLOG_H
