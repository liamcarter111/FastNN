#pragma once
#include "Activation.h"
#include <Matrix.h>
#include <vector>

struct Layer final {
  Layer(const int sizeOfLayer, Activation *const activation);

  const Matrix &GetOutput() const;

  void ForwardProp(const Matrix &pLActivations);
  void BackwardProp(const Matrix &pLInput, const float &learningRate,
                    Matrix &error);

  void Print() const;

private:
  const int m_sizeOfLayer;
  Matrix m_weights;
  Matrix m_biases;
  Matrix m_weightsMomentum;
  Matrix m_biasesMomentum;
  Activation *const m_activation;
};