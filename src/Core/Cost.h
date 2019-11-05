#pragma once
#include <Matrix.h>

struct Cost {
  virtual void Set(const Matrix &prediction, const Matrix &expected) {
    m_gradients.Resize(prediction.RowSize(), prediction.ColSize());
  }

  const float &GetError() const { return m_error; }

  const Matrix &GetGradients() const { return m_gradients; }

protected:
  float m_error;
  Matrix m_gradients;
};