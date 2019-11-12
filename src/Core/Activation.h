#pragma once
#include <Matrix.h>

struct Activation {

  void Init(const int currentLayerSize) {
    m_activations.Resize(currentLayerSize, 1);
    m_derivatives.Resize(currentLayerSize, 1);
  }

  virtual void Set(const Matrix &weightedInputs) {}

  const Matrix &GetActivations() const { return m_activations; }

  const Matrix &GetDerivatives() const { return m_derivatives; }

protected:
  Matrix m_activations;
  Matrix m_derivatives;
};