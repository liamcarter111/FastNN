#pragma once
#include <Matrix.h>

struct Cost {
  virtual void Set(const Matrix &prediction, const Matrix &expected) {}

  const double &GetError() const { return m_error; }

  const Matrix &GetGradients() const { return m_gradients; }

protected:
  double m_error;
  Matrix m_gradients;
};