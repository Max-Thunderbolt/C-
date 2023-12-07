#include "printSudoku.h"

#include <iostream> 

using namespace std;

printSudoku::printSudoku()
{
}

void printSudoku::printGame(vector<vector<char> > &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
}
