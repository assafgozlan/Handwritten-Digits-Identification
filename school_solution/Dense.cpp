//
// Created by yuval on 01-Oct-21.
//

#include "Dense.h"

Dense::Dense (const Matrix &w, const Matrix &bias,
              activation::Func act_type)
{
  _bias = bias;
  _weights = w;
  _activation = act_type;
}

Matrix Dense::get_weights () const
{
  return _weights;
}

Matrix Dense::get_bias () const
{
  return _bias;
}

activation::Func Dense::get_activation () const
{
  return _activation;
}

Matrix Dense::operator() (const Matrix &m) const
{
  return _activation ((_weights * m) + _bias);
}
