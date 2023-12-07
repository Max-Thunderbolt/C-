#include "chessboard.h"

#include <iostream>
#include <string>

using namespace std;

Chessboard::Chessboard(Chessboard &obj)
{
    rows = obj.rows;
    columns = obj.columns;
    board = new Chesspiece **[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece *[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = obj.board[i][j];
        }
    }
}

Chessboard::Chessboard(int in_rows, int in_columns)
{
    if (in_rows < 0 || in_columns < 0)
    {
        rows = 0;
        columns = 0;
    }
    else
    {
        this->rows = in_rows;
        this->columns = in_columns;
    }

    board = new Chesspiece **[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece *[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = NULL;
        }
    }
}

Chessboard::~Chessboard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{
    this->board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column)
{
    board[row][column] = NULL;
}

Chesspiece &Chessboard::at(int row, int column) const
{
    return *this->board[row][column];
}

Chessboard &Chessboard::operator=(const Chessboard &other)
{
    if (this != &other)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete board[i][j];
            }
            delete[] board[i];
        }
        delete[] this->board;
        rows = other.rows;
        columns = other.columns;
        board = new Chesspiece **[rows];
        for (int i = 0; i < rows; i++)
        {
            board[i] = new Chesspiece *[columns];
            for (int j = 0; j < columns; j++)
            {
                board[i][j] = other.board[i][j];
            }
        }
    }
    return *this;
}

Chessboard &Chessboard::operator+=(const Chessboard &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete board[i][j];
            }
            delete[] board[i];
        }
        delete[] board;
        rows = rhs.rows;
        columns = rhs.columns;
        board = new Chesspiece **[rows];
        for (int i = 0; i < rows; i++)
        {
            board[i] = new Chesspiece *[columns];
            for (int j = 0; j < columns; j++)
            {
                board[i][j] = rhs.board[i][j];
            }
        }
    }
    return *this;
}
