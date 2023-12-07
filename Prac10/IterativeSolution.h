#ifndef IS_H
#define IS_H

#include <stack>
#include <cmath>

#include "TowersOfHanoi.h"
#include "Disk.h"

template <class T>
class IterativeSolution : public TowersOfHanoi<T>
{
public: 
    IterativeSolution(int startTower, int endTower);
    void solveGame(); 
    void moves(int numMoves);
};

#endif
