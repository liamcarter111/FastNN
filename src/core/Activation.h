#pragma once
#include "../math/NumericFunction.h"

struct Activation : public NumericFunction {
  Activation() {}
  virtual float Derivative(float x) const = 0;
};