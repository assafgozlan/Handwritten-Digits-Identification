//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

/**
 * Should tell the students to
 * @param m
 * This test should catch an exception and return 0.
 *  If 1 was returned, then there is a mistake.
 *  2 on wrong exception
 */
void checkBadDimsAdd()
{
	Matrix M = Matrix(3, 3);
	for (int i = 0; i < M.get_cols() * M.get_rows(); i++)
	{
		M[i] = i;
	}
	Matrix B = Matrix();

	std::cout << "checking bad dims for addition" << std::endl;
	// should expect an exception
	M = M + B;
}

int main()
{
	try
	{
		checkBadDimsAdd();
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