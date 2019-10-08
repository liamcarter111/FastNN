#pragma once
#include "../Math/NumericFunction.h"

struct Activation : public NumericFunction {
  Activation() {}
  float Derivative(const float &x) const = 0;
};