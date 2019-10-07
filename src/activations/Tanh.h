#pragma once

#include "../core/Activation.h"
#include <cmath>

struct Tanh final : Activation {
  float operator()(float x) const { return std::tanh(x); }
  float Derivative(float x) const { return 1.0f - std::pow(std::tanh(x), 2); }
};