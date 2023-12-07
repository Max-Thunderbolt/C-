#include "matrix.h"

#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

Matrix::Matrix(unsigned rows, unsigned cols)
{
    this->rows = rows;
    this->cols = cols;

    this->matrix = new double *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->matrix[i] = new double[this->cols];
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &rhs)
{
    this->rows = rhs.rows;
    this->cols = rhs.cols;

    this->matrix = new double *[this->rows];

    for (int i = 0; i < this->rows; i++)
    {
        this->matrix[i] = new double[this->cols];
    }

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::readFile(istream &infile)
{
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            infile >> matrix[i][j];
        }
    }
}

void Matrix::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(10) << setprecision(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double &Matrix::operator()(unsigned r, unsigned c)
{

    if (r > rows)
    {
        throw "Error: invalid row index";
    }
    else if (c > cols)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return matrix[r][c];
    }
}

const double &Matrix::operator()(const unsigned r, const unsigned c) const
{
    if (r > rows)
    {
        throw "Error: invalid row index";
    }
    else if (c > cols)
    {
        throw "Error: invalid column index";
    }
    else
    {
        return matrix[r][c];
    }
}

Vector Matrix::operator[](const unsigned r) const
{
    Vector ret(cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ret[i] = matrix[r][j];
        }
    }
    return ret;
}

unsigned Matrix::getRows() const
{
    return rows;
}

unsigned Matrix::getCols() const
{
    return cols;
}

const Matrix &Matrix::operator=(const Matrix &rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }

    return *this;
}

//////////////////
//// TASK 2 /////
////////////////

Matrix Matrix::operator*(const double &rhs)
{
    Matrix *m2 = new Matrix(*this);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            m2->matrix[i][j] *= rhs;
        }
    }

    return *m2;
}

Matrix Matrix::operator*(const Matrix &rhs)
{
    if (cols != rhs.rows)
    {
        throw "Error: invalid matrix dimensions";
    }
    else
    {
        int tempCols = 0;
        int product = 0;

        Matrix *temp = new Matrix(rows, rhs.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    for (int l = 0; l < cols; l++)
                    {
                        product += matrix[k][l] * rhs.matrix[l][k];
                    }
                }
                temp->matrix[i][j] = product;
                product = 0;
            }
        }
        return *temp;
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
    if (cols != rhs.rows)
    {
        throw "Error: invalid matrix dimensions";
    }
    else
    {
        int tempCols = 0;
        int product = 0;

        Matrix *temp = new Matrix(rows, rhs.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                for (int k = 0; k < this->rows; k++)
                {
                    for (int l = 0; l < this->cols; l++)
                    {
                        product += this->matrix[k][l] * rhs.matrix[l][k];
                    }
                }
                temp->matrix[i][j] = product;
                product = 0;
            }
        }
        return *temp;
    }
    return *this;
}

Matrix &Matrix::operator*=(const double &rhs)
{

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this->matrix[i][j] = this->matrix[i][j] * rhs;
        }
    }

    return *this;
}

Matrix Matrix::operator/(const double &rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {

        Matrix *m2 = new Matrix(*this);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                m2->matrix[i][j] /= rhs;
            }
        }

        return *m2;
    }
}

Matrix Matrix::operator+(const Matrix &rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        int tempCols = 0;
        int product = 0;

        Matrix *temp = new Matrix(rows, rhs.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                for (int k = 0; k < this->rows; k++)
                {
                    for (int l = 0; l < this->cols; l++)
                    {
                        product += this->matrix[k][l] + rhs.matrix[l][k];
                    }
                }
                temp->matrix[i][j] = product;
                product = 0;
            }
        }
        return *temp;
    }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        int tempCols = 0;
        int product = 0;

        Matrix *temp = new Matrix(rows, rhs.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                for (int k = 0; k < this->rows; k++)
                {
                    for (int l = 0; l < this->cols; l++)
                    {
                        product += this->matrix[k][l] + rhs.matrix[l][k];
                    }
                }
                temp->matrix[i][j] = product;
                product = 0;
            }
        }
        return *temp;
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix &rhs)
{
    if (rows != rhs.rows || cols != rhs.cols)
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] -= rhs.matrix[i][j];
            }
        }
    }
}

