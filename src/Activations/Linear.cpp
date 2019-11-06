#include "Linear.h"

void Linear::Set(const Matrix &weightedInputs) {
  m_activations = weightedInputs;

  m_gradients.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());
  m_gradients.Fill(1.0f);
};