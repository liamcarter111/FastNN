#pragma once

#include <Activation.h>

struct Linear final : public Activation {
  void Set(const Matrix &weightedInputs);
};