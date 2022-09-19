//
// Created by yuval on 01-Oct-21.
//

#include "Matrix.h"

#define EPSILON 0.1

// private
void Matrix::init () noexcept (false)
{
  _size = _rows * _cols;
  _matrix = new float[_size];
}

void Matrix::compare_dims (const Matrix &m) const noexcept (false)
{
  if (_rows != m.get_rows () || _cols != m.get_cols ())
  {
	throw std::out_of_range (DIM_ERR);
  }
}

// ----------------------------CONSTRUCTORS----------------------------------

Matrix::Matrix () : _rows (1), _cols (1)
{
  init ();
  for (int i = 0; i < _size; i++)
  {
	_matrix[i] = 0;
  }

}

Matrix::Matrix (int rows, int cols) noexcept (false):
	_rows (rows), _cols (cols)
{
  if (rows <= 0 || cols <= 0)
  {
	throw std::length_error (BAD_DIM);
  }
  init ();
  for (int i = 0; i < _size; i++)
  {
	_matrix[i] = 0;
  }
}

Matrix::Matrix (const Matrix &m) : _rows (m._rows), _cols (m._cols)
{
  init ();
  for (int i = 0; i < _size; i++)
  {
	_matrix[i] = m[i];
  }
}

Matrix::~Matrix ()
{
  delete[] _matrix;
}


// ----------------------------METHODS---------------------------------------

int Matrix::get_rows () const
{
  return _rows;
}

int Matrix::get_cols () const
{
  return _cols;
}

Matrix &Matrix::transpose () noexcept (false)
{
  // create a new matrix
  float *new_matrix = new float[_size];

  // transpose the new matrix
  for (int i = 0; i < _rows; i++)
  {
	for (int j = 0; j < _cols; j++)
	{
	  new_matrix[j * _rows + i] = _matrix[i * _cols + j];
	}
  }

  // replace the old matrix
  delete[] _matrix;
  _matrix = new_matrix;

  // set the right dimensions
  int old_cols = _cols;
  _cols = _rows;
  _rows = old_cols;

  return *this;
}

Matrix &Matrix::vectorize ()
{
  _rows *= _cols;
  _cols = 1;

  return *this;
}

void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
  {
	for (int j = 0; j < _cols; j++)
	{
	  std::cout << _matrix[i * _cols + j] << " ";
	}
	std::cout << std::endl;
  }
}

Matrix Matrix::dot (const Matrix &m) const
{
  // check dimensions are identical
  compare_dims (m);

  Matrix dot_product (_rows, _cols);
  for (int i = 0; i < _size; i++)
  {
	dot_product[i] = _matrix[i] * m[i];
  }

  return dot_product;
}

float Matrix::norm ()
{
  float norm = 0.0;
  for (int i = 0; i < _size; i++)
  {
	norm += _matrix[i] * _matrix[i];
  }

  return std::sqrt (norm);
}

// ----------------------------OPERATORS-------------------------------------

Matrix Matrix::operator+ (const Matrix &m) const
{
  // check dimensions are identical
  compare_dims (m);

  Matrix sum (*this);
  for (int i = 0; i < _size; i++)
  {
	sum[i] += m[i];
  }

  return sum;
}

Matrix &Matrix::operator= (const Matrix &m)
{
  if (this == &m)
  {
	return *this;
  }

  delete[] _matrix;
  _rows = m._rows;
  _cols = m._cols;
  init ();
  for (int i = 0; i < _size; i++)
  {
	_matrix[i] = m[i];
  }

  return *this;
}

Matrix Matrix::operator* (const Matrix &m) const noexcept (false)
{
  // check dimensions are identical
  if (_cols != m.get_rows ())
  {
	throw std::length_error (DIM_ERR);
  }

  Matrix mult (_rows, m.get_cols ());
  for (int i = 0; i < mult._rows; i++)
  {
	for (int j = 0; j < mult._cols; j++)
	{
	  for (int k = 0; k < _cols; k++)
	  {
		mult (i, j) += (*this) (i, k) * m (k, j);
	  }
	}
  }

  return mult;
}

Matrix Matrix::operator* (const float &scalar) const
{
  Matrix mult (*this);
  for (int i = 0; i < _size; i++)
  {
	mult._matrix[i] *= scalar;
  }

  return mult;
}

Matrix operator* (const float &scalar, const Matrix &matrix)
{
  return matrix * scalar;
}

Matrix &Matrix::operator+= (const Matrix &m)
{
  // check dimensions are identical
  compare_dims (m);

  for (int i = 0; i < _size; i++)
  {
	_matrix[i] += m[i];
  }

  return *this;
}

float Matrix::operator() (const int &i, const int &j) const noexcept (false)
{
  if (i < 0 || i >= _rows || j < 0 || j >= _cols)
  {
	throw std::out_of_range (INDEX_ERR);

  }
  return _matrix[i * _cols + j];
}

float &Matrix::operator() (const int &i, const int &j) noexcept (false)
{
  if (i < 0 || i >= _rows || j < 0 || j >= _cols)
  {
	throw std::out_of_range (INDEX_ERR);
  }
  return _matrix[i * _cols + j];
}

float Matrix::operator[] (const int &i) const noexcept (false)
{
  if (i < 0 || i >= _size)
  {
	throw std::out_of_range (INDEX_ERR);
  }

  return _matrix[i];
}

float &Matrix::operator[] (const int &i) noexcept (false)
{
  if (i < 0 || i >= _size)
  {
	throw std::out_of_range (INDEX_ERR);
  }

  return _matrix[i];
}

std::ostream &operator<< (std::ostream &os, const Matrix &m)
{
  for (int i = 0; i < m._rows; ++i)
  {
	for (int j = 0; j < m._cols; ++j)
	{
	  os << ((m (i, j) > EPSILON) ? "*" : " ");
	}
	os << std::endl;
  }
  return os;
}

std::istream &operator>> (std::istream &is, Matrix &m) noexcept (false)
{
  if (!is)
  {
	throw std::runtime_error (STREAM_ERR);
  }
  if (!is.read ((char *) m._matrix, m._cols * m._rows * sizeof (float)))
  {
	throw std::runtime_error (SIZE_ERR);
  }
  return is;
}
