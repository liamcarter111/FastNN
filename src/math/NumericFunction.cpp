#include "NumericFunction.h"

template <typename Type> Type NumericFunction<Type>::Derivative(Type x) const {
  return ((*this)(__FLT_EPSILON__ + x) - (*this)(x)) / __FLT_EPSILON__;
}