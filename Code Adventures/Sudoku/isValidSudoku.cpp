#include <vector>
#include <iostream>

#include "createGame.cpp"

using namespace std;

// Create the 9 grids in the game.

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

bool isValidGrid(vector<vector<char> > &grid)
{
    char blank = '.';
    vector<char> gridNums;
    bool isValid = true;

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            if (grid[row][col] != blank)
            {
                gridNums.push_back(grid[row][col]);
            }
        }
    }

    sort(gridNums.begin(), gridNums.end());

    for (int i = 0; i < gridNums.size(); i++)
    {
        for (int j = i + 1; j < gridNums.size(); j++)
        {
            cout << gridNums[i] << " " << gridNums[j] << endl;
            if (gridNums[i] == gridNums[j])
            {
                isValid = false;
            }
            else if (isValid != false)
            {
                isValid = true;
            }
        }
    }
    return isValid;
}

bool validateBoard(vector<vector<char> > &board)
{
    char blank = '.';
    bool isValid = true;
    vector<char> rowNums, colNums;

    // Check rows
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board[row].size(); col++)
        {
            if (board[row][col] != blank)
            {
                rowNums.push_back(board[row][col]);
            }
        }
        for (int i = 0; i < rowNums.size(); i++)
        {
            for (int j = i + 1; j < rowNums.size(); j++)
            {
                if (rowNums[i] == rowNums[j])
                {
                    isValid = false;
                }
            }
        }
        rowNums.clear();
    }

    // Check columns
    for (int col = 0; col < board[0].size(); col++)
    {
        for (int row = 0; row < board.size(); row++)
        {
            if (board[row][col] != blank)
            {
                colNums.push_back(board[row][col]);
            }
        }
        for (int i = 0; i < colNums.size(); i++)
        {
            for (int j = i + 1; j < colNums.size(); j++)
            {
                if (colNums[i] == colNums[j])
                {
                    isValid = false;
                }
            }
        }
        colNums.clear();
    }
    return isValid;
}

bool isValidSudoku(vector<vector<char> > &board)
{
    bool isValid = false;
    // Allocate the grids
    allocateGrids(board);

    // Check if the grids are valid:
    if (isValidGrid(grid1) && isValidGrid(grid2) && isValidGrid(grid3) && isValidGrid(grid4) && isValidGrid(grid5) && isValidGrid(grid6) && isValidGrid(grid7) && isValidGrid(grid8) && isValidGrid(grid9) && validateBoard(board))
    {
        return true;
    }
    else
    {
        return false;
    }
}
