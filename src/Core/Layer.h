#pragma once
#include "Activation.h"
#include <Matrix.h>
#include <vector>

class Layer {
  Matrix m_values;

public:
  Layer(const int size);

  const Matrix &GetValues() const;
  Matrix &GetValues();

  const int GetSize() const;
};