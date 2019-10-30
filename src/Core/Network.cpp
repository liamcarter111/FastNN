#include "Network.h"
#include <cstring>

Network::Network(InputLayer &inputLayer, std::vector<HiddenLayer> &hiddenLayers,
                 OutputLayer &outputLayer, Cost *cost)
    : m_inputLayer(inputLayer), m_outputLayer(outputLayer),
      m_hiddenLayers(hiddenLayers), m_cost(cost) {}

const Matrix &Network::ForwardProp(Matrix &input) {

  ForwardLayer &fLayer = m_inputLayer;
  fLayer.GetValues() = input;

  for (int i = 0; i < m_hiddenLayers.size(); ++i) {
    ForwardLayer::ForwardProp(fLayer, m_hiddenLayers[i]);
    fLayer = m_hiddenLayers[i];
  }

  ForwardLayer::ForwardProp(fLayer, m_outputLayer);

  return m_outputLayer.GetValues();
}

float Network::Train(Matrix &input, Matrix &expected) {
  constexpr float learningRate = 0.1f;
  const Matrix &output = ForwardProp(input);

  const float globalError =
      (*m_cost)(output.Data(), output.Data() + input.Size(), expected.Data());

  Matrix localErrors = output - expected;

  BackwardLayer::BackwardProp(m_hiddenLayers.back(), m_outputLayer,
                              learningRate, localErrors);

  for (int i = m_hiddenLayers.size() - 2; i > 1; --i) {
    BackwardLayer::BackwardProp(m_hiddenLayers[i], m_hiddenLayers[i],
                                learningRate, localErrors);
  }

  return globalError;
};