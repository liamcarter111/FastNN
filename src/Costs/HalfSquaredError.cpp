#include "HalfSquaredError.h"
#include <cassert>
#include <numeric>

void HalfSquaredError::Set(const Matrix &prediction, const Matrix &expected) {
  assert(prediction.ColSize() == expected.ColSize());
  assert(prediction.RowSize() == expected.RowSize());

  // MSE (over 2)
  // 1/2 * sum(x' - x)^2

  // get the difference
  Matrix diff = prediction - expected;
  // square them
  diff *= diff;
  // sum them
  float sumOfSqaures =
      std::accumulate(diff.Data(), diff.Data() + diff.RowSize(), 0.0f);
  // divide by 2.
  m_error = 0.5 * sumOfSqaures;

  // get the partial derivative for the error.
  // power rule -> 1/2 * 2 * (x' - x)
  // = (x' - x)

  // get the difference, thats it
  m_gradients = diff;
};