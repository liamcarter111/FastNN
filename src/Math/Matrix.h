#pragma once
#include <cassert>
#include <vector>

struct Matrix {
  Matrix();

  Matrix(const int &iCols, const int &iRows);

  Matrix operator-() const;

  Matrix operator-(const double &rhs) const;

  Matrix &operator-=(const double &rhs);

  Matrix &operator-=(const Matrix &rhs);

  Matrix operator-(const Matrix &rhs) const;

  Matrix operator+(const double &rhs) const;

  Matrix &operator+=(const double &rhs);

  Matrix &operator+=(const Matrix &rhs);

  Matrix operator+(const Matrix &rhs) const;

  Matrix operator*(const double &rhs) const;

  Matrix &operator*=(const double &rhs);

  Matrix operator*(const Matrix &rhs) const;

  double &operator()(const int &row, const int &col);

  const double &operator()(const int &row, const int &col) const;

  double Accumulate(const double init = 0.0f) const;

  Matrix Pow(const int exponent) const;

  Matrix Hadamard(const Matrix &rhs) const;

  Matrix TransposeLHSMultiply(const Matrix &rhs) const;

  Matrix TransposeRHSMultiply(const Matrix &rhs) const;

  Matrix Transpose() const;

  void Zero();

  void Fill(const double &v);

  void Randomize();

  void Resize(const int &rows, const int &cols);

  void Print(const int precision = 3) const;

  template <typename TFunction> Matrix Map(const TFunction &function) const {
    return MAP(*this, function, Matrix(RowSize(), ColSize()));
  }

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const std::vector<double> &Data() const { return m_data; }

  static Matrix &&HAD(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &HAD(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&SUB(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &SUB(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&SUB(const Matrix &lhs, const float rhs, Matrix &&out);

  static Matrix &SUB(const Matrix &lhs, const float rhs, Matrix &out);

  static Matrix &&ADD(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &ADD(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&ADD(const Matrix &lhs, const float rhs, Matrix &&out);

  static Matrix &ADD(const Matrix &lhs, const float rhs, Matrix &out);

  static Matrix &&MUL(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &MUL(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&MUL_RHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &MUL_RHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&MUL_LHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &&out);

  static Matrix &MUL_LHS_T(const Matrix &lhs, const Matrix &rhs, Matrix &out);

  static Matrix &&MUL(const Matrix &lhs, const float rhs, Matrix &&out);

  static Matrix &MUL(const Matrix &lhs, const float rhs, Matrix &out);

  static Matrix &&POW(const Matrix &lhs, const int exponent, Matrix &&out);

  static Matrix &POW(const Matrix &lhs, const int exponent, Matrix &out);

  template <typename TFunction>
  static Matrix &&MAP(const Matrix &lhs, const TFunction &function,
                      Matrix &&out) {
    return std::move(MAP(lhs, function, out));
  }

  template <typename TFunction>
  static Matrix &MAP(const Matrix &lhs, const TFunction &function,
                     Matrix &out) {
    assert(rhs.RowSize() == out.ColSize());
    assert(lhs.RowSize() == out.RowSize());

    for (int i = 0; i < lhs.Size(); ++i) {
      out.m_data.at(i) = function(lhs.m_data.at(i));
    }
    return out;
  }

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  std::vector<double> m_data;
};