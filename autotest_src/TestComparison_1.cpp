//
// Created by User on 7/21/2020.
//

#include "autotest_utils.h"

void checkBadDimsMult()
{
	std::cout << "checking bad dims for multiplication" << std::endl;
	Matrix M = Matrix(3, 3);
	for (int i = 0; i < M.get_cols() * M.get_rows(); i++)
	{
		M[i] = i;
	}
	Matrix B = Matrix();

	// use a bad multiplcation make sure there is a error print.
	M = M * B;
}

/**
 * checking if there was an exception throwing
 * @return 0 on success
 *         1 in failure
 *         2 on wrong exception
 */
int main()
{
	try
	{
		checkBadDimsMult();
	}
	catch (const std::length_error &error)
	{
		std::cerr << error.what() << std::endl;
		return 0;

	}
	catch (const std::exception &error)
	{
		std::cerr << "wrong exception" << std::endl;
		return 2;
	}
	return 1;
}