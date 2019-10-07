#pragma once

#include "../core/Activation.h"
#include <cmath>

template <typename Type> struct Sigmoid final : Activation<Type> {
  Type operator()(Type x) const { return (Type)1 / ((Type)1 + std::exp(-x)); }
  Type Derivative(Type x) const {
    return std::exp(-x) / std::pow((Type)1 + std::exp(-x), (Type)2);
  }
};