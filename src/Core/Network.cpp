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

float Network::Optimize(const Matrix &input, const Matrix &expected,
                        const float &learningRate) {
  Matrix output = ForwardProp(input);

  m_cost->Set(output, expected);

  const float globalError = m_cost->GetError();

  Matrix error = m_cost->GetGradients();

  for (int i = m_layers.size() - 1; i >= 0; --i) {

    (*m_layers[i])
        .BackwardProp(i == 0 ? input : (*m_layers[i - 1]).GetOutput(),
                      learningRate, error);
  }

  return globalError;
};