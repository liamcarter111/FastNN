#pragma once

#include <Cost.h>

struct MeanSqaured final : Cost {
  float operator()(const float *actualBegin, const float *const actualEnd,
                   const float *expectedBegin) const;
  float Derivative(const float *actualBegin, const float *const actualEnd,
                   const float *expectedBegin) const;
};