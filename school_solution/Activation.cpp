
#include "Activation.h"

Matrix activation::relu(const Matrix &m) {
	Matrix output(m);
	for (int i = 0; i < m.get_rows() * m.get_cols(); i++) {
		if (m[i] < 0) {
			output[i] = 0;
		}
	}
	return output;
}

Matrix activation::softmax(const Matrix &m) {
	Matrix output(m);
	int size = m.get_rows() * m.get_cols();
	float sum = 0.0;
	for (int i = 0; i < size; i++) {
		float new_val = std::exp(m[i]);
		sum += new_val;
		output[i] = new_val;
	}
	output = (1 / sum) * output;
	return output;
}
