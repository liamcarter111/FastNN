#pragma once

#include <Cost.h>

struct RootMeanSquareError final : Cost {
  float operator()(const float *actualBegin, const float *const actualEnd,
                   const float *expectedBegin) const;
};