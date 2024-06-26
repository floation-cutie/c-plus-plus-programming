#ifndef MATRIX
#define MATRIX
#include <iostream>
#include <exception>
#include <iomanip>
// specify exception for big applications
class size_incompatible : public std::exception
{
    const char *what() const noexcept override
    {
        return "matrices size incompatible!";
    }
};

using MatrixPointer = int **;
class Matrix
{
private:
    size_t rows, columns;
    MatrixPointer mPointer;
    // friend are neccessary sometimes
    // 在重载运算符时，有时需要访问类的私有成员以实现运算
    // 对于类中实现的成员运算符重载函数，
    // 第一个操作数（左操作数）必须是类的实例，即隐含的 this 指针。
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator-(const Matrix &lhs, const Matrix &rhs);

public:
    Matrix(size_t r = 1, size_t c = 2);
    // copy constructor is very important
    // default copy just copy the same pointer to the same memory position
    Matrix(const Matrix &other);
    Matrix(Matrix &&other) noexcept;
    // 在析构之前一定要进行判断空间是否已经被释放
    // avoid double free
    ~Matrix();

    void init();
    // to distinguish prvalue and xvalue, do implicitly cast
    // specify one r-reference in the function parameter
    // the r-reference itself is a l-value which is needed to be cast to r-value
    Matrix add(const Matrix &one, const Matrix &two);
    Matrix subtract(const Matrix &one, const Matrix &two);
    // copy assignment and prevent self-assignment
    Matrix &operator=(const Matrix &other);
    // tell the library of the fact that move semantic
    // will not throw any exception
    Matrix &operator=(Matrix &&other) noexcept;
    // Matrix operator+(Matrix &other) const;

    /**
     * if we need to define a begin()
     * we also need to define a iterator template class
     */
};
/**
 *  written as non-member function is better
 *  create a new matrix object
 * */
Matrix operator+(const Matrix &lhs, const Matrix &rhs);
Matrix operator-(const Matrix &lhs, const Matrix &rhs);
std::ostream &operator<<(std::ostream &os, const Matrix &m);
/**
 * There exists some operators can't be overloaded as non-member function
 * v.operator[](0) : ok
 * operator[](v,0) : not ok
 */
#endif