#pragma once

#include <Cost.h>
#include <Matrix.h>

class HalfSquaredError final : public Cost {
  void Set(const Matrix &prediction, const Matrix &expected);
};