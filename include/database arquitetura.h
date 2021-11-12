#ifndef DATABASEARQUITETURA_H
#define DATABASEARQUITETURA_H
#include <iostream>
#include <string>
#include <no.h>

using namespace std;

class databaseArquitetura
{
    public:
        databaseArquitetura();
        ~databaseArquitetura();
        setReview();

    private:
        string _path;
        no *primeiro;
        no *ultimo;
};

#endif // DATABASE ARQUITETURA_H
