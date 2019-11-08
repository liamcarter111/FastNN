#pragma once

#include <Activation.h>
#include <Matrix.h>

struct ReLU final : Activation {
  void Set(const Matrix &weightedInputs);
};