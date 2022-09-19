//
// Created by User on 12/26/2019.
//

#include "Matrix.h"
#include <iostream>

/**
 * check addition for const matrices
 */
void checkConstAddition()
{
    std::cout << "checking const parameters + operator" << std::endl;
    // set up const matrix 1,1 with value of 1
    Matrix A = Matrix(1,1);
    A[0] = 1;
    const Matrix M = A;

    // will not compile if + operator isn't const
    Matrix B = A + A;
}

/**
 * check if += operator has const parameters
 */
void checkConstAccumalatedSum()
{
    std::cout << "checking const parameters += operator" << std::endl;
    Matrix A = Matrix(1,1);
    A[0] = 1;
    const Matrix M = A;
    // won't compile if += doesnt keep M as const
    A += M;
}

int main()
{
    checkConstAddition();
    checkConstAccumalatedSum();
}
