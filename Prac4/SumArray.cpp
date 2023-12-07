#include "SumArray.h"

using namespace std;

SumArray::SumArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{
}

int *SumArray::operator[](int index)
{
    int *ret; 
    int counter = 0;
    if (index >= 0 && index <= getBaseSize())
    {
        for (int i = 0; i < getBaseSize(); i++)
        {
            for (int j = 0; j < getSizes()[i]; j++)
            {
                if (i == index)
                {
                    counter += getArray()[i][j];
                }
            }
        }
    }
    ret = new int(counter);
    return ret;
}
