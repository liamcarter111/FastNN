#pragma once
#include "HiddenLayer.h"
#include "InputLayer.h"
#include "OutputLayer.h"
#include <vector>

class Network final {
  InputLayer m_inputLayer;
  OutputLayer m_outputLayer;
  std::vector<HiddenLayer> m_hiddenLayers;

  std::vector<float> ForwardProp(const std::vector<float> &input);
};