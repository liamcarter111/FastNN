#pragma once

#include "../core/Activation.h"
#include <algorithm>

using namespace core;

template <typename Type, Type Lower = (Type)__FLT_EPSILON__>
struct ReLU final : Activation<Type> {
  Type operator()(Type x) const { return std::max(Lower, x); }
  Type Derivative(Type x) const { return x > Lower ? (Type)1 : Lower; }
};