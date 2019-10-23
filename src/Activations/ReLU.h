#pragma once

#include <Activation.h>

struct ReLU final : Activation {
  void operator()(float *begin, float *const end) const;
  void Derivative(float *begin, float *const end) const;
};