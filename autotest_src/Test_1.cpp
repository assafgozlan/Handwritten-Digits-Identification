//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/***
 * check the assignment operator for a Matrix object.
 */
int checkAssignment()
{
    Matrix M = get_ordered_matrix(4, 5);
    Matrix B = Matrix();
    B = M;

    // checking correct new dimensions
    if (B.get_rows() != M.get_rows() || B.get_cols() != M.get_cols()) {
	  B.~Matrix();
	  return 3;
    }

    // checking correct new values
    for(int i=0; i<M.get_cols()*M.get_rows(); i++)
    {
        if((B[i] != M[i]))
        {
		  	B.~Matrix();
            return 1;
        }
    }

    // todo: if this causes valgrind to fail does this need to be in a unit test...?
    // checking self assignment
    // will cause valgrind to fail if not done properly! (or double delete which is a runtime error)
    B = B;
    using Traits = function_traits<decltype(&Matrix::operator=)>;
    if(!std::is_same<const Matrix&, Traits::argument<1>::type>::value)
    {
        std::cerr << "Operator= does not accept by const reference" << std::endl;
	  	B.~Matrix();
	  	return 2;
    }
    return 0;
}

int main()
{
    return checkAssignment();
}
