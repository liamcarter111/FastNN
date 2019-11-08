#pragma once

#include <Activation.h>
#include <Matrix.h>

struct Sigmoid final : Activation {
  void Set(const Matrix &weightedInputs);
};