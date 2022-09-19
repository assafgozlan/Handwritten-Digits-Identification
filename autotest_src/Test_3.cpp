//
// Created by User on 7/20/2020.
//

#include "autotest_utils.h"

int checkCopyCtor()
{
    Matrix M = get_ordered_matrix(7, 10);
    Matrix C(M);

    // Checking correct dimensions
    if (C.get_rows() != M.get_rows() || C.get_cols() != M.get_cols())
    {
	  M.~Matrix();
	  return 3;
    }

    // Checking correct values
    for(int i=0; i<M.get_cols()*M.get_rows(); i++)
    {
        if(M[i] != C[i])
        {
			std::cerr << "Values in copy ctor are not the same" << std::endl;
		  	M.~Matrix();
		  	return 2;
        }

    }

    // passing Rvalue to make sure the copy ctor takes a const reference
//    using Traits = function_traits<decltype(&Matrix::Matrix>;
//    if(!std::is_same<const Matrix&, Traits::argument<1>::type>::value)
//    {
//        std::cerr << "Operator= does not accept by const reference" << std::endl;
//        exit(2);
//    }
	return 0;

}

int main()
{
    return checkCopyCtor();
}