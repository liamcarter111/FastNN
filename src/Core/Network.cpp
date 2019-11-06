#include "Network.h"
#include <cassert>
#include <cstring>

Network::Network(std::vector<Layer *> &layers, Cost *cost)
    : m_layers(layers), m_cost(cost) {
  assert(layers.size() > 0);
}

const Matrix &Network::ForwardProp(const Matrix &input) {

  (*m_layers.front()).ForwardProp(input);

  for (int i = 1; i < m_layers.size(); ++i) {
    (*m_layers[i]).ForwardProp((*m_layers[i - 1]).GetOutput());
  }

  return (*m_layers.back()).GetOutput();
}

float Network::Optimize(const Matrix &input, const Matrix &expected) {
  ForwardProp(input);

  constexpr float learningRate = 0.1f;

  m_cost->Set((*m_layers.back()).GetOutput(), expected);

  const float globalError = m_cost->GetError();

  Matrix gradients = m_cost->GetGradients();

  for (int i = m_layers.size() - 1; i > 0; --i) {
    (*m_layers[i])
        .BackwardProp((*m_layers[i - 1]).GetOutput(), learningRate, gradients);
  }

  (*m_layers.back()).BackwardProp(input, learningRate, gradients);

  return globalError;
};