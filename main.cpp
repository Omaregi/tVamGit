#include <iostream>
#include  "tvector.h"
#include "tmatrix.h"

using namespace std;

int main()
{
    tMatrix<double> M (2,3);
    cout << M;
    M.Transpose();
    cout << M;

    return 0;
}
