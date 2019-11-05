#pragma once
#include "Cost.h"
#include "HiddenLayer.h"
#include "InputLayer.h"
#include "OutputLayer.h"
#include <vector>

class Network final {
  Cost &m_cost;
  InputLayer m_inputLayer;
  OutputLayer m_outputLayer;
  std::vector<HiddenLayer> m_hiddenLayers;

public:
  Network(InputLayer &inputLayer, std::vector<HiddenLayer> &hiddenLayers,
          OutputLayer &outputLayer, Cost &cost);

  const Matrix &ForwardProp();

  float Optimize(Matrix &expected);
};