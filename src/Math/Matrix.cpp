#include "Matrix.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>

Matrix::Matrix() : m_iCols(0), m_iRows(0), m_iElements(0){};

Matrix::Matrix(const int &iRows, const int &iCols)
    : m_iCols(iCols), m_iRows(iRows), m_iElements(RowSize() * ColSize()),
      m_data(m_iElements) {}

Matrix &Matrix::operator-=(const double &rhs) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) -= rhs;
  }
  return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
  assert(rhs.ColSize() == ColSize());
  assert(rhs.RowSize() == RowSize());

  for (int i = 0; i < Size(); i++) {
    m_data.at(i) -= rhs.m_data.at(i);
  }
  return *this;
}

Matrix &Matrix::operator+=(const double &rhs) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) += rhs;
  }
  return *this;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
  assert(rhs.ColSize() == ColSize());
  assert(rhs.RowSize() == RowSize());

  for (int i = 0; i < Size(); i++) {
    m_data.at(i) += rhs.m_data.at(i);
  }
  return *this;
}

Matrix &Matrix::operator*=(const double &rhs) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) *= rhs;
  }
  return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  assert(ColSize() == rhs.RowSize());

  Matrix result(RowSize(), rhs.ColSize());

  for (int j = 0; j < result.ColSize(); ++j) {
    for (int i = 0; i < result.RowSize(); ++i) {
      result(i, j) = 0.0f;
      for (int k = 0; k < ColSize(); ++k) {
        result(i, j) += (*this)(i, k) * rhs(k, j);
      };
    }
  }
  return result;
}

Matrix Matrix::operator-() const {
  Matrix result(*this);
  for (int i = 0; i < Size(); i++) {
    result.m_data.at(i) = -result.m_data.at(i);
  }
  return result;
}

Matrix Matrix::operator-(const double &rhs) const {
  return Matrix(*this) -= rhs;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
  return Matrix(*this) -= rhs;
}

Matrix Matrix::operator+(const double &rhs) const {
  return Matrix(*this) += rhs;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
  return Matrix(*this) += rhs;
}

Matrix Matrix::operator*(const double &rhs) const {
  return Matrix(*this) *= rhs;
}

double &Matrix::operator()(const int &row, const int &col) {
  return m_data.at(col + row * ColSize());
}

const double &Matrix::operator()(const int &row, const int &col) const {
  return m_data.at(col + row * ColSize());
}

double Matrix::Accumulate(const double init) const {
  return std::accumulate(Data().begin(), Data().end(), init);
}

Matrix Matrix::Pow(const int exponent) const {
  Matrix result(*this);

  for (int i = 0; i < Size(); i++) {
    result.m_data.at(i) = std::pow(result.m_data.at(i), exponent);
  }

  return result;
}

Matrix Matrix::Hadamard(const Matrix &rhs) const {
  assert(ColSize() == rhs.ColSize());
  assert(RowSize() == rhs.RowSize());

  Matrix result(RowSize(), rhs.ColSize());

  for (int i = 0; i < Size(); i++) {
    result.m_data.at(i) = m_data.at(i) * rhs.m_data.at(i);
  }

  return result;
}

Matrix Matrix::TransposeLHSMultiply(const Matrix &rhs) const {
  assert(RowSize() == rhs.RowSize());

  Matrix result(ColSize(), rhs.ColSize());

  for (int j = 0; j < result.ColSize(); ++j) {
    for (int i = 0; i < result.RowSize(); ++i) {
      result(i, j) = 0.0f;
      for (int k = 0; k < RowSize(); ++k) {
        result(i, j) += (*this)(k, i) * rhs(k, j);
      };
    }
  }
  return result;
}

Matrix Matrix::TransposeRHSMultiply(const Matrix &rhs) const {
  assert(ColSize() == rhs.ColSize());

  Matrix result(RowSize(), rhs.RowSize());

  for (int j = 0; j < result.ColSize(); ++j) {
    for (int i = 0; i < result.RowSize(); ++i) {
      result(i, j) = 0.0f;
      for (int k = 0; k < ColSize(); ++k) {
        result(i, j) += (*this)(i, k) * rhs(j, k);
      };
    }
  }
  return result;
}

Matrix Matrix::Transpose() const {
  if (ColSize() == 1 || RowSize() == 1) {
    Matrix result(*this);
    result.m_iRows = ColSize();
    result.m_iCols = RowSize();
    return result;
  } else {
    Matrix result(ColSize(), RowSize());

    for (int i = 0; i < ColSize(); i++) {
      for (int j = 0; j < RowSize(); j++) {
        result(i, j) = (*this)(j, i);
      }
    }
    return result;
  }
}

void Matrix::Zero() { Fill(0.0); }

void Matrix::Fill(const double &v) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) = v;
  }
}

void Matrix::Randomize() {
  for (int i = 0; i < ColSize(); i++) {
    for (int j = 0; j < RowSize(); j++) {
      (*this)(j, i) = (double)(rand() + 1) / (double)(RAND_MAX + 1) +
                      1.0 / (double)RAND_MAX;
    }
  }
}

void Matrix::Resize(const int &rows, const int &cols) {
  m_iRows = rows;
  m_iCols = cols;
  int newSize = rows * cols;

  if (newSize != m_iElements) {
    m_iElements = newSize;
    m_data.resize(m_iElements);
  }
}

void Matrix::Print(const int precision) const {
  const int precisionScalingFactor = std::pow(10, precision);
  for (unsigned i = 0; i < RowSize(); i++) {
    for (unsigned j = 0; j < ColSize(); j++) {
      std::cout << std::fixed << std::setprecision(precision) << "["
                << std::ceil((*this)(i, j) * precisionScalingFactor) /
                       precisionScalingFactor
                << "] " << std::setprecision(-1) << std::defaultfloat;
    }
    std::cout << std::endl;
  }
}