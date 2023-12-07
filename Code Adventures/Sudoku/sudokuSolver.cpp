#include <vector>
#include <iostream>

#include "isValidSudoku.cpp"


using namespace std;

void allocateGrids(vector<vector<char> > &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Top 3 grid allocation
            if (row < 3)
            {
                if (col < 3)
                {
                    grid1.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 3 && col < 6)
                {
                    grid2.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 6 && col < 9)
                {
                    grid3.push_back(vector<char>(1, board[row][col]));
                }
            }

            // Middle 3 grid allocation
            if (row >= 3 && row < 6)
            {
                if (col < 3)
                {
                    grid4.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 3 && col < 6)
                {
                    grid5.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 6 && col < 9)
                {
                    grid6.push_back(vector<char>(1, board[row][col]));
                }
            }

            // Bottom 3 grid allocation
            if (row >= 6 && row < 9)
            {
                if (col < 3)
                {
                    grid7.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 3 && col < 6)
                {
                    grid8.push_back(vector<char>(1, board[row][col]));
                }
                if (col >= 6 && col < 9)
                {
                    grid9.push_back(vector<char>(1, board[row][col]));
                }
            }
        }
    }
}

bool isValid(vector<vector<char> > &board, int row, int col, char c)
{
    bool isValid = true;
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
        {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
        {
            return false;
        }
    }

    // Check grid
    if (row < 3)
    {
        if (col < 3)
        {
            for (int i = 0; i < grid1.size(); i++)
            {
                if (grid1[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 3 && col < 6)
        {
            for (int i = 0; i < grid2.size(); i++)
            {
                if (grid2[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 6 && col < 9)
        {
            for (int i = 0; i < grid3.size(); i++)
            {
                if (grid3[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
    }

    if (row >= 3 && row < 6)
    {
        if (col < 3)
        {
            for (int i = 0; i < grid4.size(); i++)
            {
                if (grid4[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 3 && col < 6)
        {
            for (int i = 0; i < grid5.size(); i++)
            {
                if (grid5[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 6 && col < 9)
        {
            for (int i = 0; i < grid6.size(); i++)
            {
                if (grid6[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
    }

    if (row >= 6 && row < 9)
    {
        if (col < 3)
        {
            for (int i = 0; i < grid7.size(); i++)
            {
                if (grid7[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 3 && col < 6)
        {
            for (int i = 0; i < grid8.size(); i++)
            {
                if (grid8[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
        if (col >= 6 && col < 9)
        {
            for (int i = 0; i < grid9.size(); i++)
            {
                if (grid9[i][0] == c && isValid != false)
                {
                    isValid = false;
                }
            }
        }
    }
    return isValid;
}

bool solveSudokuHelper(vector<vector<char> > &board, int row, int col)
{
    if (row == 9)
    {
        return true;
    }

    if (col == 9)
    {
        return solveSudokuHelper(board, row + 1, 0);
    }

    if (board[row][col] != '.')
    {
        return solveSudokuHelper(board, row, col + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        char c = i + '0';
        if (isValid(board, row, col, c))
        {
            board[row][col] = c;
            if (solveSudokuHelper(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char> > &board)
{
    allocateGrids(board);
    solveSudokuHelper(board, 0, 0);
}




