#include "RecursiveSolution.h"
#include <cmath>

template <class T>
RecursiveSolution<T>::RecursiveSolution(int startTower, int goalTower) : TowersOfHanoi<T>(startTower, goalTower)
{
    this->numDisksInGame = 0;
    this->goalTowerSize = 0;
}

//! IMPLEMENTING THE HELPER FUNCTIONS
template <class T>
void RecursiveSolution<T>::recursiveSolve(int moves, int start, int goal, int aux)
{
    // Solve the game recursively for any number of disks in the game in the start tower and in the minimum number of moves
    // Base case: if there is only one disk, move it from start to goal
    if (moves == 1)
    {
        this->moveDisk(start, goal);
    }
    else if (getGoalTowerSize() < count())
    {
        // Recursive case: move n-1 disks from start to aux, move the nth disk from start to goal, then move n-1 disks from aux to goal
        recursiveSolve(moves - 1, start, aux, goal);
        this->moveDisk(start, goal);
        recursiveSolve(moves - 1, aux, goal, start);
    }
}
template <class T>
int RecursiveSolution<T>::diskIterator(int remainder, int numDisks, T *labelPtr)
{
    stack<Disk<T> *> *currentTower = TowersOfHanoi<T>::getTower(remainder);

    if (currentTower->empty())
    {
        return 0;
    }
    else
    {
        T topDisk = currentTower->top()->getLabel();
        currentTower->pop();
        numDisks += diskIterator(remainder, numDisks, labelPtr);
        numDisks++;
        this->numDisksInGame = numDisks;
        TowersOfHanoi<T>::addDisk(topDisk, remainder);
    }
    return numDisks;
}

template <class T>
int RecursiveSolution<T>::towerIterator(int tower, int count, T *labelPtr)
{
    if (tower == 0)
    {
        return 0;
    }
    else
    {
        int currNumTowers = 0;
        count += diskIterator(tower, currNumTowers, labelPtr);
        this->numDisksInGame = count;
        towerIterator(tower - 1, count, labelPtr);
    }
    return count;
}

template <class T>
int RecursiveSolution<T>::counter(int towers, int count)
{
    /*
    ?NOTES:
    ~~~~~~
    - This function is used to count the number of disks in the game.
    - towers: the number of towers to iterate through
    - count: the number of disks counted so far

    ?STEPS:
    ~~~~~~
    1.) Iterate through the towers and count the number of disks in each tower.
    2.) Return the total number of disks in the game.
    */

    int returnStatement = towerIterator(towers, count, NULL);
    return returnStatement;
}

template <class T>
int RecursiveSolution<T>::count()
{
    int numDisks = 0;
    counter(3, numDisks);
    return this->numDisksInGame;
}

template <class T>
bool RecursiveSolution<T>::contains(T label)
{
    /*
    ?NOTES:
    ~~~~~~
    - This function recursively checks if a disk with a given label exists in the game.
    - Create a temporary stack to hold the disks in the tower.
    - If the tower is empty, return false.
    - If the top disk in the tower has the given label, return true.
    - If the top disk in the tower does not have the given label, pop the disk and recursively call the function again.
    - If the function returns true, push the disk back onto the tower and return true.
    - If the function returns false, push the disk back onto the tower and return false.
    */

    stack<Disk<T> *> *tower1 = TowersOfHanoi<T>::getTower(1);
    stack<Disk<T> *> *tower2 = TowersOfHanoi<T>::getTower(2);
    stack<Disk<T> *> *tower3 = TowersOfHanoi<T>::getTower(3);
    stack<Disk<T> *> *tempTower = new stack<Disk<T> *>();

    if (tower1->empty())
    {
        return false;
    }
    else
    {
        T topDisk = tower1->top()->getLabel();
        if (topDisk == label)
        {
            return true;
        }
        else
        {
            tower1->pop();
            tempTower->push(new Disk<T>(topDisk));
            bool returnStatement = contains(label);
            if (returnStatement)
            {
                tower1->push(tempTower->top());
                tempTower->pop();
                return true;
            }
            else
            {
                tower1->push(tempTower->top());
                tempTower->pop();
                return false;
            }
        }
    }

    if (tower2->empty())
    {
        return false;
    }
    else
    {
        T topDisk = tower2->top()->getLabel();
        if (topDisk == label)
        {
            return true;
        }
        else
        {
            tower2->pop();
            tempTower->push(new Disk<T>(topDisk));
            bool returnStatement = contains(label);
            if (returnStatement)
            {
                tower2->push(tempTower->top());
                tempTower->pop();
                return true;
            }
            else
            {
                tower2->push(tempTower->top());
                tempTower->pop();
                return false;
            }
        }
    }

    if (tower3->empty())
    {
        return false;
    }
    else
    {
        T topDisk = tower3->top()->getLabel();
        if (topDisk == label)
        {
            return true;
        }
        else
        {
            tower3->pop();
            tempTower->push(new Disk<T>(topDisk));
            bool returnStatement = contains(label);
            if (returnStatement)
            {
                tower3->push(tempTower->top());
                tempTower->pop();
                return true;
            }
            else
            {
                tower3->push(tempTower->top());
                tempTower->pop();
                return false;
            }
        }
    }

    return false;

}

template <class T>
int RecursiveSolution<T>::getGoalTowerSize()
{
    /*
    ?NOTES:
    ~~~~~~
    - This function is used to count the number of disks in the goal tower.
    - Add popped disks to a temporary stack to preserve the order of the disks in the goal tower.
    - Add the popped disks back to the goal tower.
    - Return the number of disks in the goal tower.

    ?STEPS:
    ~~~~~~
    1.) Count the number of disks in the goal tower.
    2.) Return the number of disks in the goal tower.
    */

    stack<Disk<T> *> *goalTower = TowersOfHanoi<T>::getTower(this->goalTower);
    stack<Disk<T> *> *temp = new stack<Disk<T> *>();
    int count = 0;

    while (!goalTower->empty())
    {
        temp->push(goalTower->top());
        goalTower->pop();
        count++;
        this->goalTowerSize = count;
    }

    while (!temp->empty())
    {
        goalTower->push(temp->top());
        temp->pop();
    }

}

template <class T>
void RecursiveSolution<T>::solveGame()
{
    // Solve TOH recursively

    // 1.) Calculate the minimum number of moves required to solve the game with any number of disks.
    // 2.) Call recursiveSolve() to solve the game in minimum number of moves.
    // 3.) Return.

    int numDisks = count();
    int minMoves = pow(2, numDisks) - 1;
    this->minNumMoves = minMoves;
    recursiveSolve(minMoves, this->startTower, this->goalTower, 6 - this->startTower - this->goalTower);
}
