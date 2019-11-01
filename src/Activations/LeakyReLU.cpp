#include "LeakyReLU.h"

#define _LeakyReLuMin 0.01f

void LeakyReLU::operator()(float *begin, float *const end) const {
  while (begin != end) {
    *begin = *begin > _LeakyReLuMin ? *begin : 0.0f;
    ++begin;
  }
};

void LeakyReLU::Derivative(float *begin, float *const end) const {
  while (begin != end) {
    *begin = *begin != 0.0f ? 1.0f : 0.0f;
    ++begin;
  }
}