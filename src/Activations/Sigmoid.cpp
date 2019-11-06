#include "Sigmoid.h"
#include <cmath>

void Sigmoid::Set(const Matrix &weightedInputs) {

  m_activations.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());
  m_gradients.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());

  for (size_t i = 0; i < m_activations.RowSize(); i++) {
    for (size_t j = 0; j < m_activations.ColSize(); j++) {
      m_activations(i, j) = 1.0f / (1.0f + std::exp(-weightedInputs(i, j)));
      m_gradients(i, j) = 1.0f - m_activations(i, j);
    }
  }
};