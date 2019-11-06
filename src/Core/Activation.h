#pragma once
#include <Matrix.h>

struct Activation {

  virtual void Set(const Matrix &weightedInputs) {}

  const Matrix &GetActivations() const { return m_activations; }

  const Matrix &GetDerivatives() const { return m_derivatives; }

protected:
  Matrix m_activations;
  Matrix m_derivatives;
};