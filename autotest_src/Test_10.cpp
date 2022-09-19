//
// Created by User on 7/21/2020.
//

#include "autotest_utils.h"

int checkActivationType()
{

    Matrix weights(5,1);
    Matrix bias(5,1);
    Dense const_dense1 = Dense(weights, bias, activation::relu);
    Dense const_dense2 = Dense(weights, bias, activation::softmax);

    if(const_dense1.get_activation() != activation::relu || const_dense2.get_activation() != activation::softmax)
    {
      return 1;
    }
	return 0;

}

int main()
{
    return checkActivationType();
}
