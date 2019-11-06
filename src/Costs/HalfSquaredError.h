#pragma once

#include <Cost.h>
#include <Matrix.h>

struct HalfSquaredError final : Cost {
  void Set(const Matrix &prediction, const Matrix &expected);
};