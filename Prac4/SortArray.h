#ifndef SORTARRAY
#define SORTARRAY

#include "TwoDArray.h"
#include <iostream>
#include <string>

using namespace std;

class SortArray : public TwoDArray
{
public:
    SortArray(int **array, int *sizes, int baseSize);
    int *operator[](int);
};

#endif
