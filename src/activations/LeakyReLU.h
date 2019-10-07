#pragma once

#include "../core/Activation.h"
#include <algorithm>
#include <cfloat>

struct LeakyReLU final : Activation {
  float operator()(float x) const { return std::max(FLT_EPSILON, x); }
  float Derivative(float x) const {
    return x > FLT_EPSILON ? 1.0f : FLT_EPSILON;
  }
};