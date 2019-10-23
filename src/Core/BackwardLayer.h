#pragma once
#include "Activation.h"
#include "Layer.h"

class BackwardLayer : public Layer {
public:
  static Layer &BackwardProp(Layer &out, const BackwardLayer &a,
                             const Layer &b);
};