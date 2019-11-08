#pragma once

#include <Activation.h>
#include <Matrix.h>

struct Linear final : Activation {
  void Set(const Matrix &weightedInputs);
};