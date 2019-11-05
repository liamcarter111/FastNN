#pragma once
#include "Activation.h"
#include "Layer.h"

class BackwardLayer : virtual public Layer {
  Matrix m_weights;
  Matrix m_biases;
  Activation &m_activation;

public:
  BackwardLayer(const int size, const int previousLayerSize,
                Activation &activation);

  static void BackwardProp(const Layer &pL, BackwardLayer &cL,
                           const float &learningRate, Matrix &errors);

  const Matrix &GetWeights() const;

  const Activation &GetActivation() const;

  Activation &GetActivation();

  const Matrix &GetBiases() const;
};