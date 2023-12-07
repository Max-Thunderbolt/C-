#ifndef TOH_H
#define TOH_H

#include <stack>

#include "Exception.h"
#include "Disk.h"

using namespace std;

template <class T>
class TowersOfHanoi
{
protected:
    stack<Disk<T> *> *t1;
    stack<Disk<T> *> *t2;
    stack<Disk<T> *> *t3;
    int startTower;
    int goalTower;
    TowersOfHanoi();

public:
    void moveDisk(int dep, int dest);
    TowersOfHanoi(int startTower, int goalTower);
    ~TowersOfHanoi();
    void addDisk(T diskData, int tower);
    bool validateGame();
    stack<Disk<T> *> *getTower(int tower);
    virtual void solveGame() = 0;
};

#endif
