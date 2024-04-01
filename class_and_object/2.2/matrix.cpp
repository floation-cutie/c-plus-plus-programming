#include "matrix.hpp"

Matrix::Matrix(int r, int c) : rows(r), columns(c)
{
    if (rows <= 0 || columns <= 0)
    {
        mPointer = nullptr;
        return;
    }
    mPointer = new int *[r];
    for (size_t i = 0; i < r; i++)
        mPointer[i] = new int[c];
}

Matrix::Matrix(const Matrix &other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    if (other.rows <= 0 || other.columns <= 0)
    {
        this->mPointer = nullptr;
        return;
    }
    mPointer = new int *[rows];
    for (size_t i = 0; i < rows; i++)
        mPointer[i] = new int[columns];
    std::copy(other.mPointer,
              other.mPointer + (other.columns * other.rows),
              mPointer);
}
/*
one slight good version of copy assignment
Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        MatrixPointer temp = new int *[rows];
        for (size_t i = 0; i < rows; i++)
            temp[i] = new int[columns];
        rows = other.rows;
        columns = other.columns;
        delete[] this->mPointer;
        mPointer = temp;
        std::copy(other.mPointer,
                  other.mPointer + (other.columns * other.rows),
                  mPointer);
    }
    return *this;
}
*/
Matrix &Matrix::operator=(const Matrix &other)
{
    Matrix temp(other);
    // can swap order
    // they are more exception safe
    std::swap(this->columns, temp.columns);
    std::swap(this->rows, temp.rows);
    std::swap(this->mPointer, temp.mPointer);
    return *this;
}

// why this move function exist?
// In the function body,
// assignment operator will also create copy for big objects
Matrix::Matrix(Matrix &&other) noexcept : columns(std::move(other.columns)),
                                          rows(std::move(other.rows)),
                                          mPointer(std::move(other.mPointer))
{
    std::cout << __FUNCTION__ << " said Hello from the move constructor!" << std::endl;
    other.mPointer = nullptr;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept
{
    std::cout << __FUNCTION__ << " said Hello from the move assignment!" << std::endl;
    if (this != &other)
    {
        delete[] mPointer;
        columns = std::move(other.columns);
        rows = std::move(other.rows);
        mPointer = std::move(other.mPointer);
        other.mPointer = nullptr;
    }
    return *this;
}

Matrix::~Matrix()
{
    if (mPointer)
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] mPointer[i];
        }
        delete[] mPointer;
    }
}

void Matrix::init()
{
    std::cout << "Please fill the matrix entries with your input." << std::endl;
    std::cout << "The default row is 4, and the default column is 5." << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cin >> mPointer[i][j];
        }
    }
}

Matrix Matrix::add(const Matrix &one, const Matrix &two)
{
    if (one.columns != two.columns || one.rows != two.rows)
        throw size_incompatible();
    Matrix result(one.rows, one.columns);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            result.mPointer[i][j] = one.mPointer[i][j] + two.mPointer[i][j];
    return result;
}

Matrix Matrix::subtract(const Matrix &one, const Matrix &two)
{
    if (one.columns != two.columns || one.rows != two.rows)
        throw size_incompatible();
    Matrix result(one.rows, one.columns);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            result.mPointer[i][j] = one.mPointer[i][j] - two.mPointer[i][j];
    return result;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    os << "Here is the matrix looks like. " << std::endl;
    for (size_t i = 0; i < m.rows; i++)
    {
        for (size_t j = 0; j < m.columns - 1; j++)
            os << std::setw(3) << m.mPointer[i][j] << ' ';
        os << std::setw(3) << m.mPointer[i][m.columns - 1] << std::endl;
    }
    os << std::endl;
    return os;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.columns != rhs.columns || lhs.rows != rhs.rows)
        throw size_incompatible();
    Matrix result(lhs.rows, lhs.columns);
    for (size_t i = 0; i < result.rows; i++)
        for (size_t j = 0; j < result.columns; j++)
            result.mPointer[i][j] = lhs.mPointer[i][j] + rhs.mPointer[i][j];
    return result;
}

Matrix operator-(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.columns != rhs.columns || lhs.rows != rhs.rows)
        throw size_incompatible();
    Matrix result(lhs.rows, lhs.columns);
    for (size_t i = 0; i < result.rows; i++)
        for (size_t j = 0; j < result.columns; j++)
            result.mPointer[i][j] = lhs.mPointer[i][j] - rhs.mPointer[i][j];
    return result;
}