#include "IterativeSolution.h"

template <class T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower) : TowersOfHanoi<T>(startTower, goalTower)
{
}

template <class T>
void IterativeSolution<T>::solveGame()
{
    // Check that game is valid before attempting to solve
    TowersOfHanoi<T>::validateGame();
    if (TowersOfHanoi<T>::validateGame() == 0)
    {
        try
        {
            throw *Exception<T>::invalidGame();
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }
    else // Game is valid
    {
        int minNumMoves = pow(2, this->t1->size()) - 1;
        int goalTowerEndSize = this->t1->size(); // This is used as the end condition for the algorithm.

        if (this->t1->size() % 2 == 0) // Even number of disks
        {

            for (int i = 0; i < minNumMoves;)
            {
                int start = this->startTower;
                int goal = this->goalTower;
                int aux = 0;
                if (this->startTower == 1 && this->goalTower == 2)
                {
                    aux = 3;
                }
                else if (this->startTower == 1 && this->goalTower == 3)
                {
                    aux = 2;
                }
                else if (this->startTower == 2 && this->goalTower == 1)
                {
                    aux = 3;
                }
                else if (this->startTower == 2 && this->goalTower == 3)
                {
                    aux = 1;
                }
                else if (this->startTower == 3 && this->goalTower == 1)
                {
                    aux = 2;
                }
                else if (this->startTower == 3 && this->goalTower == 2)
                {
                    aux = 1;
                }
                // Get the value(label) of the top disk of the towers. This will be used to determine the legal move.
                stack<Disk<T> *> *tempT1 = TowersOfHanoi<T>::getTower(start);
                stack<Disk<T> *> *tempT2 = TowersOfHanoi<T>::getTower(aux);
                stack<Disk<T> *> *tempT3 = TowersOfHanoi<T>::getTower(goal);

                Disk<T> *disk1;
                Disk<T> *disk2;
                Disk<T> *disk3;

                if (tempT1->size() > 0)
                {
                    disk1 = tempT1->top();
                }

                if (tempT2->size() > 0)
                {
                    disk2 = tempT2->top();
                }

                if (tempT3->size() > 0)
                {
                    disk3 = tempT3->top();
                }

                T valT1 = 0;
                T valT2 = 0;
                T valT3 = 0;

                if (tempT1->size() > 0)
                {
                    valT1 = disk1->getLabel();
                }

                if (tempT2->size() > 0)
                {
                    valT2 = disk2->getLabel();
                }

                if (tempT3->size() > 0)
                {
                    valT3 = disk3->getLabel();
                }

                /* STEPS TO SOLVE: (https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/)
                1.) Make legal move between start Tower and aux Tower   (1 <-> 2)
                2.) Make legal move between start Tower and goal Tower  (1 <-> 3)
                3.) Make legal move between aux Tower and goal Tower    (2 <-> 3)
                */

                //? 1.) Make legal move between start Tower and aux Tower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT2 && valT1 != 0 || valT2 == 0) // (1 -> 2)
                    {
                        // Make legal move between startTower and auxTower
                        TowersOfHanoi<T>::moveDisk(start, aux);
                        i++;
                        valT2 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else // (2 -> 1)
                    {
                        // Make legal move between auxTower and startTower
                        TowersOfHanoi<T>::moveDisk(aux, start);
                        i++;
                        valT1 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                }

                //? 2.) Make legal move between start Tower and goal Tower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT3 && valT1 != 0 || valT3 == 0) // (1 -> 3)
                    {
                        // Make legal move between startTower and goalTower
                        TowersOfHanoi<T>::moveDisk(start, goal);
                        i++;
                        valT3 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else if (valT1 == 0 || valT3 < valT1) // (3 -> 1)
                    {
                        // Make legal move between goalTower and startTower
                        TowersOfHanoi<T>::moveDisk(goal, start);
                        i++;
                        valT1 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }

                //? 3.) Make legal move between aux Tower and goal Tower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT2 < valT3) // (2 -> 3)
                    {
                        // Make legal move between tempTower and goalTower
                        TowersOfHanoi<T>::moveDisk(aux, goal);
                        i++;
                        valT3 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                    else // (3 -> 2)
                    {
                        // Make legal move between goalTower and tempTower
                        TowersOfHanoi<T>::moveDisk(goal, aux);
                        i++;
                        valT2 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }
            }
        }
        else // Odd number of disks
        {

            for (int i = 0; i < minNumMoves;)
            {
                int start = this->startTower;
                int goal = this->goalTower;
                int aux = 0;
                if (this->startTower == 1 && this->goalTower == 2)
                {
                    aux = 3;
                }
                else if (this->startTower == 1 && this->goalTower == 3)
                {
                    aux = 2;
                }
                else if (this->startTower == 2 && this->goalTower == 1)
                {
                    aux = 3;
                }
                else if (this->startTower == 2 && this->goalTower == 3)
                {
                    aux = 1;
                }
                else if (this->startTower == 3 && this->goalTower == 1)
                {
                    aux = 2;
                }
                else if (this->startTower == 3 && this->goalTower == 2)
                {
                    aux = 1;
                }

                stack<Disk<T> *> *tempT1 = TowersOfHanoi<T>::getTower(start);
                stack<Disk<T> *> *tempT2 = TowersOfHanoi<T>::getTower(aux);
                stack<Disk<T> *> *tempT3 = TowersOfHanoi<T>::getTower(goal);
                // Get the values(label) of the top disk of each tower. This will be used to determine the legal move.
                Disk<T> *disk1;
                Disk<T> *disk2;
                Disk<T> *disk3;
                if (tempT1->size() > 0)
                {
                    disk1 = tempT1->top();
                }

                if (tempT2->size() > 0)
                {
                    disk2 = tempT2->top();
                }

                if (tempT3->size() > 0)
                {
                    disk3 = tempT3->top();
                }

                T valT1 = 0;
                T valT2 = 0;
                T valT3 = 0;

                if (tempT1->size() > 0)
                {
                    valT1 = disk1->getLabel();
                }

                if (tempT2->size() > 0)
                {
                    valT2 = disk2->getLabel();
                }

                if (tempT3->size() > 0)
                {
                    valT3 = disk3->getLabel();
                }

                /*
                STEPS TO SOLVE: (https://www.stemlittleexplorers.com/en/make-and-solve-tower-of-hanoi/)
                1.) Make legal move between startTower and goalTower (1 <-> 3)
                2.) Make legal move between startTower and tempTower (1 <-> 2)
                3.) Make legal move between tempTower and goalTower  (2 <-> 3)
                */

                //? Step 1 - Make legal move between startTower and goalTower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT3 || valT3 == 0) // Move disk from start tower to goal tower (1 -> 3)
                    {

                        TowersOfHanoi<T>::moveDisk(start, goal);
                        i++;
                        valT3 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else // Move disk from goal tower to start tower (3 -> 1)
                    {

                        TowersOfHanoi<T>::moveDisk(goal, start);
                        i++;
                        valT1 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }

                //? Step 2 - Make legal move between startTower and tempTower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT2 && valT1 != 0 || valT2 == 0) // Move disk from start tower to goal tower (1 -> 2)
                    {
                        TowersOfHanoi<T>::moveDisk(start, aux);
                        i++;
                        valT2 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else if (valT1 == 0 || valT2 < valT1) // Move disk from temp tower to start tower (2 -> 1)
                    {

                        TowersOfHanoi<T>::moveDisk(aux, start);
                        i++;
                        valT1 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                }

                //? Step 3 - Make legal move between tempTower and goalTower
                if (i == minNumMoves)
                {
                    break;
                }
                else
                {
                    if (valT2 < valT3) // Move disk from temp tower to goal tower (2 -> 3)
                    {
                        TowersOfHanoi<T>::moveDisk(aux, goal);
                        i++;
                        valT3 = valT2;
                        if (tempT2->size() > 0) // If tower 2 is not empty
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                    else // Move disk from goal tower to temp tower (3 -> 2)
                    {
                        TowersOfHanoi<T>::moveDisk(goal, aux);
                        i++;
                        valT2 = valT3;
                        if (tempT3->size() > 0) // If tower 3 is not empty
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }
            }
        }
    }
}

template <class T>
void IterativeSolution<T>::moves(int numMoves)
{

    int start = this->startTower;
    int goal = this->goalTower;
    int aux = 0;

    if (this->startTower == 1 && this->goalTower == 2)
    {
        aux = 3;
    }
    else if (this->startTower == 1 && this->goalTower == 3)
    {
        aux = 2;
    }
    else if (this->startTower == 2 && this->goalTower == 1)
    {
        aux = 3;
    }
    else if (this->startTower == 2 && this->goalTower == 3)
    {
        aux = 1;
    }
    else if (this->startTower == 3 && this->goalTower == 1)
    {
        aux = 2;
    }
    else if (this->startTower == 3 && this->goalTower == 2)
    {
        aux = 1;
    }

    stack<Disk<T> *> *tempT1 = TowersOfHanoi<T>::getTower(start);
    stack<Disk<T> *> *tempT2 = TowersOfHanoi<T>::getTower(aux);
    stack<Disk<T> *> *tempT3 = TowersOfHanoi<T>::getTower(goal);

    if (numMoves < 0)
    {
        try
        {

            throw *Exception<T>::invalidMoves(numMoves);
        }

        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }
    else if (numMoves > (pow(2, tempT1->size()) - 1))
    {
        solveGame();
    }
    else
    {
        int minNumMoves = pow(2, this->t1->size()) - 1;
        int goalTowerEndSize = this->t1->size();
        if (this->t1->size() % 2 == 0)
        {
            for (int i = 0; i < numMoves;)
            {

                Disk<T> *disk1 = tempT1->top();
                Disk<T> *disk2;
                Disk<T> *disk3;
                if (tempT2->size() > 0)
                {
                    disk2 = tempT2->top();
                }
                else
                {
                }
                if (tempT3->size() > 0)
                {
                    disk3 = tempT3->top();
                }
                else
                {
                }

                T valT1 = disk1->getLabel();
                T valT2 = 0;
                T valT3 = 0;

                if (tempT2->size() > 0)
                {
                    valT2 = disk2->getLabel();
                }
                else
                {
                }
                if (tempT3->size() > 0)
                {
                    valT3 = disk3->getLabel();
                }
                else
                {
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT2 || valT2 == 0)
                    {

                        TowersOfHanoi<T>::moveDisk(start, aux);
                        i++;
                        valT2 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else
                    {
                        TowersOfHanoi<T>::moveDisk(aux, start);
                        i++;
                        valT1 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT3 && valT1 != 0 || valT3 == 0)
                    {
                        TowersOfHanoi<T>::moveDisk(start, goal);
                        i++;
                        valT3 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else if (valT1 == 0 || valT3 < valT1)
                    {

                        TowersOfHanoi<T>::moveDisk(goal, start);
                        i++;
                        valT1 = valT3;
                        if (tempT2->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT2 < valT3)
                    {
                        TowersOfHanoi<T>::moveDisk(aux, goal);
                        i++;
                        valT3 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                    else
                    {
                        TowersOfHanoi<T>::moveDisk(goal, aux);
                        i++;
                        valT2 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < numMoves;)
            {
                Disk<T> *disk1 = tempT1->top();
                Disk<T> *disk2;
                Disk<T> *disk3;
                if (tempT2->size() > 0)
                {
                    disk2 = tempT2->top();
                }
                else
                {
                }
                if (tempT3->size() > 0)
                {
                    disk3 = tempT3->top();
                }
                else
                {
                }

                T valT1 = disk1->getLabel();
                T valT2 = 0;
                T valT3 = 0;

                if (tempT2->size() > 0)
                {
                    valT2 = disk2->getLabel();
                }
                else
                {
                }
                if (tempT3->size() > 0)
                {
                    valT3 = disk3->getLabel();
                }
                else
                {
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT3 || valT3 == 0)
                    {

                        TowersOfHanoi<T>::moveDisk(start, goal);
                        i++;
                        valT3 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else
                    {
                        TowersOfHanoi<T>::moveDisk(goal, start);
                        i++;
                        valT1 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT1 < valT2 && valT1 != 0 || valT2 == 0)
                    {
                        TowersOfHanoi<T>::moveDisk(start, aux);
                        i++;
                        valT2 = valT1;
                        if (tempT1->size() > 0)
                        {
                            disk1 = tempT1->top();
                            valT1 = disk1->getLabel();
                        }
                        else
                        {
                            valT1 = 0;
                        }
                    }
                    else if (valT1 == 0 || valT2 < valT1)
                    {

                        TowersOfHanoi<T>::moveDisk(aux, start);
                        i++;
                        valT1 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                }

                if (i == numMoves)
                {
                    break;
                }
                else
                {
                    if (valT2 < valT3)
                    {
                        TowersOfHanoi<T>::moveDisk(aux, goal);
                        i++;
                        valT3 = valT2;
                        if (tempT2->size() > 0)
                        {
                            disk2 = tempT2->top();
                            valT2 = disk2->getLabel();
                        }
                        else
                        {
                            valT2 = 0;
                        }
                    }
                    else
                    {
                        TowersOfHanoi<T>::moveDisk(goal, aux);
                        i++;
                        valT2 = valT3;
                        if (tempT3->size() > 0)
                        {
                            disk3 = tempT3->top();
                            valT3 = disk3->getLabel();
                        }
                        else
                        {
                            valT3 = 0;
                        }
                    }
                }
            }
        }
    }
}