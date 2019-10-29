#include "BackwardLayer.h"
#include <Matrix.h>

BackwardLayer::BackwardLayer(const int size, const int previousLayerSize,
                             Activation *activation)
    : Layer(size), m_biases(1, size), m_weights(previousLayerSize, size),
      m_activation(activation) {
  m_weights.Randomize();
  m_biases.Randomize();
}

void BackwardLayer::BackwardProp(const Layer &pL, BackwardLayer &cL,
                                 const float &learningRate) {

  // deltaBias = learningRate * error * x
  // deltaWeights = learningRate * error

  // Local Error ??
  const Matrix errors(0, 0);

  Matrix gradients = cL.GetValues();
  (*cL.GetActivation())
      .Derivative(gradients.Data(), gradients.Data() + gradients.Size());

  const Matrix deltaBiases = errors * learningRate;
  const Matrix deltaWeights =
      errors * gradients * cL.GetValues().Transpose() * learningRate;
}

const Matrix &BackwardLayer::GetWeights() const { return m_weights; }

Activation *BackwardLayer::GetActivation() const { return m_activation; }

const Matrix &BackwardLayer::GetBiases() const { return m_biases; }