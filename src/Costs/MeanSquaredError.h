#pragma once

#include <Cost.h>
#include <Matrix.h>

struct MeanSquaredError final : Cost {
  void Set(const Matrix &prediction, const Matrix &expected);
};