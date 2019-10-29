#pragma once

struct Matrix {
  Matrix(const Matrix *other);

  Matrix(const Matrix &other);

  Matrix(Matrix &&other);

  Matrix(const int &iCols, const int &iRows);

  ~Matrix();

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

  Matrix &operator*=(const Matrix &rhs);

  Matrix operator*(const Matrix &rhs) const;

  Matrix &operator=(const Matrix &rhs);

  float &operator()(const int &row, const int &col);

  const float &operator()(const int &row, const int &col) const;

  Matrix Hadamard(const Matrix &rhs) const;

  Matrix Transpose() const;

  void Zero();

  void Fill(const float &v);

  void Randomize();

  void Resize(const int &rows, const int &cols);

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const float *Data() const { return m_data; }
  float *Data() { return m_data; }

  static Matrix &ADD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &ADD(Matrix &out, const Matrix &lhs, const float &rhs);

  static Matrix &SUB(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &SUB(Matrix &out, const Matrix &lhs, const float &rhs);

  static Matrix &HADAMARD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const float &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &TRANSPOSE(Matrix &out, const Matrix &rhs);

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  float *m_data;
};