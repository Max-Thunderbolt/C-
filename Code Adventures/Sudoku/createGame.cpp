#include "createGame.h"
#include "printSudoku.h"

#include <vector>
#include <iostream>

using namespace std;

createGame::createGame()
{
}

void createGame::createGame1()
{
    //!                 BOARD 1
    char col[] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    char col2[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    char col3[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    char col4[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    char col5[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    char col6[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    char col7[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    char col8[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    char col9[] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    board.push_back(vector<char>(col, col + sizeof(col) / sizeof(char)));
    board.push_back(vector<char>(col2, col2 + sizeof(col2) / sizeof(char)));
    board.push_back(vector<char>(col3, col3 + sizeof(col3) / sizeof(char)));
    board.push_back(vector<char>(col4, col4 + sizeof(col4) / sizeof(char)));
    board.push_back(vector<char>(col5, col5 + sizeof(col5) / sizeof(char)));
    board.push_back(vector<char>(col6, col6 + sizeof(col6) / sizeof(char)));
    board.push_back(vector<char>(col7, col7 + sizeof(col7) / sizeof(char)));
    board.push_back(vector<char>(col8, col8 + sizeof(col8) / sizeof(char)));
    board.push_back(vector<char>(col9, col9 + sizeof(col9) / sizeof(char)));
    printSudoku print;
    print.printGame(board);
}

void createGame::createGame2()
{
    //!                 BOARD 2
    char col[] = {'.', '.', '.', '.', '.', '.', '5', '.', '.'};
    char col2[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    char col3[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    char col4[] = {'9', '3', '.', '.', '2', '.', '4', '.', '.'};
    char col5[] = {'.', '.', '7', '.', '.', '.', '3', '.', '.'};
    char col6[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    char col7[] = {'.', '.', '.', '3', '4', '.', '.', '.', '.'};
    char col8[] = {'.', '.', '.', '.', '.', '3', '.', '.', '.'};
    char col9[] = {'.', '.', '.', '.', '.', '5', '2', '.', '.'};
    board.push_back(vector<char>(col, col + sizeof(col) / sizeof(char)));
    board.push_back(vector<char>(col2, col2 + sizeof(col2) / sizeof(char)));
    board.push_back(vector<char>(col3, col3 + sizeof(col3) / sizeof(char)));
    board.push_back(vector<char>(col4, col4 + sizeof(col4) / sizeof(char)));
    board.push_back(vector<char>(col5, col5 + sizeof(col5) / sizeof(char)));
    board.push_back(vector<char>(col6, col6 + sizeof(col6) / sizeof(char)));
    board.push_back(vector<char>(col7, col7 + sizeof(col7) / sizeof(char)));
    board.push_back(vector<char>(col8, col8 + sizeof(col8) / sizeof(char)));
    board.push_back(vector<char>(col9, col9 + sizeof(col9) / sizeof(char)));
    printSudoku print;
    return print.printGame(board);
}

void createGame::createGame3()
{
    //!                BOARD 3
    char col[] = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    char col2[] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    char col3[] = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    char col4[] = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    char col5[] = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    char col6[] = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    char col7[] = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    char col8[] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    char col9[] = {'.', '.', '.', '2', '7', '5', '9', '.', '.'};
    board.push_back(vector<char>(col, col + sizeof(col) / sizeof(char)));
    board.push_back(vector<char>(col2, col2 + sizeof(col2) / sizeof(char)));
    board.push_back(vector<char>(col3, col3 + sizeof(col3) / sizeof(char)));
    board.push_back(vector<char>(col4, col4 + sizeof(col4) / sizeof(char)));
    board.push_back(vector<char>(col5, col5 + sizeof(col5) / sizeof(char)));
    board.push_back(vector<char>(col6, col6 + sizeof(col6) / sizeof(char)));
    board.push_back(vector<char>(col7, col7 + sizeof(col7) / sizeof(char)));
    board.push_back(vector<char>(col8, col8 + sizeof(col8) / sizeof(char)));
    board.push_back(vector<char>(col9, col9 + sizeof(col9) / sizeof(char)));
    printSudoku print;
    return print.printGame(board);
}

void createGame::deleteGame()
{
    board.clear();
}
