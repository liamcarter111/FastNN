#include "Sigmoid.h"
#include <cmath>

void Sigmoid::Set(const Matrix &weightedInputs) {
  m_activations = weightedInputs.Map(
      [](const double &val) { return 1.0 / (1.0 + std::exp(-val)); });
  m_derivatives =
      m_activations.Map([](const double &val) { return val * (1.0 - val); });
};