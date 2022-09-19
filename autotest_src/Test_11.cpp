//
// Created by User on 7/21/2020.
//

#include "autotest_utils.h"

int checkParenthesis()
{
    using Traits = function_traits<decltype(&activation::relu)>;
    if(!std::is_same<const Matrix&, Traits::argument<0>::type>::value)
    {
        std::cerr << "relu does not accept by const reference" << std::endl;
        return 1;
    }

    using Traits2 = function_traits<decltype(&activation::softmax)>;
    if(!std::is_same<const Matrix&, Traits2::argument<0>::type>::value)
    {
      std::cerr << "softmax does not accept by const reference" << std::endl;
	  return 1;

    }
  	return 0;

}

int main()
{
    return checkParenthesis();
}
