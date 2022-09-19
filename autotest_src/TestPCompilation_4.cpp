//
// Created by User on 12/26/2019.
//

#include "Matrix.h"
#include <iostream>

/**
 * check existence of const version for parenthesis operator
 */
void checkConstParenthesis()
{
    // set up const matrix 1,1 with value of 1
    Matrix A = Matrix(1,1);
    A[0] = 1;
    const Matrix M = A;
    std::cout << "checking const operator for parenthesis" << std::endl;

    // won't compile if () doesnt have const version
    M(0,0);
}

int main()
{
    checkConstParenthesis();
}
