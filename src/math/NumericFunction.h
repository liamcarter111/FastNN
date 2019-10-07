#pragma once

template <typename Type> struct NumericFunction {
  /**
   * Get the value of Y at X.
   */
  virtual Type operator()(Type x) const = 0;
  /**
   * Get the aproximate derivative.
   * If not overridden by the derived class.
   */
  virtual Type Derivative(Type x) const;
};