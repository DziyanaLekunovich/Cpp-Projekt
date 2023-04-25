#ifndef CHOINKA_H_INCLUDED
#define CHOINKA_H_INCLUDED
#include <iostream>
#include "ozdoba.h"

using namespace std;

class Choinka{
private:
    int n;
    Ozdoba* **tab;
public:
    Choinka(int n);
    ~Choinka();
    void powiesz(char c, int i, int j);
    friend ostream& operator<<(ostream& os, const Choinka& c);
    void zdejmij(int i, int j);
};

Choinka::Choinka(int n) : n(n){
    tab = new Ozdoba**[n];
    for (int i = 0, j = 1; i < n; i++, j += 2){
        tab[i] = new Ozdoba*[j] {nullptr};
    }

    int k = 1;
    int v;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            v = rand() % 4;
            switch(v){
                case 0: tab[i][j] = new Bombka(); break;
                case 1: tab[i][j] = new Lampka(); break;
                case 2: tab[i][j] = new Cukierek(); break;
            }
        }
        k += 2;
    }
}

ostream& operator<<(ostream& os, const Choinka& c){
    int k = 1;
    for(int i = 0; i < c.n; i++){
        for (int m = 0; m < c.n - 1 - i; m++)
            os << " ";
        for (int j = 0; j < k; j++){
            if(c.tab[i][j] == nullptr){
                os << "^";
            }
            else
                os << c.tab[i][j]->print();
        }
        k += 2;
        os << endl;
    }
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < c.n - 1; j++)
            os << " ";
        os << "#" << endl;
    }

    return os;
}


void Choinka::powiesz(char c, int i, int j){
    delete tab[i][j];
    switch(c){
        case 'o' : tab[i][j] = new Bombka(); break;
        case '*' : tab[i][j] = new Lampka(); break;
        case '&' : tab[i][j] = new Cukierek(); break;
    }
}

void Choinka::zdejmij(int i, int j) {
    delete tab[i][j];
    tab[i][j] = nullptr;
}

Choinka::~Choinka(){
   int k = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            delete tab[i][j];
        }
        k += 2;
    }
    delete[] tab;
}


#endif // CHOINKA_H_INCLUDED
