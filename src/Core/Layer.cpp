#include "Layer.h"
#include <cassert>
#include <cmath>
#include <iostream>

Layer::Layer(const int sizeOfLayer, Activation *const activation)
    : m_sizeOfLayer(sizeOfLayer), m_activation(activation) {
  assert(sizeOfLayer > 0);
  assert(activation != nullptr);
}

const Matrix &Layer::GetOutput() const {
  return m_activation->GetActivations();
}

void Layer::ForwardProp(const Matrix &pLActivations) {
  assert(pLActivations.RowSize() == m_weights.ColSize());
  assert(pLActivations.ColSize() == 1);

  assert(m_biases.RowSize() == m_sizeOfLayer);
  assert(m_biases.ColSize() == 1);

  // Multiply the neron values of the previous Layer by the weights of the
  // current layer, then put the results into the values of current layer.
  Matrix weightedInputs = m_weights * pLActivations;

  // Apply the bias, to align the activation.
  weightedInputs += m_biases;

  // Apply the activation to the new computed values of the current layer.
  m_activation->Set(weightedInputs);
}

void Layer::BackwardProp(const Matrix &pLActivations, Matrix &error,
                         const double learningRate, const double momentumRate) {
  assert(pLActivations.RowSize() == m_weights.ColSize());
  assert(pLActivations.ColSize() == 1);

  assert(error.RowSize() == m_sizeOfLayer);
  assert(error.ColSize() == 1);

  assert(m_biases.RowSize() == m_sizeOfLayer);
  assert(m_biases.ColSize() == 1);

  // Get the gradient
  Matrix gradient = error.Hadamard(m_activation->GetDerivatives());

  const Matrix deltaBiases = gradient;
  const Matrix deltaWeights = (gradient * (pLActivations.Transpose()));

#if 1

  std::cout << "##########Layer##########" << std::endl;

  std::cout << "Error:" << std::endl;
  error.Print();

  std::cout << "Previous Out:" << std::endl;
  pLActivations.Print();

  std::cout << "Previous OutT:" << std::endl;
  pLActivations.Transpose().Print();

  std::cout << "Derivatives:" << std::endl;
  m_activation->GetDerivatives().Print();

  std::cout << "Gradient:" << std::endl;
  gradient.Print();

  std::cout << "Weights:" << std::endl;
  m_weights.Print();

  std::cout << "Bias:" << std::endl;
  m_biases.Print();

  std::cout << "Delta Weights:" << std::endl;
  deltaWeights.Print();

  std::cout << "Delta Bias:" << std::endl;
  deltaBiases.Print();

#endif

  // Calculate the gradient for the previous layer.
  error = m_weights.Transpose() * gradient;

  m_biases += m_biases.Hadamard(deltaBiases * learningRate +
                                m_biasesMomentum * momentumRate);
  m_weights += m_weights.Hadamard(deltaWeights * learningRate +
                                  m_weightsMomentum * momentumRate);

  m_weightsMomentum = deltaWeights;
  m_biasesMomentum = deltaBiases;
}

void Layer::Print() const {
  std::cout << "Weights:" << std::endl;
  m_weights.Print();
  std::cout << "Biases:" << std::endl;
  m_biases.Print();
}

void Layer::Init(const int previousLayerSize) {
  Matrix weights(m_sizeOfLayer, previousLayerSize);
  Matrix biases(m_sizeOfLayer, 1);

  weights.Randomize();
  biases.Randomize();

  // weights *= std::sqrt(2.0 / previousLayerSize);

  Init(previousLayerSize, weights, biases);
}

void Layer::Init(const int previousLayerSize, const Matrix &weights,
                 const Matrix &biases) {
  assert(previousLayerSize > 0);

  assert(weights.ColSize() == previousLayerSize);
  assert(weights.RowSize() == m_sizeOfLayer);

  assert(biases.ColSize() == 1);
  assert(biases.RowSize() == m_sizeOfLayer);

  m_weights = weights;
  m_biases = biases;

  m_weightsMomentum.Resize(m_weights.RowSize(), m_weights.ColSize());
  m_biasesMomentum.Resize(m_biases.RowSize(), m_biases.ColSize());

  m_weightsMomentum.Zero();
  m_biasesMomentum.Zero();
}

const int &Layer::GetSize() const { return m_sizeOfLayer; }