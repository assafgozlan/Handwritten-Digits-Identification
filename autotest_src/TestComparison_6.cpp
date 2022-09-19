//
// Created by yuval on 13-Oct-21.
//

#include "autotest_utils.h"

/**
 * Should tell the students to
 * @param m
 * This test should catch an exception and return 0.
 *  If 1 was returned, then there is a mistake.
 *  2 on wrong exception
 */
void checkCtorBadDims()
{
	std::cout << "checking bad dims in matrix creation" << std::endl;
	// should expect to an exception
	Matrix m = Matrix(0, -1);
}

int main()
{

	try
	{

		checkCtorBadDims();
	}
	catch (const std::exception &error)
	{
		if (error is std::length_error )
		{
			std::cerr << error.what() << std::endl;
			return 0;
		}
		else
		{
			std::cerr << "wrong exception" << std::endl;
			return 2;

		}

	}

	return 1;
}