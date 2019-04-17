#include <iostream>
#include "BlogPost.h"

int main() {
    BlogPost post1("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
    BlogPost post2("Tim Urban", "Wait but why", "Lorem ipsum dolor sit amet.", "2010.10.10.");
    BlogPost post3("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.", "2017.03.28.");
    post1.printNicely();
    post2.printNicely();
    post3.printNicely();
    return 0;
}