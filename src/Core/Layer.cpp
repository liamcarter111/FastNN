#include "Layer.h"

Layer::Layer(const int size) : m_values(1, size) {
  Matrix::FILL(m_values, 0.0f);
}

const Matrix &Layer::GetValues() const { return m_values; }
Matrix &Layer::GetValues() { return m_values; }

const int Layer::GetSize() const { return m_values.RowSize(); }