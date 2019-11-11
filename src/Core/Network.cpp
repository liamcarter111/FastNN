#include "Network.h"
#include <cassert>
#include <cstring>

Network::Network(const int inputSize, std::vector<Layer *> &layers, Cost *cost)
    : m_cost(cost), m_layers(layers) {
  assert(layers.size() > 0);
}

const Matrix &Network::ForwardProp(const Matrix &input) {

  const Matrix *previousLayerOutput = &input;

  // Run through all the layers (forwards).
  for (int i = 0; i < m_layers.size(); ++i) {
    Layer &currentLayer = *m_layers[i];
    currentLayer.ForwardProp(*previousLayerOutput);
    previousLayerOutput = &currentLayer.GetOutput();
  }

  return *previousLayerOutput;
}

double Network::Optimize(const Matrix &input, const Matrix &expected,
                         const double learningRate, const double momentumRate) {
  Matrix output = ForwardProp(input);

  m_cost->Set(output, expected);

  const double globalError = m_cost->GetError();

  if (learningRate != 0.0) {
    Matrix error = m_cost->GetGradients();

    // Run through all the layers except the last (backwards).
    for (size_t i = m_layers.size() - 1; i > 0; --i) {
      Layer &currentLayer = *m_layers[i];
      Layer &previousLayer = *m_layers[i - 1];

      currentLayer.BackwardProp(previousLayer.GetOutput(), error, learningRate,
                                momentumRate);
    }

    // Call the first layer with the network input.
    Layer &lastLayer = *m_layers.front();
    lastLayer.BackwardProp(input, error, learningRate, momentumRate);
  }

  return globalError;
};