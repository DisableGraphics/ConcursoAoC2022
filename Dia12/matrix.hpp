#pragma once
#include <ostream>
class Matrix 
{
    public:
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);
        Matrix(int raw[9][9]);
        ~Matrix();
        Matrix& operator=(const Matrix& other);
        int getRows() const;
        int getCols() const;
        int& operator()(int row, int col);
        int operator()(int row, int col) const;
        Matrix power(int n);
        friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
        
    private:
        int rows;
        int cols;
        int* data;
};
inline Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data = new int[rows * cols];
}
inline Matrix::Matrix(const Matrix& other)
{
    this->rows = other.rows;
    this->cols = other.cols;
    this->data = new int[rows * cols];
    for(int i{0}; i < rows * cols; i++)
    {
        this->data[i] = other.data[i];
    }
}
inline Matrix::Matrix(int raw[9][9])
{
    this->rows = 9;
    this->cols = 9;
    this->data = new int[rows * cols];
    for(int i{0}; i < rows * cols; i++)
    {
        this->data[i] = raw[i / cols][i % cols];
    }
}

inline Matrix::~Matrix()
{
    delete[] data;
}
inline Matrix& Matrix::operator=(const Matrix& other)
{
    if(this != &other)
    {
        delete[] data;
        this->rows = other.rows;
        this->cols = other.cols;
        this->data = new int[rows * cols];
        for(int i{0}; i < rows * cols; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    return *this;
}
inline int Matrix::getRows() const
{
    return rows;
}
inline int Matrix::getCols() const
{
    return cols;
}
inline int& Matrix::operator()(int row, int col)
{
    return data[row * cols + col];
}
inline int Matrix::operator()(int row, int col) const
{
    return data[row * cols + col];
}
inline Matrix Matrix::power(int n)
{
    Matrix result(rows, cols);
    for(int i{0}; i < rows; i++)
    {
        for(int j{0}; j < cols; j++)
        {
            result(i, j) = 0;
            for(int k{0}; k < cols; k++)
            {
                result(i, j) += (*this)(i, k) * (*this)(k, j);
            }
        }
    }
    return result;
}
inline std::ostream& operator<<(std::ostream& out, const Matrix &m)
{
    for(int i{0}; i < m.rows; i++)
    {
        for(int j{0}; j < m.cols; j++)
        {
            out << m.data[i * m.cols + j] <<  " ";
        }
        out << std::endl;
    }
    return out;
}