#ifndef TWODARRAY
#define TWODARRAY

// Do not add any more #includes
#include <iostream>
#include <string>

using namespace std;

// Define class below
class TwoDArray;
ostream &operator<<(ostream &out, TwoDArray &obj);

class TwoDArray
{
private:
    int **array; // wrapped array of integers
    int *sizes;
    int baseSize;

public:
    TwoDArray(int **array, int *sizes, int baseSize);
    ~TwoDArray();
    virtual int *operator[](int) = 0;
    operator int();
    operator int *();
    operator int **();
    friend ostream &operator<<(ostream &out, TwoDArray &obj);

protected:
    int **getArray();
    int *getSizes();
    int getBaseSize();
};

#endif
