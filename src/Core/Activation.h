#pragma once

struct Activation {
  Activation() {}
  /**
   */
  virtual void operator()(float *begin, float *const end) const = 0;
  /**
   */
  virtual void Derivative(float *begin, float *const end) const = 0;
};