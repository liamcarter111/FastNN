#include "Network.h"
#include <cstring>

std::vector<float> Network::ForwardProp(const std::vector<float> &input) {
  std::vector<float> output(m_outputLayer.GetSize());
  memcpy(m_inputLayer.GetValues().Data(), input.data(),
         m_inputLayer.GetSize() * sizeof(float));

  ForwardLayer &fLayer = m_inputLayer;

  for (int i = 0; i < m_hiddenLayers.size(); i++) {
    ForwardLayer::ForwardProp(fLayer, (BackwardLayer &)m_hiddenLayers[i]);
    fLayer = m_hiddenLayers[i];
  }

  ForwardLayer::ForwardProp(fLayer, m_outputLayer);

  output.assign(m_outputLayer.GetValues().Data(),
                m_outputLayer.GetValues().Data() + m_outputLayer.GetSize());
  return output;
}