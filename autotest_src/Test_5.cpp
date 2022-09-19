//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/***
 * check multiplication operator
 */
int checkMultiplication()
{
    Matrix A = get_ordered_matrix(2, 4);
    Matrix B = get_ordered_matrix(4, 3);

    Matrix C = A*B;

    // Check correct dimensions
    if (C.get_rows() != 2 || C.get_cols() != 3)
    {
	  A.~Matrix();
	  B.~Matrix();
	  C.~Matrix();
	  return 3;
    }

    // Check correct values
    Matrix ans = Matrix(2, 3);
    ans[0] = 42;
    ans[1] = 48;
    ans[2] = 54;
    ans[3] = 114;
    ans[4] = 136;
    ans[5] = 158;
    for (int i = 0 ; i < C.get_cols()*C.get_rows(); i++)
    {
        if (C[i] != ans[i]) {
		  A.~Matrix();
		  B.~Matrix();
		  C.~Matrix();
		  ans.~Matrix();
		  return 2;
        }
    }
    return 0;

//    using Traits = function_traits<static_cast<Matrix(const Matrix&)>(&Matrix::operator*);>;
//    if(!std::is_same<const Matrix&, Traits::argument<1>::type>::value)
//    {
//        std::cerr << "Operator= does not accept by const reference" << std::endl;
//        exit(2);
//    }
}

int main()
{
    return checkMultiplication();
}