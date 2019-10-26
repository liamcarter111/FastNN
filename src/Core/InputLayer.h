#pragma once
#include "ForwardLayer.h"

class InputLayer : public ForwardLayer {
public:
  InputLayer(const std::vector<float> &values);
};