//
// Created by User on 12/26/2019.
//

#include "Matrix.h"
#include <iostream>

/**
 * check existence of const version for parenthesis operator
 */
void checkConstBrackets()
{

    // set up const matrix 1,1 with value of 1
    Matrix A = Matrix(1,1);
    A[0] = 1;
    const Matrix M = A;
    std::cout << "checking const operator for brackets" << std::endl;

    // won't compile if () doesnt have const version. also won't compile for bad print
    M[0];

}

int main()
{
    checkConstBrackets();
}
