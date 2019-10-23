#include "Sigmoid.h"
#include <algorithm>
#include <cmath>
#include <numeric>

void Sigmoid::operator()(float *begin, float *const end) const {
  std::fill(begin, end,
            1.0f / (1.0f + std::exp(-std::accumulate(begin, end, 0.0f))));
}

void Sigmoid::Derivative(float *begin, float *const end) const {
  const float sum = std::accumulate(begin, end, 0.0f);
  std::fill(begin, end, std::exp(-sum) / std::pow(1.0f + std::exp(-sum), 2));
}