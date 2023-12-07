#include "IsSmaller.h"

int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int val) : ValueDependantTester(val)
{
    numAliveObjects++;
}

IsSmaller::~IsSmaller()
{
    numAliveObjects--;
}

bool IsSmaller::evaluate(int val)
{ 
    if (val < value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int IsSmaller::getNumAliveObjects()
{
    return numAliveObjects;
}

NumberTester* IsSmaller::clone()
{
    IsSmaller *newSmaller = new IsSmaller(value);
    return newSmaller;
}