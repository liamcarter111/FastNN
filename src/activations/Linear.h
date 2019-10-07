#pragma once

#include "../core/Activation.h"

template <typename Type> struct Linear final : Activation<Type> {
  Type operator()(Type x) const { return x; }
  Type Derivative(Type x) const { return (Type)1; }
};