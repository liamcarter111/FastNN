#pragma once
#include <functional>

struct Matrix {
  Matrix(const Matrix *other);

  Matrix(const Matrix &other);

  Matrix(Matrix &&other);

  Matrix(const int &iCols, const int &iRows);

  ~Matrix();

  Matrix operator*(const float &rhs) const;

  Matrix &operator*=(const float &rhs);

  Matrix operator*(const Matrix &rhs) const;

  Matrix &operator=(const Matrix &rhs);

  float &operator()(const int &row, const int &col);

  const float &operator()(const int &row, const int &col) const;

  void Resize(const int &rows, const int &cols);

  template <class TReturn>
  TReturn Map(const std::function<TReturn(const float * /* begin */,
                                          const float * /* end */)> &fn) const {
    return fn(Data(), Data() + Size());
  }

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const float *Data() const { return m_data; }
  float *Data() { return m_data; }

  static Matrix &ADD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &SUB(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &HADAMARD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const float &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &ZERO(Matrix &out);

  static Matrix &FILL(Matrix &out, const float &v);

  static Matrix &RANDOM(Matrix &out);

  static Matrix &TRANSPOSE(Matrix &out);

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  float *m_data;
};