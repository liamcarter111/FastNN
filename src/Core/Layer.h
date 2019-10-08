#pragma once
#include <Matrix.h>

class Layer final {
  Matrix m_weights;
  Matrix m_scores;

public:
  static Layer &ForwardProp(Layer &out, const Layer &a, const Layer b);
};