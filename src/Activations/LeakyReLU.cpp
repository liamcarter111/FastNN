#include "LeakyReLU.h"
#include <algorithm>
#include <cfloat>

float LeakyReLU::operator()(const float &x) const {
  return std::max(FLT_EPSILON, x);
};

float LeakyReLU::Derivative(const float &x) const {
  return x > FLT_EPSILON ? 1.0f : FLT_EPSILON;
}