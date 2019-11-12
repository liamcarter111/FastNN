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

Matrix &Matrix::operator-=(const double &rhs) { return SUB(*this, rhs, *this); }

Matrix &Matrix::operator-=(const Matrix &rhs) { return SUB(*this, rhs, *this); }

Matrix &Matrix::operator+=(const double &rhs) { return ADD(*this, rhs, *this); }

Matrix &Matrix::operator+=(const Matrix &rhs) { return ADD(*this, rhs, *this); }

Matrix &Matrix::operator*=(const double &rhs) { return MUL(*this, rhs, *this); }

Matrix Matrix::operator*(const Matrix &rhs) const {
  return MUL(*this, rhs, Matrix(RowSize(), rhs.ColSize()));
}

Matrix Matrix::operator-() const {
  return MAP(
      *this, [](const double &val) { return -val; },
      Matrix(RowSize(), ColSize()));
}

Matrix Matrix::operator-(const double &rhs) const {
  return SUB(*this, rhs, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::operator-(const Matrix &rhs) const {
  return SUB(*this, rhs, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::operator+(const double &rhs) const {
  return ADD(*this, rhs, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::operator+(const Matrix &rhs) const {
  return ADD(*this, rhs, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::operator*(const double &rhs) const {
  return MUL(*this, rhs, Matrix(RowSize(), ColSize()));
}

double &Matrix::operator()(const int &row, const int &col) {
  assert(row > -1);
  assert(col > -1);
  assert(row < RowSize());
  assert(col < ColSize());

  return m_data.at(col + row * ColSize());
}

const double &Matrix::operator()(const int &row, const int &col) const {
  assert(row > -1);
  assert(col > -1);
  assert(row < RowSize());
  assert(col < ColSize());

  return m_data.at(col + row * ColSize());
}

double Matrix::Accumulate(const double init) const {
  return std::accumulate(Data().begin(), Data().end(), init);
}

Matrix Matrix::Pow(const int exponent) const {
  return POW(*this, exponent, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::Hadamard(const Matrix &rhs) const {
  return HAD(*this, rhs, Matrix(RowSize(), ColSize()));
}

Matrix Matrix::TransposeLHSMultiply(const Matrix &rhs) const {
  return MUL_LHS_T(*this, rhs, Matrix(ColSize(), rhs.ColSize()));
}

Matrix Matrix::TransposeRHSMultiply(const Matrix &rhs) const {
  return MUL_RHS_T(*this, rhs, Matrix(RowSize(), rhs.RowSize()));
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

void Matrix::Zero() {
  MAP(
      *this, [](const double &val) { return 0; }, *this);
}

void Matrix::Fill(const double &v) {
  MAP(
      *this, [&v](const double &val) { return v; }, *this);
}

void Matrix::Randomize() {
  MAP(
      *this,
      [](const double &val) {
        return (double)(rand() + 1) / (double)(RAND_MAX + 1) +
               1.0 / (double)RAND_MAX;
      },
      *this);
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
  const int precisionScalingFactor = (int)std::pow(10, precision);
  for (int i = 0; i < RowSize(); i++) {
    for (int j = 0; j < ColSize(); j++) {
      std::cout << std::fixed << std::setprecision(precision) << "["
                << std::ceil((*this)(i, j) * precisionScalingFactor) /
                       precisionScalingFactor
                << "] " << std::setprecision(-1) << std::defaultfloat;
    }
    std::cout << std::endl;
  }
}

Matrix &&Matrix::HAD(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(HAD(lhs, rhs, out));
}

Matrix &Matrix::HAD(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) * rhs.m_data.at(i);
  }

  return out;
}

Matrix &&Matrix::SUB(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(SUB(lhs, rhs, out));
}

Matrix &Matrix::SUB(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) - rhs.m_data.at(i);
  }

  return out;
}

Matrix &&Matrix::SUB(const Matrix &lhs, const float rhs, Matrix &&out) {
  return std::move(SUB(lhs, rhs, out));
}

Matrix &Matrix::SUB(const Matrix &lhs, const float rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) - rhs;
  }

  return out;
}

Matrix &&Matrix::ADD(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(ADD(lhs, rhs, out));
}

Matrix &Matrix::ADD(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());
  assert(rhs.ColSize() == out.ColSize());
  assert(rhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) + rhs.m_data.at(i);
  }

  return out;
}

Matrix &&Matrix::ADD(const Matrix &lhs, const float rhs, Matrix &&out) {
  return std::move(ADD(lhs, rhs, out));
}

Matrix &Matrix::ADD(const Matrix &lhs, const float rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) + rhs;
  }

  return out;
}

Matrix &&Matrix::MUL(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(MUL(lhs, rhs, out));
}

Matrix &Matrix::MUL(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(&lhs != &out);
  assert(&rhs != &out);

  assert(lhs.ColSize() == rhs.RowSize());
  assert(rhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int j = 0; j < out.ColSize(); ++j) {
    for (int i = 0; i < out.RowSize(); ++i) {
      out(i, j) = 0.0f;
      for (int k = 0; k < lhs.ColSize(); ++k) {
        out(i, j) += lhs(i, k) * rhs(k, j);
      };
    }
  }
  return out;
}

Matrix &&Matrix::MUL_LHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(MUL_LHS_T(lhs, rhs, out));
}

Matrix &Matrix::MUL_LHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(&lhs != &out);
  assert(&rhs != &out);

  assert(lhs.RowSize() == rhs.RowSize());
  assert(rhs.ColSize() == out.ColSize());
  assert(lhs.ColSize() == out.RowSize());

  for (int j = 0; j < out.ColSize(); ++j) {
    for (int i = 0; i < out.RowSize(); ++i) {
      out(i, j) = 0.0f;
      for (int k = 0; k < lhs.RowSize(); ++k) {
        out(i, j) += lhs(k, i) * rhs(k, j);
      };
    }
  }
  return out;
}

Matrix &&Matrix::MUL_RHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &&out) {
  return std::move(MUL_RHS_T(lhs, rhs, out));
}

Matrix &Matrix::MUL_RHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &out) {
  assert(&lhs != &out);
  assert(&rhs != &out);

  assert(lhs.ColSize() == rhs.ColSize());
  assert(rhs.RowSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int j = 0; j < out.ColSize(); ++j) {
    for (int i = 0; i < out.RowSize(); ++i) {
      out(i, j) = 0.0f;
      for (int k = 0; k < lhs.ColSize(); ++k) {
        out(i, j) += lhs(i, k) * rhs(j, k);
      };
    }
  }
  return out;
}

Matrix &&Matrix::MUL(const Matrix &lhs, const float rhs, Matrix &&out) {
  return std::move(MUL(lhs, rhs, out));
}

Matrix &Matrix::MUL(const Matrix &lhs, const float rhs, Matrix &out) {
  assert(lhs.ColSize() == out.ColSize());
  assert(lhs.RowSize() == out.RowSize());

  for (int i = 0; i < out.Size(); i++) {
    out.m_data.at(i) = lhs.m_data.at(i) * rhs;
  }

  return out;
}

Matrix &&Matrix::POW(const Matrix &lhs, const int exponent, Matrix &&out) {
  return std::move(POW(lhs, exponent, out));
}

Matrix &Matrix::POW(const Matrix &lhs, const int exponent, Matrix &out) {
  return MAP(
      lhs, [&exponent](const double &val) { return std::pow(val, exponent); },
      out);
}