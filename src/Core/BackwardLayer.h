#pragma once
#include "Activation.h"
#include "Layer.h"

class BackwardLayer : public Layer {
  Matrix m_weights;
  Activation *m_activation;

public:
  BackwardLayer(const int size, const int previousLayerSize,
                Activation *activation);

  static Layer &BackwardProp(Layer &out, const BackwardLayer &a,
                             const Layer &b);

  const Matrix &GetWeights() const;
  Matrix &GetWeights();

  Activation *GetActivation() const;
};