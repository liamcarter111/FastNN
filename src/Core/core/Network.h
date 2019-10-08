#pragma once
#include "Layer.h"
#include <vector>


class Network final {
  std::vector<Layer> m_layers;
};