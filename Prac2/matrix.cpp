//Max van der Walt u21446050
#include <iostream>
#include <cmath>

#include "matrix.h"

using namespace std;
//Do not change the displayMatrix() function
void Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            cout << *matrix[i][j];

            if (j != columns - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

}


Matrix::Matrix(int row, int col)
{
    if (row < 1 || col < 1)
    {
        int x = 1; //Num of arrays
        int y = 3; //Num of rows
        int z = 3; //Num of cols

        //! Setting dimensions for 3x3 matrix.
        this->rows = y;    //Assign rows value of 3
        this->columns = z; //Assign columns value of 3

        matrix = new int **[y];

        //Initialising matrix
        //! just check if "this->rows" & "this->columns" is causing a segmentation fault.
        for (int i = 0; i < y; i++)
        {
            matrix[i] = new int *[z];

            for (int j = 0; j < z; j++)
            {
                matrix[i][j] = new int(1);
            }
        }
    }

    else if (row > 1 || col > 1)
    {
        int x = 1;
        int y = row;
        int z = col;

        //! Setting dimensions for row x col matrix.
        this->rows = y;    //Assign rows value of 3
        this->columns = z; //Assign columns value of 3

        matrix = new int **[y];

        //Initialising matrix
        //! just check if "this->rows" & "this->columns" is causing a segmentation fault.
        for (int i = 0; i < y; i++)
        {
            matrix[i] = new int *[z];

            for (int j = 0; j < z; j++)
            {
                matrix[i][j] = new int(0);
            }
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < this->rows; j++)
        {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::resizeRows(int num_rows)
{

    if (num_rows < 1)
    {
        cout << "Error: cannot have less than 1 row \n";
    }
    else if (num_rows < this->rows)
    {
        int x = 1;
        int y = num_rows;
        int z = this->columns;

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < z; j++)
            {
                if (j > num_rows)
                {
                    delete[] matrix[i][j];
                }
            }
        }
    }
    else if (num_rows > this->rows)
    {
        int x = 1;
        int y = num_rows;
        int z = this->columns;

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (i == y)
                {    
                        matrix[i][j] = new int (0);   
                }
            }
        }
    }
}

void Matrix::resizeColumns(int num_columns)
{
    if (num_columns < 1)
    {
        cout << "Error: cannot have less than 1 column \n";
    }
    else if (num_columns < this->columns)
    {
        int y = this->rows;
        int z = num_columns;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < z; y++)
            {
                    if (j > num_columns)
                    {
                        delete[] matrix[i][j];
                    }
            }
        }
    }
    else if (num_columns > this->columns)
    {
        int y = this->rows;
        int z = num_columns;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < z; y++)
            {
                    if (j == num_columns)
                    {
                        matrix[i][j] = new int(0);
                    }
            }
        }
    }
}

void Matrix::setMatrix()
{
   string input = "";
    cin >> input;

    int numInts = input.length() / 2 + 1;

    int x = 1;
    int y = 0;
    int z = 0;

    for (int i = 0; i < numInts; i++)
    {
        if (i * i == numInts)
        {
            y = sqrt(numInts);
            z = sqrt(numInts);
            int count = 1;

            for (int i = 0; i < x; i++)
            {
                matrix[i] = new int *[y];

                for (int j = 0; j < y; j++)
                {
                    matrix[i][j] = new int[z];
                }
            }

            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < z; j++)
                {
                        matrix[i][j] = new int(count++);
                }
            }
        }
    }
}