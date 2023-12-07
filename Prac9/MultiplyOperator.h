#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H

#include <cstddef>
#include "Operator.h"

template <class T>
class MultiplyOperator : public Operator<T>
{
public: 
    virtual T operator()(T lhs, T rhs);
    virtual Operator<T> *clone();
};

#endif
