#pragma once

#include <Activation.h>
#include <algorithm>

struct ReLU final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};