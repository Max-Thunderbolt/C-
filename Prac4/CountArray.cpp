#include "CountArray.h"

using namespace std;

CountArray::CountArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{
}

int *CountArray::operator[](int index)
{
    int *ret;
    int counter = 0;
    counter += getSizes()[index];
    ret = new int(counter);
    return ret;
}
