#pragma once
#include <vector>

struct Matrix {
  Matrix();

  Matrix(const int &iCols, const int &iRows);

  Matrix &operator=(const Matrix &rhs);

  Matrix operator-() const;

  Matrix operator-(const float &rhs) const;

  Matrix &operator-=(const float &rhs);

  Matrix &operator-=(const Matrix &rhs);

  Matrix operator-(const Matrix &rhs) const;

  Matrix operator+(const float &rhs) const;

  Matrix &operator+=(const float &rhs);

  Matrix &operator+=(const Matrix &rhs);

  Matrix operator+(const Matrix &rhs) const;

  Matrix operator*(const float &rhs) const;

  Matrix &operator*=(const float &rhs);

  Matrix operator*(const Matrix &rhs) const;

  float &operator()(const int &row, const int &col);

  const float &operator()(const int &row, const int &col) const;

  float Accumulate(const float init = 0.0f) const;

  Matrix Pow(const int exponent) const;

  Matrix Hadamard(const Matrix &rhs) const;

  Matrix Transpose() const;

  void Zero();

  void Fill(const float &v);

  void Randomize();

  void Resize(const int &rows, const int &cols);

  void Print() const;

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const std::vector<float> &Data() const { return m_data; }

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  std::vector<float> m_data;
};