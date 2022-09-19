//
// Created by yuval on 01-Oct-21.
//

#include "MlpNetwork.h"

#define TEN 10

MlpNetwork::MlpNetwork (Matrix weights[MLP_SIZE], Matrix biases[MLP_SIZE]) :
// understand why
// this initialization is correct
    _layers{Dense (weights[0], biases[0], activation::relu),
            Dense (weights[1], biases[1], activation::relu),
            Dense (weights[2], biases[2], activation::relu),
            Dense (weights[3], biases[3], activation::softmax)}
{}

digit MlpNetwork::operator() (const Matrix &m) const
{
  Matrix output (m);
  for (const auto &layer : _layers)
    {
      output = layer (output);
    }

  unsigned int result = 0;
  float prob = 0.0;
  for (int i = 0; i < TEN; i++)
    {
      if (output[i] > prob)
        {
          result = i;
          prob = output[i];
        }
    }
  return digit{result, prob};
}
