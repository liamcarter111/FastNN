#include "ForwardLayer.h"

ForwardLayer::ForwardLayer(const int size) : Layer(size) {}

void ForwardLayer::ForwardProp(const ForwardLayer &a, BackwardLayer &b) {
  Matrix::MUL(b.GetValues(), b.GetWeights(), a.GetValues());

  (*b.GetActivation())(b.GetValues().Data(),
                       b.GetValues().Data() + b.GetSize());
}