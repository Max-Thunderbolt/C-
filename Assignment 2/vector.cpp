#include "vector.h"
#include <iomanip>

/////////////////
//// Task 1 ////
///////////////

Vector::Vector(unsigned s)
{
    this->size = s;
    this->vector = new double[s];
    for (int i = 0; i < this->size; i++)
    {
        this->vector[i] = 0;
    }
}

Vector::Vector(const Vector &rhs)
{
    this->size = rhs.size;

    this->vector = new double[this->size];

    for (int i = 0; i < this->size; i++)
    {
        this->vector[i] = rhs.vector[i];
    }
}

Vector::~Vector()
{
    delete[] vector;
}

void Vector::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << setprecision(3) << vector[i] << " ";
    }
    cout << endl;
}

void Vector::readFile(istream &infile)
{
    for (int i = 0; i < size; i++)
    {
        infile >> vector[i];
    }
}

double &Vector::operator[](const unsigned r)
{
    return vector[r];
}

const double &Vector::operator[](const unsigned r) const
{
    return vector[r];
}

unsigned Vector::getSize() const
{
    return size;
}

/////////////////
//// TASK 2 ////
///////////////

Vector Vector::operator*(const double &rhs)
{
    Vector *temp = new Vector(*this);

    for (int i = 0; i < this->size; i++)
    {
        temp->vector[i] *= rhs;
    }

    return *temp;
}

Vector &Vector::operator*=(const double &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] * rhs;
    }

    return *this;
}

Vector Vector::operator/(const double &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] / rhs;
    }

    return *this;
}

const Vector &Vector::operator=(const Vector &rhs)
{
    if (rhs.size >= 0)
    {
        Vector *newVect = new Vector(rhs);
        return *newVect;
    }
    return *this;
}

Vector Vector::operator+(const Vector &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] += rhs.vector[i];
    }
}

Vector &Vector::operator+=(const Vector &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] += rhs.vector[i];
    }
}

Vector Vector::operator-(const Vector &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] -= rhs.vector[i];
    }
}

Vector &Vector::operator-=(const Vector &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] -= rhs.vector[i];
    }
}

Vector Vector::operator^(int pow)
{
    if (pow < 0)
    {
        cout << "Error: negative power is not supported" << endl;
    }
    else if (pow == 0)
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = 1;
        }
    }
    else if (pow == 1)
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = vector[i];
        }
    }
    else if (pow > 0)
    {
        for (int j = 0; j < pow; j++)
        {
            for (int i = 0; i < size; i++)
            {
                vector[i] += vector[i] * vector[i];
            }
        }
    }
}

Vector &Vector::operator^=(int pow)
{
    if (pow < 0)
    {
        cout << "Error: negative power is not supported" << endl;
    }
    else if (pow == 0)
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = 1;
        }
    }
    else if (pow == 1)
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = vector[i];
        }
    }
    else if (pow > 0)
    {
        for (int j = 0; j < pow; j++)
        {
            for (int i = 0; i < size; i++)
            {
                vector[i] += vector[i] * vector[i];
            }
        }
    }
}

Vector Vector::operator~()
{
    Vector temp = *vector;

    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > 0; j--)
        {
            temp[i] = vector[i];
            vector[i] = temp[j];
        }
    }
}
