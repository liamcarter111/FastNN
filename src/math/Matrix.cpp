#include "Matrix.h"
#include <cassert>
#include <cstdlib>
#include <cstring>

Matrix::Matrix(const Matrix *other)
    : m_iCols(other->ColSize()), m_iRows(other->RowSize()),
      m_iElements(other->Size()), m_data(new float[Size()]) {

  memcpy(m_data, other->m_data, sizeof(float) * Size());
}

Matrix::Matrix(const Matrix &other)
    : m_iCols(other.ColSize()), m_iRows(other.RowSize()),
      m_iElements(other.Size()), m_data(new float[Size()]) {

  memcpy(m_data, other.m_data, sizeof(float) * Size());
}

Matrix::Matrix(Matrix &&other)
    : m_iCols(other.ColSize()), m_iRows(other.RowSize()),
      m_iElements(other.Size()), m_data(other.Data()) {
  other.m_data = nullptr;
}

Matrix::Matrix(const int &iRows, const int &iCols)
    : m_iCols(iCols), m_iRows(iRows), m_iElements(RowSize() * ColSize()),
      m_data(new float[Size()]) {}

Matrix::~Matrix() {
  delete[] m_data;
  m_data = nullptr;
}

Matrix Matrix::operator*(const float &rhs) const {
  Matrix result(this);
  return Matrix::MUL(result, *this, rhs);
}

Matrix &Matrix::operator*=(const float &rhs) {
  return Matrix::MUL(*this, *this, rhs);
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  Matrix result(RowSize(), rhs.ColSize());
  Matrix::MUL(result, *this, rhs);
  return result;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
  if (this != &rhs) {
    Resize(rhs.RowSize(), rhs.ColSize());
    memcpy(Data(), rhs.Data(), sizeof(float) * Size());
  }
  return (*this);
}

float &Matrix::operator()(const int &row, const int &col) {
  return Data()[col + row * ColSize()];
}

const float &Matrix::operator()(const int &row, const int &col) const {
  return Data()[col + row * ColSize()];
}

void Matrix::Resize(const int &rows, const int &cols) {
  m_iRows = rows;
  m_iCols = cols;
  int iElements = rows * cols;

  if (Size() != iElements) {
    m_iElements = iElements;
    delete[] m_data;
    m_data = new float[Size()];
  }
}

Matrix &Matrix::ADD(Matrix &out, const Matrix &lhs, const Matrix &rhs) {
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = lhs.Data()[i] + rhs.Data()[i];
  }
  return out;
}

Matrix &Matrix::SUB(Matrix &out, const Matrix &lhs, const Matrix &rhs) {
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = lhs.Data()[i] - rhs.Data()[i];
  }
  return out;
}

Matrix &Matrix::HADAMARD(Matrix &out, const Matrix &lhs, const Matrix &rhs) {
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = lhs.Data()[i] * rhs.Data()[i];
  }
  return out;
}

Matrix &Matrix::MUL(Matrix &out, const Matrix &lhs, const float &rhs) {
  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = lhs.Data()[i] * rhs;
  }
  return out;
}

Matrix &Matrix::MUL(Matrix &out, const Matrix &lhs, const Matrix &rhs) {
  for (int j = 0; j < out.ColSize(); ++j) {
    for (int i = 0; i < out.RowSize(); ++i) {
      float dot = 0;
      for (int k = 0; k < out.ColSize(); ++k) {
        dot += lhs(i, k) * rhs(k, j);
      };
      out(i, j) = dot;
    }
  }
  return out;
}

Matrix &Matrix::ZERO(Matrix &out) {
  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = 0.0f;
  }
  return out;
}

Matrix &Matrix::FILL(Matrix &out, float &v) {
  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = v;
  }
  return out;
}

Matrix &Matrix::RANDOM(Matrix &out) {
  for (int i = 0; i < out.Size(); i++) {
    out.Data()[i] = (float)rand() / RAND_MAX;
  }
  return out;
}

Matrix &Matrix::TRANSPOSE(Matrix &out) {
  for (int i = 0; i < out.RowSize(); i++) {
    for (int j = i; j < out.ColSize(); j++) {
      float temp = out(i, j);
      out(i, j) = out(j, i);
      out(j, i) = temp;
    }
  }
  return out;
}