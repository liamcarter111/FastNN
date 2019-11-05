#include "ForwardLayer.h"

ForwardLayer::ForwardLayer(const int size) : Layer(size) {}

void ForwardLayer::ForwardProp(const ForwardLayer &pL, BackwardLayer &cL) {
  // Multiply the neron values of the previous Layer by the weights of the
  // current layer, then put the results into the values of current layer.
  Matrix::MUL(cL.GetValues(), cL.GetWeights(), pL.GetValues());

  // Apply the bias, to align the activation.
  cL.GetValues() += cL.GetBiases();

  // Apply the activation to the new computed values of the current layer.
  cL.GetActivation()->Set(cL.GetValues());
}