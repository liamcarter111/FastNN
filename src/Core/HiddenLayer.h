#pragma once
#include "BackwardLayer.h"
#include "ForwardLayer.h"

class HiddenLayer : public ForwardLayer, public BackwardLayer {
public:
  HiddenLayer(const int size, const int previousLayerSize,
              Activation *activation)
      : Layer(size), ForwardLayer(size),
        BackwardLayer(size, previousLayerSize, activation) {}
};