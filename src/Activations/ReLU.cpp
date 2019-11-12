#include "ReLU.h"
#include <algorithm>

void ReLU::Set(const Matrix &weightedInputs) {
  Matrix::MAP(
      weightedInputs, [](const double &val) { return std::max(0.0, val); },
      m_activations);

  Matrix::MAP(
      m_activations, [](const double &val) { return val == 0.0 ? 0.0 : 1.0; },
      m_derivatives);
};