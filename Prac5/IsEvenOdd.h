#ifndef ISEVENODD_H
#define ISEVENODD_H

#include "ValueIndependantTester.h" 

class IsEvenOdd : public ValueIndependantTester
{
private: 
    static int numAliveObjects;
public: 
    IsEvenOdd();
    virtual ~IsEvenOdd();
    virtual bool evaluate(int val);
    NumberTester* clone();
    int getNumAliveObjects();
};

//int IsEvenOdd::numAliveObjects = 0;
#endif
