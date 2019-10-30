#pragma once
#include "Activation.h"
#include "BackwardLayer.h"
#include "Layer.h"

class ForwardLayer : virtual public Layer {
public:
  ForwardLayer(const int size);

  static void ForwardProp(const ForwardLayer &pL, BackwardLayer &cL);
};