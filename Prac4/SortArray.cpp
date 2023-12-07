#include "SortArray.h"

using namespace std;

SortArray::SortArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{
}

int *SortArray::operator[](int index)
{
    int temp;
    int **tempArr = getArray();
    for (int i = 0; i < getSizes()[index]; i++)
    {
        for (int j = i + 1; j < getSizes()[index]; j++)
        {
            if (tempArr[index][i] > tempArr[index][j])
            {
                temp = tempArr[index][i];
                tempArr[index][i]= tempArr[index][j];
                tempArr[index][j] = temp;
            }
        }
    }
    return tempArr[index];
}
