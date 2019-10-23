#include "LeakyReLU.h"
#include <algorithm>
#include <numeric>

#define _LeakyReLuMin 0.01f

void LeakyReLU::operator()(float *begin, float *const end) const {
  std::fill(begin, end,
            std::max(_LeakyReLuMin, std::accumulate(begin, end, 0.0f)));
};

void LeakyReLU::Derivative(float *begin, float *const end) const {
  std::fill(begin, end,
            std::accumulate(begin, end, 0.0f) > _LeakyReLuMin ? 1.0f
                                                              : _LeakyReLuMin);
}