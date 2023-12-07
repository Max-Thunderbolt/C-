#include "Node.h"

template <class T>
Node<T>::Node(T data)
{
    this->data = data; 
    this->next = NULL;
}

template <class T> 
T Node<T>::getData()
{
    return this->data;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return this->next;
}

template <class T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}