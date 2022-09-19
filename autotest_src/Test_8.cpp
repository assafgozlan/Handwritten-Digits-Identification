#include "autotest_utils.h"

/**
 * Transpose tester, should return true if the transpose method is working correctly.
 * @param matrix the matrix we want to check
 * @return 0 if transposed successfully, 1 if transposition was not correct, 2 if dimensions were
 * messed up completely.
 */
int testTranspose(const Matrix &matrix)
{
	Matrix B = matrix;
	B.transpose ();
	if (B.get_cols() != matrix.get_rows() || B.get_rows() != matrix.get_cols())
	{
		exit(3);
	}
	for (int i = 0; i < B.get_rows(); ++i)
	{
		for (int j = 0; j < B.get_cols(); ++j)
		{
			if (B(i, j) != matrix(j, i))
			{
			  B.~Matrix();
			  return 2;
			}
		}
	}
	return 0;
}

int main()
{
	Matrix A = get_ordered_matrix(2, 10);
    Matrix B = get_ordered_matrix(7, 7);
	int res1 = testTranspose(A);
	if(res1!=0)
	{
	  return res1;
	}
	return testTranspose(B);
}

