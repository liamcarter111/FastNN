#include "Matrix.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <numeric>

Matrix::Matrix() : m_iCols(0), m_iRows(0), m_iElements(0){};

Matrix::Matrix(const int &iRows, const int &iCols)
    : m_iCols(iCols), m_iRows(iRows), m_iElements(RowSize() * ColSize()),
      m_data(m_iElements) {}

Matrix::~Matrix() {
  // why?
  int i = 0;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
  Resize(rhs.RowSize(), rhs.ColSize());

  m_data.assign(rhs.m_data.begin(), rhs.m_data.end());

  return *this;
}

Matrix &Matrix::operator-=(const float &rhs) {
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

Matrix &Matrix::operator+=(const float &rhs) {
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

Matrix &Matrix::operator*=(const float &rhs) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) *= rhs;
  }
  return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  assert(ColSize() == rhs.RowSize());

  Matrix result(RowSize(), rhs.ColSize());
  result.Zero();

  for (int j = 0; j < result.ColSize(); ++j) {
    for (int i = 0; i < result.RowSize(); ++i) {
      for (int k = 0; k < ColSize(); ++k) {
        result(i, j) += (*this)(i, k) * rhs(k, j);
      };
    }
  }
  return result;
}

Matrix Matrix::operator-(const float &rhs) const {
  return Matrix(*this) -= rhs;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
  return Matrix(*this) -= rhs;
}

Matrix Matrix::operator+(const float &rhs) const {
  return Matrix(*this) += rhs;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
  return Matrix(*this) += rhs;
}

Matrix Matrix::operator*(const float &rhs) const {
  return Matrix(*this) *= rhs;
}

float &Matrix::operator()(const int &row, const int &col) {
  return m_data.at(col + row * ColSize());
}

const float &Matrix::operator()(const int &row, const int &col) const {
  return m_data.at(col + row * ColSize());
}

float Matrix::Accumulate(const float init) const {
  return std::accumulate(Data().begin(), Data().end(), init);
}

Matrix Matrix::Pow(const int exponent) const {
  Matrix result(RowSize(), ColSize());

  for (int i = 0; i < Size(); i++) {
    result.m_data.at(i) = std::pow(m_data.at(i), exponent);
  }

  return result;
}

Matrix Matrix::Hadamard(const Matrix &rhs) const {
  assert(ColSize() == rhs.ColSize());
  assert(RowSize() == rhs.RowSize());

  Matrix result(RowSize(), ColSize());

  for (int i = 0; i < Size(); i++) {
    result.m_data.at(i) = m_data.at(i) * rhs.m_data.at(i);
  }

  return result;
}

Matrix Matrix::Transpose() const {
  Matrix result(ColSize(), RowSize());

  for (int i = 0; i < ColSize(); i++) {
    for (int j = 0; j < RowSize(); j++) {
      result(i, j) = (*this)(j, i);
    }
  }
  return result;
}

void Matrix::Zero() { Fill(0.0f); }

void Matrix::Fill(const float &v) {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) = v;
  }
}

void Matrix::Randomize() {
  for (int i = 0; i < Size(); i++) {
    m_data.at(i) = (float)rand() / RAND_MAX;
  }
}

void Matrix::Resize(const int &rows, const int &cols) {
  m_iRows = rows;
  m_iCols = cols;
  m_iElements = rows * cols;
  m_data.resize(m_iElements);
}

void Matrix::Print() const {
  for (unsigned i = 0; i < RowSize(); i++) {
    for (unsigned j = 0; j < ColSize(); j++) {
      std::cout << "[" << (*this)(i, j) << "] ";
    }
    std::cout << std::endl;
  }
}