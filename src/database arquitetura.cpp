#include "databaseArquitetura.h"
#include <no.h>
#include <iostream>
#include <string>

databaseArquitetura::databaseArquitetura(string path)
{
    _path = path;
    primeiro = null;
    ultimo = null;
}

databaseArquitetura::~databaseArquitetura()
{
    no *p = primeiro;
    no *aux;
    while(p->proximo != null){
        aux = p;
        p = p->proximo;
        delete aux;
    }
}

databaseArquitetura::setReview()
{
    if(primeiro == null){
        no *p = new no;
        //treta toda
    }
}
