#include <iostream>
#include <time.h>
#include "choinka.h"

using namespace std;

int main()
{
    srand(time(NULL));

    Choinka c1(5);
//    c1.powiesz('o', 0, 0);
//    c1.powiesz('o', 1, 1);
//    c1.powiesz('*', 2, 2);
    cout << c1 << endl;

    c1.zdejmij(1,1);
    cout << c1 << endl;

    return 0;
}
