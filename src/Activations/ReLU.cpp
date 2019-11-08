#include "ReLU.h"

void ReLU::Set(const Matrix &weightedInputs) {

  m_activations.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());
  m_derivatives.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());

  for (size_t i = 0; i < m_activations.RowSize(); i++) {
    for (size_t j = 0; j < m_activations.ColSize(); j++) {
      if (weightedInputs(i, j) > 0.0) {
        m_activations(i, j) = weightedInputs(i, j);
        m_derivatives(i, j) = 1.0;
      } else {
        m_activations(i, j) = 0.0;
        m_derivatives(i, j) = 0.0;
      }
    }
  }
};