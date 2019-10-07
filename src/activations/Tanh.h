#pragma once

#include "../core/Activation.h"
#include <cmath>

template <typename Type> struct Tanh final : Activation<Type> {
  Type operator()(Type x) const { return std::tanh(x); }
  Type Derivative(Type x) const { return (Type)1 - std::pow(std::tanh(x), 2); }
};