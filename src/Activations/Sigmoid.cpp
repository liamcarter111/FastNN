#include "Sigmoid.h"
#include <algorithm>
#include <cmath>
#include <numeric>

void Sigmoid::operator()(float *begin, float *const end) const {
  while (begin != end) {
    *begin = 1.0f / (1.0f + std::exp(-*begin));
    ++begin;
  }
}

void Sigmoid::Derivative(float *begin, float *const end) const {
  while (begin != end) {
    *begin = 1.0f - *begin;
    ++begin;
  }
}