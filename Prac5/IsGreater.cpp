#include "IsGreater.h"

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int val) : ValueDependantTester(val)
{
    numAliveObjects++;
}

IsGreater::~IsGreater()
{
    numAliveObjects--;
}

bool IsGreater::evaluate(int val)
{
    if (val > value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

NumberTester* IsGreater::clone()
{
    IsGreater *newGreater = new IsGreater(value);
    return newGreater;
}

int IsGreater::getNumAliveObjects()
{
    return numAliveObjects;
}
