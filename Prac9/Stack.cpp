#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    this->top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
    while (this->top != NULL)
    {
        Node<T> *temp = this->top;
        this->top = this->top->getNext();
        delete temp;
    }
}

template <class T>
void Stack<T>::push(T data)
{
    Node<T> *newNode = new Node<T>(data); // Create node at top of stack
    newNode->setNext(this->top);          // Set next node to the current top
    this->top = newNode;                  // Move top to new node
}

template <class T>
Node<T> *Stack<T>::pop()
{
    if (this->top == NULL) // Stack is empty
    {
        return NULL;
    }
    else // Stack is not empty
    {
        Node<T> *oldTop = this->top;
        this->top = this->top->getNext();
        return oldTop;
    }
}

template <class T>
Node<T> *Stack<T>::getTop()
{
    return this->top;
}

template <class T>
int Stack<T>::size()
{
    Node<T> *temp = this->top;
    int size = 0;
    if (this->top == NULL)
    {
        size = 0;
    }
    else
    {
        while (temp != NULL)
        {
            size++;
            temp = temp->getNext();
        }
    }
    return size;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if (this->top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
Stack<T> *Stack<T>::reverse()
{
    Stack<T> *newStack = new Stack<T>();
    Node<T> *oldTop = this->top;

    if (this->top == NULL) // Stack is empty
    {
        return newStack;
    }
    else
    {
        while (oldTop != NULL)
        {
            newStack->push(oldTop->getData());
            oldTop = oldTop->getNext();
        }
    }

    return newStack;
}

template <class T>
bool Stack<T>::contains(T data)
{
    Node<T> *ptr = this->top;
    bool ret;

    if (ptr == NULL) // Stack is empty
    {
        return false;
    }
    else
    {
        if (ptr->getData() == data) // Value is at the top
        {
            ret = true;
        }
        else
        {
            while (ptr != NULL)
            {
                if (ptr->getData() == data)
                {
                    ret = true;
                    break;
                }
                else
                {
                    ret = false;
                }
                ptr = ptr->getNext();
            }
        }
    }

    return ret;
}
