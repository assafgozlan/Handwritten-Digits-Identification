//
// Created by User on 7/20/2020.
//
#include "autotest_utils.h"

/***
 * check the vectorization of a matrix object, print and compare with diff
 */
int checkVectorize()
{
    Matrix M = get_ordered_matrix(4, 3);
    Matrix old = M;
    M.vectorize();

    // Checking correct dimensions
    if(M.get_cols() != 1 || M.get_rows() != 12)
    {
		M.~Matrix();
		return 2;
    }

    // Checking same address
    if(!checkSameAddress(M, M.vectorize()))
    {
		M.~Matrix();
		return 3;
    }

    // Checking same values
    for (int i = 0; i < 12; i++)
    {
        if (old[i] != M[i])
        {
		  	M.~Matrix();
		  	return 4;
        }
    }
    return 0;
}

int main()
{
    return checkVectorize();
}
