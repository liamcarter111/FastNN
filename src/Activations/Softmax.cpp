#include "Softmax.h"
#include <algorithm>
#include <cmath>
#include <numeric>

void Softmax::operator()(float *begin, float *const end) const {
  std::transform(begin, end, begin, [](float v) { return std::exp(v); });
  float sumOfExps = std::accumulate(begin, end, 0.0f);
  if (sumOfExps != 0.0f) {
    std::transform(begin, end, begin,
                   [&sumOfExps](float v) { return v / sumOfExps; });
  } else {
    std::fill(begin, end, 0.0f);
  }
}

void Softmax::Derivative(float *begin, float *const end) const {}