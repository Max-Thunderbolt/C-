#ifndef ISSMALLER_H
#define ISSMALLER_H

#include "ValueDependantTester.h"

class IsSmaller : public ValueDependantTester
{
private: 
    static int numAliveObjects;

public: 
    IsSmaller(int val);
    ~IsSmaller();
    bool evaluate(int val);
    NumberTester* clone();
    static int getNumAliveObjects();
};
//int IsSmaller::numAliveObjects = 0;
#endif 
