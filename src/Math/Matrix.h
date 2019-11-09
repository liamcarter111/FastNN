#pragma once
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

  Matrix Transpose() const;

  void Zero();

  void Fill(const double &v);

  void Randomize();

  void Resize(const int &rows, const int &cols);

  void Print(const int precision = 3) const;

  template <typename TFunction> Matrix Map(const TFunction &function) const {
    Matrix result(RowSize(), ColSize());

    for (unsigned i = 0; i < Size(); ++i) {
      result.m_data.at(i) = function(m_data.at(i));
    }

    return result;
  }

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const std::vector<double> &Data() const { return m_data; }

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  std::vector<double> m_data;
};