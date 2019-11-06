#pragma once
#include "Cost.h"
#include "Layer.h"
#include <vector>

class Network final {
  Cost *m_cost;
  std::vector<Layer *> m_layers;

public:
  Network(std::vector<Layer *> &layers, Cost *cost);

  const Matrix &ForwardProp(const Matrix &input);

  float Optimize(const Matrix &input, const Matrix &expected);
};