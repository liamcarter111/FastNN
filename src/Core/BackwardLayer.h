#pragma once
#include "Activation.h"
#include "Layer.h"

class BackwardLayer : public Layer {
  Matrix m_weights;
  Matrix m_biases;
  Activation *m_activation;

public:
  BackwardLayer(const int size, const int previousLayerSize,
                Activation *activation);

  static void BackwardProp(const Layer &pL, BackwardLayer &cL,
                           const float &learningRate);

  const Matrix &GetWeights() const;

  Activation *GetActivation() const;

  const Matrix &GetBiases() const;
};