#ifndef COUNTARRAY
#define COUNTARRAY

#include "TwoDArray.h"
#include <iostream>
#include <string>

using namespace std;

class CountArray : public TwoDArray
{

public:
    CountArray(int **array, int *sizes, int baseSize);
    int *operator[](int index);
};

#endif
