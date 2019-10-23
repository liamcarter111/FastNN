#include "Linear.h"
#include <algorithm>
#include <numeric>

void Linear::operator()(float *begin, float *const end) const {
  std::fill(begin, end, std::accumulate(begin, end, 0.0f));
};

void Linear::Derivative(float *begin, float *const end) const {
  std::fill(begin, end, 1.0f);
}