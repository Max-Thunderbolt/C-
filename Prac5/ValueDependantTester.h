#ifndef VALUEDEPENDANTTESTER_H
#define VALUEDEPENDANTTESTER_H

#include "NumberTester.h"

class ValueDependantTester : public NumberTester
{
private:
    static int numAliveObjects;

protected: 
    int value;

public: 
    ValueDependantTester(int val);
    ~ValueDependantTester();
    virtual bool evaluate(int val) = 0;
    virtual NumberTester* clone() = 0;
    static int getNumAliveObjects();
};
//int ValueDependantTester::numAliveObjects = 0;
#endif
