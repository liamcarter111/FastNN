#pragma once

#include <Activation.h>

class Linear final : public Activation {
  void Set(const Matrix &weightedInputs);
};