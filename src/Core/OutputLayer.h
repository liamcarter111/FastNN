#pragma once
#include "BackwardLayer.h"

class OutputLayer : public BackwardLayer {
public:
  OutputLayer(const int size, const int previousLayerSize,
              Activation &activation);
};