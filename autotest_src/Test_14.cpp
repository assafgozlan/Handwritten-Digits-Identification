//
// Created by User on 12/26/2019.
//

// for the bigger main if Dense doesnt work properly it'll fail
// and so we won't check valeus here, but just getters etc.

#include "autotest_utils.h"

int checkDense()
/**
* function to check the existence of all dense class methods
*/
{
    Matrix m;
    Matrix bias;
    Matrix w;
    m[0] = 2;
    bias[0] = 1;
    w[0] = 3;

// check ctor of Dense
    Dense d(w, bias, activation::relu);

// check () operator
    Matrix D = d(m);
    std::cout << "checking dense getters and operator ()" << std::endl;
    std::cout << "checking () operator, should get 7" << std::endl << D[0] << std:: endl;
    if(D[0] != 7)
    {
	  	D.~Matrix();
	  	return 1;
    }

    // checking getters
    std::cout << "checking getters" << std::endl;
//    std::cout << (d.getActivation().get_activation_type() == RELU) <<std::endl;
// TODO add const version for get_activation_type maybe?
    std::cout << (d.get_bias()[0] == 1) << std::endl;
    if(d.get_bias()[0] != 1)
    {
	  	D.~Matrix();
	  	return 2;
    }
    std::cout << (d.get_weights()[0] == 3) << std::endl;
    if(d.get_weights()[0] != 3)
    {
	  D.~Matrix();
	  return 3;
    }
    return 0;
}

int main()
{
    return checkDense();
}
