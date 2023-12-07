#include "TwoDArray.h"

#include <string>
#include <iostream>

using namespace std;

TwoDArray::TwoDArray(int **array, int *sizes, int baseSize)
{
    this->baseSize = baseSize;
    this->array = new int *[baseSize];
    this->sizes = new int[baseSize];

    for (int i = 0; i < baseSize; i++)
    {
        this->sizes[i] = sizes[i];
        this->array[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            this->array[i][j] = array[i][j];
        }
    }
}

TwoDArray::~TwoDArray()
{
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] sizes;
}

TwoDArray::operator int()
{
    return getBaseSize();
}

TwoDArray::operator int *()
{
    int *arr = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        arr[i] = sizes[i];
    }
    return arr;
}

TwoDArray::operator int **()
{
    int **temp = new int *[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            temp[i][j] = array[i][j];
        }
    }
    return temp;
}

//! might not work
ostream &operator<<(std::ostream &out, TwoDArray &obj)
{
    for (int i = 0; i < obj.baseSize; i++)
    {
        for (int j = 0; j < obj.sizes[i]; j++)
        {
                out << obj.array[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

int **TwoDArray::getArray()
{
    int **temp = new int *[baseSize];

    for (int i = 0; i < baseSize; i++)
    {
        temp[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            temp[i][j] = array[i][j];
        }
    }

    return temp;
}

int *TwoDArray::getSizes()
{
    int *ret = new int[baseSize];

    for (int i = 0; i < baseSize; i++)
    {
        ret[i] = this->sizes[i];
    }

    return ret;
}

int TwoDArray::getBaseSize()
{
    return baseSize;
}
