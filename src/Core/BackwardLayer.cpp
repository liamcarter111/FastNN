#include "BackwardLayer.h"
#include <Matrix.h>

BackwardLayer::BackwardLayer(const int size, const int previousLayerSize,
                             Activation *activation)
    : Layer(size), m_weights(previousLayerSize, size),
      m_activation(activation) {
  Matrix::RANDOM(m_weights);
}

Layer &BackwardLayer::BackwardProp(Layer &out, const BackwardLayer &a,
                                   const Layer &b) {
  return out;
}

const Matrix &BackwardLayer::GetWeights() const { return m_weights; }
Matrix &BackwardLayer::GetWeights() { return m_weights; }

Activation *BackwardLayer::GetActivation() const { return m_activation; }