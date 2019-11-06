#include "Linear.h"

void Linear::Set(const Matrix &weightedInputs) {
  m_activations = weightedInputs;

  m_derivatives.Resize(weightedInputs.RowSize(), weightedInputs.ColSize());
  m_derivatives.Fill(1.0f);
};