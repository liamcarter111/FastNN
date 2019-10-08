#include "Layer.h"

Layer &Layer::ForwardProp(Layer &out, const Layer &a, const Layer b) {

  Matrix::MUL(out.m_scores, a.m_weights, b.m_scores);

  return out;
}