//
// Created by yuval on 13-Oct-21.
//

#include "Activation.h"
#include <iostream>

/**
 * call on const objects to make sure get_activation_type is a const function
 * if this compiles and returns true we can pass
 * @return
 */
bool testGetActivationType()
{
    std::cout << "testing if relu and softmax exist" << std::endl;
    (void) activation::relu;
    (void) activation::softmax;
    return true;
}

int main()
{
    testGetActivationType();
}
