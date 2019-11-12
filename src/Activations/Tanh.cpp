#include "Tanh.h"
#include <cmath>

void Tanh::Set(const Matrix &weightedInputs) {
  Matrix::MAP(
      weightedInputs, [](const double &val) { return std::tanh(val); },
      m_activations);

  Matrix::MAP(
      m_activations, [](const double &val) { return 1.0 - (val * val); },
      m_derivatives);
}