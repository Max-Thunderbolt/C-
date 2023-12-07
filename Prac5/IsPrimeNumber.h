#ifndef ISPRIMENUMBER_H
#define ISPRIMENUMBER_H

#include "ValueIndependantTester.h"

class IsPrimeNumber : public ValueIndependantTester
{
private: 
    static int numAliveObjects;

public: 
    IsPrimeNumber();
    virtual ~IsPrimeNumber();
    virtual bool evaluate(int val);
    NumberTester* clone();
    static int getNumAliveObjects();
};
//int IsPrimeNumber::numAliveObjects = 0;
#endif 
