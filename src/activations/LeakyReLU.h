#pragma once

#include "../Core/Activation.h"

struct LeakyReLU final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};