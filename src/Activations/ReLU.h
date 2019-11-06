#pragma once

#include <Activation.h>

struct ReLU final : Activation {
  void Set(const Matrix &weightedInputs);
};