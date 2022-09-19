//
// Created by Chend on 3/17/2021.
//
#include "autotest_utils.h"

/**
 * This function tests the Matrix.dot function. If it finds that it is correct, it returns true,
 * otherwise it returns false
 * @param matrix
 * @return 0 if dot works correctly, 2 otherwise
 */
int testDotGoodDims(Matrix &matrix)
{
	Matrix result = matrix.dot(matrix);
	for (int i = 0; i < matrix.get_cols() * matrix.get_rows(); ++i)
	{
		if (result[i] != matrix[i] * matrix[i])
		{
		  matrix.~Matrix();
		  return 2;
		}
	}
	return 0;
}


int main()
{
	Matrix A = get_ordered_matrix(2, 10);
	return testDotGoodDims(A);
}


