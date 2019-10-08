#include "Sigmoid.h"
#include <cmath>

float Sigmoid::operator()(const float &x) const {
  return 1.0f / (1.0f + std::exp(-x));
}

float Sigmoid::Derivative(const float &x) const {
  return std::exp(-x) / std::pow(1.0f + std::exp(-x), 2);
}