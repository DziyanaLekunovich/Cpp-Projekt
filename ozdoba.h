#ifndef OZDOBA_H_INCLUDED
#define OZDOBA_H_INCLUDED
#include <iostream>

using namespace std;

class Ozdoba{
public:
    virtual char print() const = 0;
    virtual ~Ozdoba() = default;
};

class Bombka : public Ozdoba{
    char c;
public:
    Bombka() { c = 'o';}
    ~Bombka() {cout << "~B" << endl;}
    char print() const {return c;}
};

class Cukierek : public Ozdoba{
    char c;
public:
    Cukierek() { c = '&';}
    ~Cukierek() {cout << "~C" << endl;}
    char print() const {return c;}
};

class Lampka : public Ozdoba{
    char c;
public:
    Lampka() { c = '*';}
    ~Lampka() {cout << "~L" << endl;}
    char print() const {return c;}
};


#endif // OZDOBA_H_INCLUDED
