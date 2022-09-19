//
// Created by User on 12/26/2019.
//

#include "Matrix.h"
#include <iostream>

/***
 * check all multiplications are const
 */
void checkConstMults()
{
    std::cout << "checking const mult" << std::endl;
    // set up const matrix 1,1 with value of 1
    Matrix A = Matrix(1,1);
    A[0] = 1;
    const Matrix M = A;

    // check operator * with scalar are const
    Matrix B = Matrix();
    B = 2 * M;
    B = M * 2;

    // check * operator with matrix is const
    B = M*M;
}

int main()
{
    checkConstMults();
}
