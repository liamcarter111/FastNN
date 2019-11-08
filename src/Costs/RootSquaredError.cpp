#include "RootSquaredError.h"
#include <cassert>
#include <cmath>

void RootSquaredError::Set(const Matrix &prediction, const Matrix &expected) {
  assert(prediction.ColSize() == expected.ColSize());
  assert(prediction.RowSize() == expected.RowSize());
  Matrix diff = prediction - expected;
  Matrix diffSqaures = diff.Pow(2);
  m_error = diffSqaures.Accumulate() / expected.RowSize();
  m_gradients = diff;
};