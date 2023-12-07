#include "Calculator.h"
#include "Operator.h"
#include "Stack.h"
#include "Node.h"

#include <cstddef>

template <class T>
Calculator<T>::Calculator()
{
    this->valueStack = new Stack<T>();
    this->operatorStack = new Stack<Operator<T> *>();
}

template <class T>
Calculator<T>::~Calculator()
{
    delete this->valueStack;
    delete this->operatorStack;
}

template <class T>
void Calculator<T>::addValue(T val)
{
    this->valueStack->push(val);
}

template <class T>
void Calculator<T>::addOperator(Operator<T> *op)
{
    Operator<T> *temp = op;
    this->operatorStack->push(temp);
}

template <class T>
T Calculator<T>::removeValue()
{
    Node<T> *removeVal = valueStack->getTop();
    if (removeVal == NULL)
    {
        return 0; // should return NULL
    }
    else
    {
        valueStack->pop();
        return removeVal->getData();
    }
}

template <class T>
Operator<T> *Calculator<T>::removeOperator()
{
    Node<Operator<T> *> *removeOP = operatorStack->getTop();
    if (removeOP == NULL)
    {
        return 0; // should return NULL
    }
    else
    {
        operatorStack->pop();
        return removeOP->getData();
    }
}

template <class T>
int Calculator<T>::numValues()
{
    return this->valueStack->size();
}

template <class T>
int Calculator<T>::numOperators()
{
    return this->operatorStack->size();
}

template <class T>
T Calculator<T>::calculate()
{
    /**************************************************************************
      Example table:
      |Value Stack | Operator Stack |
      -------------------------------
      |1           |                |
      |2           | +              |
      |3           | -              |
      -------------------------------

     result = (1 + 2) - 3 = 0
    **************************************************************************/
    T result = 0;
    T lhs, rhs = 0;

    if (numValues() >= 2) // check that there are values for operator
    {
        while (!operatorStack->isEmpty())
        {
            if (numOperators() >= 1) // check that there is an operator to use
            {
                Operator<T> *op = removeOperator();
                lhs = removeValue();
                rhs = removeValue();
                result = op->operator()(lhs, rhs);
                addValue(result);
            }
        }
    }
    else 
    {
        return 0; 
    }

    return result;
}