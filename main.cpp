#include <iostream>
#include  "tvector.h"
#include "tmatrix.h"

using namespace std;

int main()
{

    tVector<double> V (100.5,500,100,0);
    cout << V;
    cout << V;
    cout << V.GetLength()<<endl;
    V.Normilize();
    cout << V.GetLength()<<endl;

    return 0;
}

