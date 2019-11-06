#pragma once

#include <Activation.h>

struct Linear final : Activation {
  void Set(const Matrix &weightedInputs);
};