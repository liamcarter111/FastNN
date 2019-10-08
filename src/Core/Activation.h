#pragma once
#include <NumericFunction.h>

struct Activation : public NumericFunction {
  Activation() {}
  virtual float Derivative(const float &x) const = 0;
};