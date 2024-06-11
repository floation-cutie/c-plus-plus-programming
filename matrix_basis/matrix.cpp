#include <iostream>
#include <iomanip>
using namespace std;
using MatrixPointer = int **;

void createMatrix(MatrixPointer &, size_t row = 4, size_t col = 5);
void initMatrix(const MatrixPointer &, size_t row = 4, size_t col = 5);
void printMatrix(const MatrixPointer &, size_t row = 4, size_t col = 5);
void matrixAddition(const MatrixPointer &, const MatrixPointer &, const MatrixPointer &, size_t row = 4, size_t col = 5);
void matrixSubtraction(const MatrixPointer &, const MatrixPointer &, const MatrixPointer &, size_t row = 4, size_t col = 5);
void freeMatrixSpace(MatrixPointer &, size_t row = 4);

/**
 * use the following command to run the program
 *Get-Content .\testmatrix.txt | .\matrix.exe
 */

int main(int argc, char const *argv[])
{
    MatrixPointer A1, A2, A3;

    // 动态申请矩阵空间
    createMatrix(A1);
    createMatrix(A2);
    createMatrix(A3);

    // 初始化矩阵内容
    initMatrix(A1);
    initMatrix(A2);

    // 进行矩阵加法，将结果存储在A3矩阵中
    matrixAddition(A1, A2, A3);
    // 打印格式化结果
    printMatrix(A3);

    // 进行矩阵减法，将结果存储在A3矩阵中
    matrixSubtraction(A1, A2, A3);
    // 打印格式化结果
    printMatrix(A3);

    // 释放矩阵空间
    freeMatrixSpace(A1);
    freeMatrixSpace(A2);
    freeMatrixSpace(A3);

    cout << "The whole matrix space has been freed. " << endl;
    cout << endl;
    return 0;
}

void createMatrix(MatrixPointer &mPointer, size_t row, size_t col)
{
    mPointer = new int *[row];
    for (size_t i = 0; i < col; i++)
        mPointer[i] = new int[col];
}

void initMatrix(const MatrixPointer &mPointer, size_t row, size_t col)
{
    cout << "Please fill the matrix entries with your input." << endl;
    cout << "The default row is 4, and the default column is 5." << endl;
    cout << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> mPointer[i][j];
        }
    }
}

/**
 * 格式化输出矩阵内容
 * 可以影响常量指针背后的值
 */
void printMatrix(const MatrixPointer &mPointer, size_t row, size_t col)
{
    cout << "Here is the matrix looks like. " << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col - 1; j++)
            cout << setw(3) << mPointer[i][j] << ' ';
        cout << setw(3) << mPointer[i][col - 1] << endl;
    }
    cout << endl;
}

void matrixAddition(const MatrixPointer &mPointerA, const MatrixPointer &mPointerB, const MatrixPointer &mPointerC, size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            mPointerC[i][j] = mPointerA[i][j] + mPointerB[i][j];
        }
    }
}

void matrixSubtraction(const MatrixPointer &mPointerA, const MatrixPointer &mPointerB, const MatrixPointer &mPointerC, size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            mPointerC[i][j] = mPointerA[i][j] - mPointerB[i][j];
        }
    }
}

void freeMatrixSpace(MatrixPointer &mPointer, size_t row)
{
    for (size_t i = 0; i < row; i++)
        delete[] mPointer[i];
    delete[] mPointer;
}