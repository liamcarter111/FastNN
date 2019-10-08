#pragma once

#include "../Core/Activation.h"
#include <algorithm>

struct ReLU final : Activation {
  float operator()(float x) const { return std::max((float)0, x); }
  float Derivative(float x) const { return x > 0.f ? 1.0f : 0.f; }
};