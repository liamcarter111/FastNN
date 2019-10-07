#pragma once

#include "../core/Activation.h"
#include <algorithm>

template <typename Type> struct ReLU final : Activation<Type> {
  Type operator()(Type x) const { return std::max((Type)0, x); }
  Type Derivative(Type x) const { return x > (Type)0 ? (Type)1 : (Type)0; }
};