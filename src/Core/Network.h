#pragma once
#include "Cost.h"
#include "HiddenLayer.h"
#include "InputLayer.h"
#include "OutputLayer.h"
#include <vector>

class Network final {
  Cost *const m_cost;
  InputLayer m_inputLayer;
  OutputLayer m_outputLayer;
  std::vector<HiddenLayer> m_hiddenLayers;

  Network(InputLayer &inputLayer, std::vector<HiddenLayer> &hiddenLayers,
          OutputLayer &outputLayer, Cost *cost);

  const Matrix &ForwardProp(Matrix &input);

  float Train(Matrix &input, Matrix &expected);
};