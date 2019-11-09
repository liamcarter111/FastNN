#include "Tanh.h"
#include <cmath>

void Tanh::Set(const Matrix &weightedInputs) {
  m_activations =
      weightedInputs.Map([](const double &val) { return std::tanh(val); });
  m_derivatives =
      m_activations.Map([](const double &val) { return 1.0 - (val * val); });
}