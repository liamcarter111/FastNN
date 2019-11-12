#include "Sigmoid.h"
#include <cmath>

void Sigmoid::Set(const Matrix &weightedInputs) {
  Matrix::MAP(
      weightedInputs,
      [](const double &val) { return 1.0 / (1.0 + std::exp(-val)); },
      m_activations);

  Matrix::MAP(
      m_activations, [](const double &val) { return val * (1.0 - val); },
      m_derivatives);
};