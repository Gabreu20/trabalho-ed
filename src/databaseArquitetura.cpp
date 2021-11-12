#include "databaseArquitetura.h"
#include <no.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

databaseArquitetura::databaseArquitetura(string path)
{
    _path = path;
    primeiro = NULL;
    ultimo = NULL;
}

databaseArquitetura::~databaseArquitetura()
{
    no *p = primeiro;
    no *aux;
    while(p->proximo != NULL)
    {
        aux = p;
        p = p->proximo;
        delete aux;
    }
}

void databaseArquitetura::setReview()
{
    ifstream db;
    db.open(_path);
    string line;
    int inicialPos = 90;
    int position = 0;
    getline(db,line,'\n');
    //setar novo no
    no *p = new no;
    int quantos = 10;
    while(quantos >= 1)
    {
        if(primeiro != NULL)
        {
            no *aux = new no;
            p->proximo = aux;
            aux->anterior = p;
            p = aux;
        }
        if(primeiro == NULL)
        {
            no *aux = new no;
            primeiro = p;
            p->anterior = NULL;
            p->proximo = aux;
            aux->anterior = p;
        }
        getline(db,line,'\n');

        position = line.size();
        for(int i = 0; i < 89; i++)
        {
            p->review_id[i] = line[i];
        }
        p->review_id[90] = '\n';

        int v[3];
        int n=0;

        for(int i=0; i < line.size(); i++)
        {
            if(line[i] == ',')
            {
                v[n%3]=i;
                n++;
            }
        }
        int vMenor = 10000;
        for(int i = 0; i < 3; i++){
            if(v[i] < vMenor)
                vMenor = v[i];
        }

        int rev_text_index = 0;
        int lengthAux = position - vMenor;
        for(int i=90; i < position - lengthAux; i++)
        {
            p->review_text[rev_text_index] = line[i];
            rev_text_index++;
        }
        int controlador = 0;
        string str = "";
        for(int i = v[(n-3) % 3] + 1; i <=line.size(); i++)
        {
            str = str + line[i];
            if(line[i] == ',' || line[i] == '\n' || i == line.size())
            {
                if(controlador == 0)
                {
                    stringstream ss;
                    ss << str;
                    ss >> p->upvote;
                    str = "";
                }
                else if(controlador == 1)
                {
                    for(int j = 0; j < str.length() - 1; j++)  //<-- POSSIVEL ERRO NO LENGTH
                    {
                        p->version[j] = str[j];
                    }
                    str = "";
                }
                else if(controlador == 2)
                {
                    for(int j = 0; j < str.length() - 1; j++)  //<-- POSSIVEL ERRO NO LENGTH
                    {
                        p->posted_data[j] = str[j];
                    }
                }
                controlador++;
            }
        }
        cout << p->review_id << endl;
        cout << endl;
        cout << p->review_text << endl;
        cout << endl;
        cout << p->upvote << endl;
        cout << endl;
        cout << p->version << endl;
        cout << endl;
        cout << p->posted_data << endl;
        cout << endl;
        quantos--;
    }
    db.close();
    ultimo = p;
    p->proximo = NULL;
}

void databaseArquitetura::imprimir(){
    cout << "upvote do primeiro: ";
    cout << primeiro->upvote << endl;
    cout << "upvote do ultimo: ";
    cout << ultimo->upvote << endl;
    cout << "pegar o segundo valor usando o proximo do primeiro: ";
    cout << primeiro->proximo->upvote << endl;
    cout << "pegar o segundo valor usando o anterior do ultimo: ";
    cout << ultimo->anterior->upvote << endl;
}

void databaseArquitetura::pegaValor(int a){
    int aux = 0;
    no *p = primeiro;
    while(aux < a-1){
        p = p->proximo;
        aux++;
    }
    cout << "Upvotes do no "<< a << " eh: " << p->upvote << endl;
}
