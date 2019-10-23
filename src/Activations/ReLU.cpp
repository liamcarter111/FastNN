#include "ReLU.h"
#include <algorithm>
#include <numeric>

void ReLU::operator()(float *begin, float *const end) const {
  std::fill(begin, end, std::accumulate(begin, end, 0.0f));
};

void ReLU::Derivative(float *begin, float *const end) const {
  std::fill(begin, end, std::accumulate(begin, end, 0.0f) > 0.f ? 1.0f : 0.f);
}