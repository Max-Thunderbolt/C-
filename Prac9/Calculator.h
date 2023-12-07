#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Stack.h"
#include "Operator.h"
#include "Node.h"

template <class T>
class Calculator
{
private: 
    Stack<T> *valueStack; 
    Stack<Operator<T> *> *operatorStack;

public: 
    Calculator(); 
    ~Calculator(); 
    void addValue(T val); 
    void addOperator(Operator<T> *op);
    T removeValue(); 
    Operator<T> *removeOperator();
    int numValues(); 
    int numOperators(); 
    T calculate();
};

#endif
