//
// Created by yuval on 01-Oct-21.
//
#include "Activation.h"

#ifndef DENSE_H
#define DENSE_H

class Dense {
 public:
  Dense (const Matrix &w, const Matrix &bias, activation::Func act_type);
  Matrix get_weights () const;
  Matrix get_bias () const;
  activation::Func get_activation () const;
  Matrix operator() (const Matrix &m) const;

 private:
  Matrix _weights;
  Matrix _bias;
  activation::Func _activation;
};

#endif //DENSE_H
