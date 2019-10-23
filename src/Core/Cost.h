#pragma once

struct Cost {
  Cost() {}
  /**
   */
  virtual float operator()(const float *actualBegin,
                           const float *const actualEnd,
                           const float *expectedBegin) const = 0;
  /**
   */
  virtual float Derivative(const float *actualBegin,
                           const float *const actualEnd,
                           const float *expectedBegin) const = 0;
};