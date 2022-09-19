//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

int checkBrackets()
{
    Matrix M = get_ordered_matrix(7, 9);
    for (int i = 0; i < M.get_cols()*M.get_rows(); i++)
    {
        if (M[i] != i)
        {
		  M.~Matrix();
		  return 2;
        }
    }
    return 0;
}

int main()
{
    return checkBrackets();
}