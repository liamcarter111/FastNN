#include "Tanh.h"
#include <cmath>

void Tanh::operator()(float *begin, float *const end) const {
  while (begin != end) {
    *begin = std::tanh(*begin);
    ++begin;
  }
}

void Tanh::Derivative(float *begin, float *const end) const {
  while (begin != end) {
    *begin = 1.0f - ((*begin) * (*begin));
    ++begin;
  }
}