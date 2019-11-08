#pragma once

#include <Activation.h>
#include <Matrix.h>

struct Tanh final : Activation {
  void Set(const Matrix &weightedInputs);
};