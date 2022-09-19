//
// Created by yuval on 13-Oct-21.
//


#include "Dense.h"
#include <iostream>

/**
 * call on const objects to make sure Dense getters are const functions
 * if this compiles and returns true we can pass
 * @return
 */
bool testDenseGetters()
{
    std::cout << "testing if there is a const version for Dense getters" << std::endl;
    Matrix weights(5,1);
    Matrix bias(5,1);
    const Dense const_dense = Dense(weights, bias, activation::relu);
    const_dense.get_weights();
    const_dense.get_bias();
    const_dense.get_activation();
    return true;
}

int main()
{
    testDenseGetters();
}
