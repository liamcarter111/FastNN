#pragma once

#include <Activation.h>

struct Sigmoid final : Activation {
  void Set(const Matrix &weightedInputs);
};