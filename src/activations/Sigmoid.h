#pragma once

#include "../core/Activation.h"
#include <cmath>

struct Sigmoid final : Activation {
  float operator()(float x) const { return 1.0f / (1.0f + std::exp(-x)); }
  float Derivative(float x) const {
    return std::exp(-x) / std::pow(1.0f + std::exp(-x), 2);
  }
};