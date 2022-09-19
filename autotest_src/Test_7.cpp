//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/**
 * check += addition operator
 */
int checkSelfAddition()
{
    Matrix M = get_ordered_matrix(5, 7);
    Matrix old = M;

    // Checking same address while doing self addition
    if(!checkSameAddress(M, M += M))
    {
	  M.~Matrix();
	  return 1;
    }

    // Checking correct values
    for(int i=0; i<M.get_cols()*M.get_rows(); i++)
    {
        if((2*old[i] != M[i]))
        {
		  M.~Matrix();
		  return 2;
        }
    }

    // Checking accepting const reference
    using Traits = function_traits<decltype(&Matrix::operator+=)>;
    if(!std::is_same<const Matrix&, Traits::argument<1>::type>::value)
    {
	  M.~Matrix();
	  return 3;
    }
    return 0;
}

int main()
{
    return checkSelfAddition();

}