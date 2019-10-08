#include "ReLU.h"
#include <algorithm>

float ReLU::operator()(const float &x) const { return std::max((float)0, x); };

float ReLU::Derivative(const float &x) const { return x > 0.f ? 1.0f : 0.f; }