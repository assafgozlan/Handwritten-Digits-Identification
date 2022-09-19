// Matrix.h
#include <iostream>
#include <cmath>

#define MEM_ERR "ERROR: No memory available for matrix"
#define DIM_ERR "ERROR: Matrices do not match dimensions"
#define BAD_DIM "ERROR: bad dimensions"
#define INDEX_ERR "ERROR: index out of boundaries"
#define STREAM_ERR "ERROR: Problem with input stream"
#define SIZE_ERR "ERROR: input stream size does not match matrix"

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims {
    int rows, cols;
} matrix_dims;

class Matrix {

 private:
  int _rows;
  int _cols;
  int _size;
  float *_matrix;

  void init ();
  void compare_dims (const Matrix &m) const;

 public:
  // constructors and destructor
  Matrix (int rows, int cols);
  Matrix ();
  Matrix (const Matrix &m);
  ~Matrix ();

  // methods
  int get_rows () const;
  int get_cols () const;
  Matrix &transpose ();
  Matrix &vectorize ();
  void plain_print () const;
  Matrix dot (const Matrix &m) const;
  float norm ();

  // operators
  Matrix operator+ (const Matrix &m) const;
  Matrix &operator= (const Matrix &m);
  Matrix operator* (const Matrix &m) const;
  Matrix operator* (const float &scalar) const;
  friend Matrix operator* (const float &scalar, const Matrix &matrix);
  Matrix &operator+= (const Matrix &m);
  float operator() (const int &i, const int &j) const;
  float operator[] (const int &i) const;

  // [] and () overloading
  float &operator() (const int &i, const int &j);
  float &operator[] (const int &i);

  // >> and <<
  friend std::ostream &operator<< (std::ostream &os, const Matrix &m);
  friend std::istream &operator>> (std::istream &is, Matrix &m);

};

#endif //MATRIX_H