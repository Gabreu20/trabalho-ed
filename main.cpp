#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <databaseArquitetura.h>

using namespace std;

void getInfo(){
    ifstream db;
    db.open("tiktok_app_reviews.csv");

    string line;
    getline(db,line,'\n');

    getline(db,line,',');
    getline(db,line,'\n');

    int v[3];
    int n=0;

    for(int i=0; i < line.size(); i++){
        if(line[i] == ','){
            v[n%3]=i;
            n++;
        }
    }
    for(int i=0; i < v[(n-3)%3];i++){
        cout << line[i];
    }
}

int main() {

    databaseArquitetura dbA("tiktok_app_reviews.csv");

    dbA.setReview();

    dbA.imprimir();

    dbA.pegaValor(7);

    return 0;
}
