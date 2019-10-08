#pragma once

#include <Activation.h>

struct LeakyReLU final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};