#include "ReLU.h"
#include <algorithm>

void ReLU::Set(const Matrix &weightedInputs) {
  m_activations =
      weightedInputs.Map([](const double &val) { return std::max(0.0, val); });
  m_derivatives = m_activations.Map(
      [](const double &val) { return val == 0.0 ? 0.0 : 1.0; });
};