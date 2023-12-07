#ifndef MINUSOPERATOR_H
#define MINUSOPERATOR_H

#include <cstddef>
#include "Operator.h"

template <class T>
class MinusOperator : public Operator<T>
{
public: 
    virtual T operator()(T lhs, T rhs);
    virtual Operator<T> *clone();
};

#endif
