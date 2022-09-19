//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/**
 * simple addition check
 */
int checkAddition()
{
    Matrix A = get_ordered_matrix(1, 4);
    Matrix B = get_ordered_matrix(1, 4);
    Matrix C = A + B;

    std::cout << "Checking simple addition" << std::endl;
    if (C[0] != 0 || C[1] != 2 || C[2] != 4)
    {
	  	A.~Matrix();
	  	B.~Matrix();
	  	C.~Matrix();
	  	return 1;
    }
//    using Traits = function_traits<decltype(&Matrix::operator+)>; //can't use if this is a friend func
//    if (!std::is_same<const Matrix &, Traits::argument<1>::type>::value)
//    {
//        std::cerr << "Operator+ does not accept by const reference" << std::endl;
//        exit(2);
//    }
	return 0;
}

int main()
{
    return checkAddition();
}