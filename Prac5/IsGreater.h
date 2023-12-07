#ifndef ISGREATER_H
#define ISGREATER_H

#include "ValueDependantTester.h"

class IsGreater : public ValueDependantTester
{
private: 
    static int numAliveObjects;

public: 
    IsGreater(int val);
    ~IsGreater();
    bool evaluate(int val);
    NumberTester* clone();
    static int getNumAliveObjects();
};
//int IsGreater::numAliveObjects = 0;
#endif 
