//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/**
 * check result and invalid indices
 * of parenthesis
 */
int checkParenthesis()
{
    Matrix M = get_ordered_matrix(8, 3);

    // Check correct values
    for (int i = 0; i < M.get_rows(); i++)
    {
        for (int j = 0; j < M.get_cols(); j++)
        {
            if (M(i, j) != (i*M.get_cols()) + j)
            {
				M.~Matrix();
                return 2;
            }
        }
    }
    return 0;
}

int main()
{
    return checkParenthesis();

}