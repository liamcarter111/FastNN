#include "Layer.h"
#include <cassert>

Layer::Layer(const int sizeOfLayer, Activation *const activation)
    : m_sizeOfLayer(sizeOfLayer), m_biases(sizeOfLayer, 1),
      m_activation(activation) {
  assert(sizeOfLayer > 0);
  assert(activation != nullptr);
}

Layer::~Layer() {
  // why?
  int i = 0;
}

const Matrix &Layer::GetOutput() const {
  return m_activation->GetActivations();
}

void Layer::ForwardProp(const Matrix &pLActivations) {

  if (m_weights.Size() == 0) {
    m_weights.Resize(m_sizeOfLayer, pLActivations.RowSize());
    m_weights.Randomize();
  }

  // Multiply the neron values of the previous Layer by the weights of the
  // current layer, then put the results into the values of current layer.
  Matrix weightedInputs = m_weights * pLActivations;

  // Apply the bias, to align the activation.
  weightedInputs += m_biases;

  // Apply the activation to the new computed values of the current layer.
  m_activation->Set(weightedInputs);
}

void Layer::BackwardProp(const Matrix &pLActivations, const float &learningRate,
                         Matrix &gradients) {

  // deltaBias = learningRate * error * x
  // deltaWeights = learningRate * error

  gradients = gradients * m_activation->GetGradients();

  const Matrix deltaBiases = gradients;
  const Matrix deltaWeights = gradients * pLActivations.Transpose();

  m_biases -= m_biases.Hadamard(deltaBiases) * learningRate;
  m_weights -= m_weights.Hadamard(deltaWeights) * learningRate;
}