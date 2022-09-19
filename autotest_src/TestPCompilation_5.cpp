#include "autotest_utils.h"

/**
 * Tests the norm of a matrix.
 * @param A
 * @return 0 if the norm is correct, 1 otherwise
 */
int testNorm()
{
	Matrix A = get_ordered_matrix(2, 10);
	double expectedResult = 49.6991;
	if ((int) A.norm() != (int) expectedResult)
	{
	  	A.~Matrix();
	  	return 1;
	} // if this is true, then norm is written correctly
	Matrix B = get_ordered_matrix(3, 5);
	double expectedResult2 = 31.8591;
	if ((int) B.norm() != (int) expectedResult2)
	{
	  	A.~Matrix();
	  	B.~Matrix();
	  	return 1;
	}
   return 0;
}

int main()
{
	return testNorm();
}

