#pragma once
#include <Matrix.h>

struct Activation {

  void Set(const Matrix &weightedInputs) {}

  const Matrix &GetActivations() const { return m_activations; }

  const Matrix &GetGradients() const { return m_gradients; }

protected:
  Matrix m_activations;
  Matrix m_gradients;
};