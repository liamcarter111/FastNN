#pragma once

#include <Cost.h>
#include <Matrix.h>

struct SquaredError final : Cost {
  void Set(const Matrix &prediction, const Matrix &expected);
};