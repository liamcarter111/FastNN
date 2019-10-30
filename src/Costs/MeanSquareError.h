#pragma once

#include <Cost.h>

struct MeanSquareError final : public Cost {
  float operator()(const float *actualBegin, const float *const actualEnd,
                   const float *expectedBegin) const;
};