#include "Layer.h"
#include <cassert>
#include <iostream>

Layer::Layer(const int sizeOfLayer, Activation *const activation)
    : m_sizeOfLayer(sizeOfLayer), m_biases(sizeOfLayer, 1),
      m_activation(activation) {
  assert(sizeOfLayer > 0);
  assert(activation != nullptr);
}

const Matrix &Layer::GetOutput() const {
  return m_activation->GetActivations();
}

void Layer::ForwardProp(const Matrix &pLActivations) {

  if (m_weights.Size() == 0) {
    m_weights.Resize(m_sizeOfLayer, pLActivations.RowSize());

    m_weights.Randomize();
    m_biases.Randomize();

    m_weightsMomentum.Resize(m_weights.RowSize(), m_weights.ColSize());
    m_biasesMomentum.Resize(m_biases.RowSize(), m_biases.ColSize());

    m_weightsMomentum.Zero();
    m_biasesMomentum.Zero();
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
                         Matrix &error) {

  // Get the gradient
  Matrix gradient = error.Hadamard(m_activation->GetDerivatives());

  const Matrix deltaBiases = gradient * learningRate;
  const Matrix deltaWeights =
      (gradient * (pLActivations.Transpose()) * learningRate);

#if 0

  std::cout << "##########Layer##########" << std::endl;

  std::cout << "PrevOutput:" << std::endl;
  pLActivations.Print();

  std::cout << "Error:" << std::endl;
  error.Print();

  std::cout << "Gradient:" << std::endl;
  gradient.Print();

  std::cout << "Weights:" << std::endl;
  m_weights.Print();

  std::cout << "Delta Weights:" << std::endl;
  deltaWeights.Print();

  std::cout << "Bias:" << std::endl;
  m_biases.Print();

   std::cout << "Delta Bias:" << std::endl;
   deltaBiases.Print();

#endif

  m_biases -= m_biases.Hadamard(deltaBiases + m_biasesMomentum);
  m_weights -= m_weights.Hadamard(deltaWeights + m_weightsMomentum);

  // Calculate the gradient for the previous layer.
  error = m_weights.Transpose() * gradient;

  m_weightsMomentum = deltaWeights;
  m_biasesMomentum = deltaBiases;
}

void Layer::Print() const {
  std::cout << "Weights:" << std::endl;
  m_weights.Print();
  std::cout << "Biases:" << std::endl;
  m_biases.Print();
}