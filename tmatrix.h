#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>

template <class Type>

class tMatrix
{
public:
    unsigned int Rows;
    unsigned int Collums;
    Type ** Mat;
public:
    tMatrix(unsigned int R, unsigned int C)
    {
        if (R!=0 && C!=0)
        {
            Rows = R;
            Collums = C;
            Mat = new Type* [R];
            for(unsigned int i = 0; i<R; ++i)
                Mat[i] = new Type [C];
        }

    }
    void Transpose()
    {

        if(Rows==Collums)
        {
            for(unsigned int i = 0; i<Rows; ++i)
            {
                for(unsigned int j=i; j<Collums;++j)
                {
                    Type tmp;
                    tmp = Mat[i][j];
                    Mat[i][j] = Mat[j][i];
                    Mat[j][i] = tmp;
                }
            }
            //return this;
        }

        else
        {
            Type **TMat = new Type* [Collums];
            for(unsigned int i = 0; i<Collums; ++i)
                TMat[i] = new Type [Rows];

            for(unsigned int i = 0; i<Rows; ++i)
            {
                for(unsigned int j = 0; j<Collums; ++j)
                {
                    TMat[j][i] = Mat[i][j];
                }
            }

            for(unsigned int i = 0; i<Rows; ++i)
                delete[] Mat[i];

            Mat = TMat;
            unsigned int tmp = Collums;
            Collums = Rows;
            Rows = tmp;

        }
    }
    void SetIdentity()
    {
        if (Rows==Collums)
        {
            for(unsigned int i = 0; i<Rows; ++i)
            {
                for(unsigned int j = 0; j<Collums; ++j)
                    Mat[i][j] = (i==j);
            }
        }
        else
            std::cout << "Error: matrix is not square."<<std::endl;
    }
    ~tMatrix()
    {
        for(unsigned int i = 0; i<Rows; ++i)
            delete[] Mat[i];
        delete[] Mat;
        std::cout<< "Matrix destroyed!"<<std::endl;
    }
    friend std::ostream & operator<< (std::ostream & os, const tMatrix & _mx )
    {
        for(unsigned int i = 0; i < _mx.Rows; ++i)
        {
            os << "[";
            for(unsigned int j = 0; j < _mx.Collums; ++j)
            {
                os << _mx.Mat[i][j] <<" ";
            }
            os << "]" << std::endl;
        }
        os << std::endl;
        return os;
    }
};

#endif // TMATRIX_H
