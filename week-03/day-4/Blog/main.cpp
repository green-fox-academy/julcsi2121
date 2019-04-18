#include <iostream>
#include "BlogPost.h"
#include "Blog.h"

int main() {
    BlogPost post1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost post2("Tim Urban", "Wait but why", "Lorem ipsum dolor sit amet.", "2010.10.10.");
    BlogPost post3("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.", "2017.03.28.");
    BlogPost post4("Kylie Jenner", "What's in my bag", "I'm gonna show you!", "2018.10.20");

    Blog myBlog;
    myBlog.add(post1);
    myBlog.add(post2);
    myBlog.add(post3);
    myBlog.printPosts();
    myBlog.update(1, post4);
    myBlog.printPosts();
    return 0;
}
