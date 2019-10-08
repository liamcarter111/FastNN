#include "Linear.h"

float Linear::operator()(const float &x) const { return x; };

float Linear::Derivative(const float &x) const { return 1.0; }