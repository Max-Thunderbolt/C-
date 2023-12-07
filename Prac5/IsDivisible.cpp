#include "IsDivisible.h"
#include "ValueDependantTester.h"

int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int val) : ValueDependantTester(val)
{
    numAliveObjects++;
}

IsDivisible::~IsDivisible()
{
    numAliveObjects--;
}

bool IsDivisible::evaluate(int val)
{
    if (val % value == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int IsDivisible::getNumAliveObjects()
{ 
    return numAliveObjects;
}

NumberTester* IsDivisible::clone()
{
    IsDivisible *newDivisible = new IsDivisible(value);
    return newDivisible;
}