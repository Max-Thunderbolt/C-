#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include <cstddef>
#include "Operator.h"

template <class T>
class PlusOperator : public Operator<T>
{
public: 
    virtual T operator()(T lhs, T rhs);
    virtual Operator<T> *clone();
};

#endif
