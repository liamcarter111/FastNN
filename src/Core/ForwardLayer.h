#pragma once
#include "Activation.h"
#include "BackwardLayer.h"
#include "Layer.h"

class ForwardLayer : public Layer {
public:
  ForwardLayer(const int size);

  static void ForwardProp(const ForwardLayer &a, BackwardLayer &b);
};