#include "TowersOfHanoi.h"


template <class T>
TowersOfHanoi<T>::TowersOfHanoi()
{
    // Leave body empty
}

template <class T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower, int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;

    // Check that game is valid
    if (startTower == goalTower)
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
    if (startTower < 1 || startTower > 3)
    {
        try
        {

            throw *Exception<T>::invalidTower(startTower);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }

    if (goalTower < 1 || goalTower > 3)
    {
        try
        {
            throw *Exception<T>::invalidTower(goalTower);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }

    // Initialise the towers with new stacks
    this->t1 = new stack<Disk<T> *>();
    this->t2 = new stack<Disk<T> *>();
    this->t3 = new stack<Disk<T> *>();
}

template <class T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest)
{

    /*
    NOTES:
    - dep = departure tower
    - dest = destination tower
    - Legal move check has already been performed in sort() method
    - The top disk of the departure tower is popped and pushed onto the destination tower
    */

    // Check that the departure tower is not empty
    if (this->getTower(dep)->empty())
    {
        try
        {
            throw *Exception<T>::emptyStack(dep);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }

    if (dep == dest)
    {
        try
        {
            throw *Exception<T>::incorrectDiskMove(dep, dest);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }

    // Get the top disk of the departure tower && the top disk of the destination tower
    stack<Disk<T> *> *tempDepStack = getTower(dep);
    stack<Disk<T> *> *tempDestStack = getTower(dest);

    Disk<T> *tempDepDisk = tempDepStack->top();
    Disk<T> *tempDestDisk;
    if (tempDestStack->empty())
    {
    }
    else
    {
        tempDestDisk = tempDestStack->top();
    }

    T valDep = tempDepDisk->getLabel();
    T valDest;
    if (tempDestStack->empty())
    {
        valDest = 0;
    }
    else
    {
        valDest = tempDestDisk->getLabel();
    }

    // Check that the top disk of the departure tower is smaller than the top disk of the destination tower
    if (valDep > valDest && valDest != 0)
    {
        try
        {
            throw *Exception<T>::incorrectDiskMove(dep, dest);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }
    else
    {
        // Move the disk from the departure tower to the destination tower
        this->getTower(dest)->push(tempDepDisk);
        this->getTower(dep)->pop();

        // Print the move
        Exception<T>::movePlan(tempDepDisk, dep, dest);
    }
}

template <class T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower)
{
    /*
    NOTES:
    - Add a disk to the specified tower
    - The diskData is the label of the disk
    - The tower is the tower number to add the disk to
    - The disk must be added to the top of the tower
    - We only add disks to the start tower (t1)
    */

    stack<Disk<T> *> *tempTower = getTower(tower);
    if (tower < 1 || tower > 3)
    {
        try
        {
            throw *Exception<T>::invalidTower(tower);
        }
        catch (Exception<T> &e)
        {
            cout << e.message << endl;
        }
    }
    else
    {

        if (tempTower->empty())
        {
            Disk<T> *tempDisk = new Disk<T>(diskData);
            tempTower->push(tempDisk);
        }
        else
        {
            Disk<T> *tempDisk = tempTower->top();
            if (tempDisk->getLabel() > diskData)
            {
                Disk<T> *tempDisk = new Disk<T>(diskData);
                tempTower->push(tempDisk);
            }
            else
            {
                try
                {
                    throw *Exception<T>::invalidDiskAdd(tower, diskData);
                }
                catch (Exception<T> &e)
                {
                    cout << e.message << endl;
                }
            }

            //! The following is used during debugging.
            // cout << "Checking what data we have: " << endl;
            // cout << "---------------------------" << endl;
            // cout << "Disk data: " << diskData << endl;
            // cout << "Tower: " << tower << endl;
            // cout << "Start tower: " << startTower << endl;
            // cout << "Goal tower: " << goalTower << endl;
            // cout << "Start tower top: " << getTower(1)->top()->getLabel() << endl;
            // cout << "Start tower size: " << getTower(1)->size() << endl;
            // cout << "---- END OF CHECK------" << endl
            //      << endl;
        }
    }
}

template <class T>
bool TowersOfHanoi<T>::validateGame()
{
    bool ret = false;
    stack<Disk<T> *> *tempTower = getTower(1);
    int size = 0;

    if (this->t1->size() == 1)
    {
        return false;
    }

    if (!this->t2->empty())
    {
        size++;
    }
    if (!this->t3->empty())
    {
        size++;
    }
    if (size > 1)
    {
        ret = false;
    }
    else
    {
        if (tempTower->empty())
        {
            ret = false;
        }
        else
        {
            Disk<T> *tempDisk = tempTower->top();
            if (tempDisk->getLabel() == 1)
            {
                ret = true;
            }
            else
            {
                ret = false;
            }
        }
    }
    return ret;
}

template <class T>
stack<Disk<T> *> *TowersOfHanoi<T>::getTower(int tower)
{
    switch (tower)
    {
    case 1:
        return this->t1;
    case 2:
        return this->t2;
    case 3:
        return this->t3;
    default:
        return NULL;
    }
}

template <class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
    // Delete disks
    while (!this->t1->empty())
    {
        Disk<T> *tempDisk = this->t1->top();
        this->t1->pop();
        delete tempDisk;
    }
    while (!this->t2->empty())
    {
        Disk<T> *tempDisk = this->t2->top();
        this->t2->pop();
        delete tempDisk;
    }
    while (!this->t3->empty())
    {
        Disk<T> *tempDisk = this->t3->top();
        this->t3->pop();
        delete tempDisk;
    }

    // Delete stacks
    delete this->t1;
    delete this->t2;
    delete this->t3;
}