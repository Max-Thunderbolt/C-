// Exception implementations
#ifndef EXCEPTIONS_CPP
#define EXCEPTIONS_CPP

#include "Exceptions.h"

AboveWeightEx::AboveWeightEx(double wd)
{
    weightDiff = wd;
}

double AboveWeightEx::getDifference() const
{
    return weightDiff;
}

template <typename E>
UndervaluedEx<E>::UndervaluedEx(E *uv, double s)
{
    underVal = uv;
    sum = s;
}

template <typename E>
E *UndervaluedEx<E>::getUndervalued() const
{
    return underVal;
}

template <typename E>
double UndervaluedEx<E>::getSum() const
{
    return sum;
}

template <typename E>
NotFoundEx<E>::NotFoundEx(E *nf)
{
    missing = nf;
}

template <typename E>
E *NotFoundEx<E>::getNotFound() const
{
    return missing;
}

#endif
