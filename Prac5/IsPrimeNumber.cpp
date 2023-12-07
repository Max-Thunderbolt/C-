#include "IsPrimeNumber.h"

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber()
{ 
    numAliveObjects++;
}

IsPrimeNumber::~IsPrimeNumber()
{ 
    numAliveObjects--;
}

bool IsPrimeNumber::evaluate(int val)
{
    if (val == 1)
    {
        return false;
    }
    else if (val == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < val; i++)
        {
            if (val % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

NumberTester* IsPrimeNumber::clone()
{
    IsPrimeNumber *newPrime = new IsPrimeNumber();
    return newPrime;
}

int IsPrimeNumber::getNumAliveObjects()
{
    return numAliveObjects;
}