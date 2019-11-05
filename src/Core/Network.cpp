#include "Network.h"
#include <cstring>

Network::Network(InputLayer &inputLayer, std::vector<HiddenLayer> &hiddenLayers,
                 OutputLayer &outputLayer, Cost &cost)
    : m_inputLayer(inputLayer), m_outputLayer(outputLayer),
      m_hiddenLayers(hiddenLayers), m_cost(cost) {}

const Matrix &Network::ForwardProp() {

  ForwardLayer &fLayer = m_inputLayer;

  for (int i = 0; i < m_hiddenLayers.size(); ++i) {
    ForwardLayer::ForwardProp(fLayer, m_hiddenLayers[i]);
    fLayer = m_hiddenLayers[i];
  }

  ForwardLayer::ForwardProp(fLayer, m_outputLayer);

  return m_outputLayer.GetValues();
}

float Network::Optimize(Matrix &expected) {
  constexpr float learningRate = 0.1f;

  m_cost.Set(m_outputLayer.GetValues(), expected);

  const float globalError = m_cost.GetError();

  Matrix gradients = m_cost.GetGradients();

  BackwardLayer::BackwardProp(m_hiddenLayers.back(), m_outputLayer,
                              learningRate, gradients);

  for (int i = m_hiddenLayers.size() - 2; i > 1; --i) {
    BackwardLayer::BackwardProp(m_hiddenLayers[i], m_hiddenLayers[i],
                                learningRate, gradients);
  }

  return globalError;
};