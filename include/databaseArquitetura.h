#ifndef DATABASEARQUITETURA_H
#define DATABASEARQUITETURA_H
#include <iostream>
#include <string>
#include <no.h>

using namespace std;

class databaseArquitetura
{
    public:
        databaseArquitetura(string path);
        ~databaseArquitetura();
        void setReview();
        void imprimir();
        void pegaValor(int a);

    private:
        string _path;
        no *primeiro;
        no *ultimo;
};


#endif // DATABASEARQUITETURA_H