Matrix &Matrix::operator-=(const Matrix &rhs)
{
    if (this->rows != rhs.rows || this->cols != rhs.cols)
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] -= rhs.matrix[i][j];
            }
        }
    }

    return *this;
}

Matrix Matrix::operator^(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else if (pow == 0) // if power 0, return identity matrix
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                if (i == j)
                {
                    this->matrix[i][j] = 1;
                }
                else
                {
                    this->matrix[i][j] = 0;
                }
            }
        }
    }
    else if (pow == 1)
    {
        // do nothing
    }
    else if (pow > 0)
    {
        for (int i = 0; i < pow; i++) // see how many times we have to mult. matrix by itself
        {
            for (int j = 0; j < this->rows; j++)
            {
                for (int k = 0; k < this->cols; k++)
                {
                    // matrix[j][k] = (matrix[j][k] * matrix[j][k]) + (matrix[j][k+1] * matrix[j+1][k]);
                    this->matrix[j][k] *= this->matrix[j][k];
                }
            }
        }
    }
}

Matrix &Matrix::operator^=(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }
    else if (pow == 0)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    else if (pow == 1)
    {
        // do nothing
    }
    else if (pow > 0)
    {
        for (int i = 0; i < pow; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    matrix[j][k] *= matrix[j][k];
                }
            }
        }
    }

    return *this;
}

Matrix Matrix::operator~()
{
    int n = rows;
    int m = cols;

    // need to convert matrix from n x m to m x n
    double **tempMatrix = new double *[m];
    for (int i = 0; i < m; i++)
    {
        tempMatrix[i] = new double[n];
    }

    // created temp Matrix to store transpose of original matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tempMatrix[i][j] = matrix[j][i];
        }
    }

    // changing dimensions of original matrix
    matrix = new double *[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new double[n];
    }

    // now need to copy tempMatrix into matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

//////////////////
//// TASK 3 /////
////////////////

Matrix Matrix::operator|(const Matrix &rhs)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if (rhs.rows != rows || rhs.cols != 1)
    {
        throw "Error: incorrect augmentation";
    }

    // Matrix *augmentedMatrix = new Matrix(rhs.rows, rhs.cols);

    // int mult = 0;

    // for (int i = 0; i < rhs.rows - 1; i++)
    // {
    //     for (int j = 0; j <rhs.rows; j++)
    //     {
    //         mult = rhs.matrix[j][i] / rhs.matrix[i][i];

    //         for (int k = 0; k < rows; k++)
    //         {
    //             augmentedMatrix->matrix[j][k] = rhs.matrix[j][k] - (mult * rhs.matrix[i][k]);
    //         }

    //         augmentedMatrix[j] = augmentedMatrix[j] - (mult * augmentedMatrix[i]);
    //     }
    // }

    // Matrix *temp = new Matrix(*augmentedMatrix);

    // for (int i = rows - 2; i < rows; i--)
    // {
    //     for (int j = i + 1; j < rows; j++)
    //     {
    //         temp->matrix[i][i] = temp->matrix[i][i] - (rhs.matrix[i][j] * temp->matrix[j][j]);
    //     }
    //     temp->matrix[i][i] = temp->matrix[i][i] / rhs.matrix[i][i];
    // }

    // return *temp;
}

Matrix &Matrix::operator|=(Matrix &rhs)
{
    if (rows != cols)
    {
        cout << "Error: non-square matrix provided" << endl;
    }
    else if (rhs.rows != rows || rhs.cols != 1)
    {
        cout << "Error: incorrect augmentation" << endl;
    }

    // int mult = 0;

    // for (int i = 0; i < rhs.rows - 1; i++)
    // {
    //     for (int j = 0; j <rhs.rows; j++)
    //     {
    //         mult = rhs.matrix[j][i] / rhs.matrix[i][i];

    //         for (int k = 0; k < rows; k++)
    //         {
    //             rhs.matrix[j][k] = rhs.matrix[j][k] - (mult * rhs.matrix[i][k]);
    //         }

    //         matrix[j][j] = matrix[j][j] - (mult * matrix[i][j]);
    //     }
    // }

    // return *this;
}