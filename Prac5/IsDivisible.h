#ifndef ISDIVISIBLE_H
#define ISDIVISIBLE_H

#include "ValueDependantTester.h"

class IsDivisible : public ValueDependantTester
{
private: 
    static int numAliveObjects;

public: 
    IsDivisible(int val);
    ~IsDivisible();
    bool evaluate(int val);
    NumberTester* clone();
    static int getNumAliveObjects();
};

//int IsDivisible::numAliveObjects = 0;
#endif
