#pragma once

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

  const int &RowSize() const { return m_iRows; }

  const int &ColSize() const { return m_iCols; }

  const int &Size() const { return m_iElements; }

  const float *Data() const { return m_data; }
  float *Data() { return m_data; }

  /*
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {

      if (m.Size() > 0) {
        os << m.Data()[0];
      }

      for (int i = 1; i < m.Size(); i++) {
        os << " " << m.Data()[i];
      }
      return os;
    }
    */

  static Matrix &ADD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &SUB(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &HADAMARD(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const float &rhs);

  static Matrix &MUL(Matrix &out, const Matrix &lhs, const Matrix &rhs);

  static Matrix &ZERO(Matrix &out);

  static Matrix &FILL(Matrix &out, float &v);

  static Matrix &RANDOM(Matrix &out);

  static Matrix &TRANSPOSE(Matrix &out);

private:
  int m_iCols;
  int m_iRows;
  int m_iElements;
  float *m_data;
};