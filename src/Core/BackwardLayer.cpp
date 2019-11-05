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
                                 const float &learningRate, Matrix &gradients) {

  // deltaBias = learningRate * error * x
  // deltaWeights = learningRate * error

  gradients *= cL.GetActivation()->GetGradients();

  const Matrix deltaBiases = gradients * learningRate;
  const Matrix deltaWeights = gradients * cL.GetValues().Transpose();

  cL.m_biases -= cL.m_biases * deltaBiases;
  cL.m_weights -= cL.m_weights * deltaWeights;
}

const Matrix &BackwardLayer::GetWeights() const { return m_weights; }

Activation *BackwardLayer::GetActivation() { return m_activation; }

const Activation *BackwardLayer::GetActivation() const { return m_activation; }

const Matrix &BackwardLayer::GetBiases() const { return m_biases; }