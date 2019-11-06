#include "ReLU.h"

void ReLU::Set(const Matrix &weightedInputs) {

  m_activations.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());
  m_derivatives.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());

  for (size_t i = 0; i < m_activations.RowSize(); i++) {
    for (size_t j = 0; j < m_activations.ColSize(); j++) {
      m_activations(i, j) =
          weightedInputs(i, j) > 0.0f ? weightedInputs(i, j) : 0.0f;
      m_derivatives(i, j) = m_activations(i, j) == 0.0f ? 0.0f : 1.0f;
    }
  }
};