#ifndef PRINT_H 
#define PRINT_H

#include <vector>

#include "createGame.h"

using namespace std;

class printSudoku
{
public:
    printSudoku();
    void printGame(vector<vector<char> > &board);
};

#endif 