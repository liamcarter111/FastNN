#pragma once

#include <Activation.h>
#include <cmath>

struct Tanh final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};