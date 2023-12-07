// File for all exception definitions
// See spec for inclusion strategy
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Exceptions.cpp"
#include <sstream>

class AboveWeightEx
{
private:
    double weightDiff;

public:
    AboveWeightEx(double);
    double getDifference() const;
};

//template<typename E>
class EmptyEx
{
};

template <typename E>
class NotFoundEx
{
private:
    E missing;

public:
    NotFoundEx(E *);
    E *getNotFound() const;
};

template <typename E>
class UndervaluedEx
{
private:
    E *underVal;
    double sum;

public:
    UndervaluedEx(E *, double);
    E *getUndervalued() const;
    double getSum() const;
};

class UnauthorisedEx
{
};

#endif 
