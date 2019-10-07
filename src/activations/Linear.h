#pragma once

#include "../core/Activation.h"

struct Linear final : Activation {
  float operator()(float x) const { return x; }
  float Derivative(float x) const { return 1.0f; }
};