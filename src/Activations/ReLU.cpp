#include "ReLU.h"
#include <algorithm>
#include <numeric>

void ReLU::operator()(float *begin, float *const end) const {
  while (begin != end) {
    *begin = *begin > 0.0f ? *begin : 0.0f;
    ++begin;
  }
};

void ReLU::Derivative(float *begin, float *const end) const {
  while (begin != end) {
    *begin = *begin != 0.0f ? 1.0f : 0.0f;
    ++begin;
  }
}