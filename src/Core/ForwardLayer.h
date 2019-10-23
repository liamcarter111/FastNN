#pragma once
#include "Activation.h"
#include "Layer.h"

class ForwardLayer : public Layer {
public:
  static Layer &ForwardProp(Layer &out, const ForwardLayer &a, const Layer &b);
};