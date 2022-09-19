//
// Created by Chend on 3/19/2021.
//
#include <iostream>
#include "Matrix.h"

/**
 * checking if there was an exception throwing
 * @return 0 on success
 *         1 in failure
 *         2 on wrong exception
 */
int main()
{

	Matrix M = Matrix(3, 3);
	for (int i = 0; i < M.get_cols() * M.get_rows(); i++)
	{
		M[i] = i;
	}
	//bad indexing
	std::cout << "Checking index over limit" << std::endl;
	try
	{
		std::cout << M(5, 5) << std::endl;
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