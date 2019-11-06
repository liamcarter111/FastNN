#pragma once
#include "Activation.h"
#include <Matrix.h>
#include <vector>

struct Layer final {

  Layer(const int sizeOfLayer, Activation *const activation);

  ~Layer();

  const Matrix &GetOutput() const;

  void ForwardProp(const Matrix &pLActivations);
  void BackwardProp(const Matrix &pLActivations, const float &learningRate,
                    Matrix &error);

private:
  const int m_sizeOfLayer;
  Matrix m_weights;
  Matrix m_biases;
  Activation *const m_activation;
};