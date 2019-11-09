#include "SquaredError.h"
#include <cassert>

void SquaredError::Set(const Matrix &prediction, const Matrix &expected) {
  assert(prediction.ColSize() == expected.ColSize());
  assert(prediction.RowSize() == expected.RowSize());
  Matrix diff = prediction - expected;
  Matrix diffSqaures = diff.Pow(2);
  m_error = diffSqaures.Accumulate() / 2.0;
  m_gradients = diff;
};