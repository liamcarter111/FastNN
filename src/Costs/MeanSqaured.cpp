#include "MeanSqaured.h"
#include <numeric>

float MeanSqaured::operator()(const float *actualBegin,
                              const float *const actualEnd,
                              const float *expectedBegin) const {
  const float n = (float)(actualEnd - actualBegin);
  float sum =
      std::accumulate(actualBegin, actualEnd, 0.0f, std::minus<float>());

  return sum * sum / n;
};

float MeanSqaured::Derivative(const float *actualBegin,
                              const float *const actualEnd,
                              const float *expectedBegin) const {
  const float n = (float)(actualEnd - actualBegin);
  float sum =
      std::accumulate(actualBegin, actualEnd, 0.0f, std::minus<float>());

  return sum * sum / 2 * n;
}