#ifndef TESTERINTERFACE_H
#define TESTERINTERFACE_H

#include "NumberTester.h"

class TesterInterface
{ 
private: 
    int currNumTesters; 
    NumberTester** testers;
    int maxNumTesters; 

public:
TesterInterface(int maxNumTesters);
    TesterInterface(TesterInterface *other);
    TesterInterface(TesterInterface &other);
    ~TesterInterface();
    int addTester(NumberTester *tester);
    bool removeTester(int pos);
    bool evaluate(int num);
    int *failedTests(int num); 
    int numberOfFailedTests(int num); 
 NumberTester* operator[](int pos);
    const int getCurrNumTesters();
    const int getMaxNumTesters();

    
    
};

#endif
