#pragma once
#include "Activation.h"
#include <Matrix.h>
#include <vector>

struct Layer final {
  Layer(const int sizeOfLayer, Activation *const activation);

  const Matrix &GetOutput() const;

  void ForwardProp(const Matrix &pLActivations);
  void BackwardProp(const Matrix &pLActivations, Matrix &error,
                    const double learningRate, const double momentumRate);

  void Print() const;

  void Init(const int previousLayerSize);

  void Init(const int previousLayerSize, const Matrix &weights,
            const Matrix &biases);

  const int &GetSize() const;

private:
  const int m_sizeOfLayer;
  Matrix m_weights;
  Matrix m_biases;
  Matrix m_weightsMomentum;
  Matrix m_biasesMomentum;
  Activation *const m_activation;
};