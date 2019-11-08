#pragma once

#include <Cost.h>
#include <Matrix.h>

struct RootSquaredError final : Cost {
  void Set(const Matrix &prediction, const Matrix &expected);
};