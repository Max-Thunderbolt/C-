#ifndef SUMARRAY
#define SUMARRAY

#include "TwoDArray.h"

using namespace std;

class SumArray : public TwoDArray
{
public: 
    SumArray(int **array, int *sizes, int baseSize);
    int* operator[](int);
};

#endif
