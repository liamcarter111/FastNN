#pragma once

#include <Activation.h>
#include <cmath>

struct Sigmoid final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};