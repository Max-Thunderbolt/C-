// The Plane implementation file
#ifndef PLANE_CPP
#define PLANE_CPP

#include "Plane.h"
#include "Exceptions.h"


using namespace std;

template <typename T>
Plane<T>::Plane(double max)
{
    maxWeight = max;
}

template <typename T>
Plane<T>::~Plane()
{
    if (!cargo->empty())
    {
        for (int i = 0; i < cargo.size(); i++)
        {
            cargo.erease(cargo.begin() + i);
        }
    }
}

template <typename T>
void Plane<T>::add(T *item)
{
    if (!cargo.empty())
    {
        double sum = 0;
        for (int i = 0; i < cargo.size(); i++)
        {
           sum += *cargo[i];
        }

        sum += item->getWeight();

        if (sum > maxWeight)
        {
            throw AboveWeightEx(sum);
        }
        else
        {
            cargo.push_back(item);
        }
    }
    else
    {
        if (item->getWeight() > maxWeight)
        {
            throw AboveWeightEx(item);
        }
        else
        {
            cargo.push_back(item);
        }
    }
}

template <typename T>
void Plane<T>::remove(T *item)
{
    bool found;
    if (cargo->empty())
    {
        throw EmptyEx();
    }
    else
    {
        found = false;

        for (int i = 0; i < cargo.size(); i++)
        {
            if (cargo[i] == item)
            {
                found = true;
                cargo.erase(cargo.begin() + i);
            }
        }
    }

    if (found == false)
    {
        throw NotFoundEx<T>(item);
    }
}

template <typename T>
string Plane<T>::getDescription()
{
    if (cargo.empty())
    {
        throw EmptyEx();
    }
    else
    {
        string ret = cargo;

        for (int i = 0; i < cargo.size(); i++)
        {
            ret += "\n" + cargo[i];
        }

        return ret;
    }
}

template <typename T>
double Plane<T>::calculateValue()
{
    if (cargo.empty())
    {
        throw EmptyEx();
    }
    else
    {
        // check if there is more than one smallest value
        T *leastVal, *secondLeast;
        leastVal = cargo; // smallest value
        double sum = 0;

        for (int i = 0; i < cargo.size(); i++)
        {
            if (leastVal->calculateValue() > cargo[i]->calculateValue())
            {
                leastVal = cargo[i];
                sum += cargo[i]->calculateValue;
            }

            for (int i = 0; i < cargo.size(); i++)
            {
                if (secondLeast->calculateValue() > cargo[i]->calculateValue() && leastVal != cargo[i])
                {
                    secondLeast = cargo[i];
                }
            }

            if (leastVal->calculateValue() * 0.5 < secondLeast->calculateValue)
            {
                throw UndervaluedEx<T>(leastVal, sum);
            }
        }

        return (sum + leastVal->calculateValue);
    }
}

template <>
double Plane<SecretCargo>::calculateValue()
{
    if (cargo.empty())
    {
        throw EmptyEx();
    }
    else
    {
        throw UnauthorisedEx();
    }
}

template <>
string Plane<SecretCargo>::getDescription()
{
    if (cargo.empty())
    {
        throw EmptyEx();
    }
    else
    {
        throw UnauthorisedEx();
    }
}

#endif 
