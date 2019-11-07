#include "HalfSquaredError.h"
#include <cassert>
#include <iostream>
#include <numeric>

void HalfSquaredError::Set(const Matrix &prediction, const Matrix &expected) {
  assert(prediction.ColSize() == expected.ColSize());
  assert(prediction.RowSize() == expected.RowSize());

  // MSE (over 2)
  // 1/2 * sum(x' - x)^2

  // get the difference
  Matrix diff = prediction - expected;

  // square them
  Matrix diffSqaures = diff.Pow(2);
  // sum them
  float sumOfSqaures = diffSqaures.Accumulate();
  // divide by 2.
  m_error = 0.5 * sumOfSqaures;

  // Get the partial derivative for the error.
  m_gradients = diff;
  // std::cout << "ERROR GRADIENT:" << prediction(0, 0) - expected(0, 0)
  //           << std::endl;
};