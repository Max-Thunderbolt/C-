#ifndef RS_H
#define RS_H

#include <stack>

#include "TowersOfHanoi.h"
#include "Disk.h"

template <class T>
class RecursiveSolution : public TowersOfHanoi<T>
{
public: 
    RecursiveSolution(int startTower, int goalTower); 
    void solveGame(); 
    int count(); 
    bool contains(T label);

    //Helper functions
    void recursiveSolve(int moves, int startTower, int goalTower, int auxTower);
    int diskIterator(int remainingTowers, int currNumTowers, T* labelPtr);
    int towerIterator(int remainingTowers, int count, T* labelPtr);
    int counter(int towers, int count);
    int numDisksInGame;
    int minNumMoves;
    int goalTowerSize;
    int getGoalTowerSize();
};

#endif
