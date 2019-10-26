#include "InputLayer.h"
#include <cstring>

InputLayer::InputLayer(const std::vector<float> &values)
    : ForwardLayer(values.size()) {
  memcpy(GetValues().Data(), values.data(), values.size() * sizeof(float));
}