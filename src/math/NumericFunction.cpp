#include "NumericFunction.h"
#include <cfloat>

float NumericFunction::Derivative(const float &x) const {
  return ((*this)(FLT_EPSILON + x) - (*this)(x)) / FLT_EPSILON;
}