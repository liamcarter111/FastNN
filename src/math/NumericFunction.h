#pragma once

struct NumericFunction {
  /**
   * Get the value of Y at X.
   */
  virtual float operator()(float x) const = 0;
  /**
   * Get the aproximate derivative.
   * If not overridden by the derived class.
   */
  virtual float Derivative(float x) const;
};