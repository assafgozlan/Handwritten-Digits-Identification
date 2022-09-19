//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

void checkParenthesisUnderLimit()
{
	Matrix M = Matrix(3, 3);
	for (int i = 0; i < M.get_cols() * M.get_rows(); i++)
	{
		M[i] = i;
	}
	std::cout << "Checking under limit in parenthesis" << std::endl;
	std::cout << M(-1, -1) << std::endl;
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
		checkParenthesisUnderLimit();
	}

	catch (const std::out_of_range &error)
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
