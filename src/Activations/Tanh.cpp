#include "Tanh.h"
#include <algorithm>
#include <cmath>
#include <numeric>

void Tanh::operator()(float *begin, float *const end) const {
  std::fill(begin, end, std::tanh(std::accumulate(begin, end, 0.0f)));
}

void Tanh::Derivative(float *begin, float *const end) const {
  std::fill(begin, end,
            1.0f - std::pow(std::tanh(std::accumulate(begin, end, 0.0f)), 2));
}