#include "RootMeanSquareError.h"
#include <numeric>

float RootMeanSquareError::operator()(const float *actualBegin,
                                      const float *const actualEnd,
                                      const float *expectedBegin) const {
  const float n = (float)(actualEnd - actualBegin);
  float sigma = 0.f;

  while (actualBegin != actualEnd) {
    const float diff = *expectedBegin - *actualBegin;
    sigma += diff * diff;
    ++actualBegin;
    ++expectedBegin;
  }

  return sigma / n;
};