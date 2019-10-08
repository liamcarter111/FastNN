#pragma once
#include "../Math/NumericFunction.h"

struct Activation : public NumericFunction {
  Activation() {}
  virtual float Derivative(float x) const = 0;
};