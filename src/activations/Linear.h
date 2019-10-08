#pragma once

#include <Activation.h>

struct Linear final : Activation {
  float operator()(const float &x) const;
  float Derivative(const float &x) const;
};