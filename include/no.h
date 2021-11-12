#ifndef NO_H
#define NO_H
#include <iostream>
#include <string>

using namespace std;

class no
{
    public:
        no();
        ~no();
        char review_id[90];
        char review_text[3000];
        int upvote;
        char version[10];
        char posted_data[20];
        no *proximo;
        no *anterior;
};

#endif // NO_H
