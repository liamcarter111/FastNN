#include "Tanh.h"
#include <cmath>

float Tanh::operator()(const float &x) const { return std::tanh(x); }

float Tanh::Derivative(const float &x) const {
  return 1.0f - std::pow(std::tanh(x), 2);
}