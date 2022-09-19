//
// Created by User on 7/21/2020.
//

#include "autotest_utils.h"

int checkRelu()
{
    Matrix M = get_ordered_matrix(1, 13);
    Matrix ans = activation::relu(M);

    // Checking no change of positives
    for(int i=0; i<M.get_cols()*M.get_rows(); i++)
    {
        if(M[i] != ans[i])
        {
           M.~Matrix();
           return 1;
		}
    }

    // Check zeroing negatives
    for(int i=0;i<M.get_cols()*M.get_rows(); i++)
    {
        M[i] = -i;
    }
    ans = activation::relu(M);
    for(int i=0; i<M.get_cols()*M.get_rows(); i++)
    {
        if (ans[i] != 0)
        {
			M.~Matrix();
			return 2;
        }
    }
    return 0;
}

int main()
{
    return checkRelu();
}
