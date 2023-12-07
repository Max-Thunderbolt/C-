#ifndef CREATEGAME_H 
#define CREATEGAME_H

#include <vector>

using namespace std;

class createGame
{
public: 
    vector<vector<char> > board;
    vector<vector<char> > grid1, grid2, grid3, grid4, grid5, grid6, grid7, grid8, grid9;
    createGame();
    void createGame1();
    void createGame2();
    void createGame3();
    void deleteGame();
};

#endif