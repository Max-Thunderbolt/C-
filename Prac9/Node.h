#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <class T>
class Node
{
private: 
    T data; // The data contained in the links of the list
    Node<T> *next; 

public: 
    Node(T data);
    T getData(); 
    Node<T> *getNext(); 
    void setNext(Node<T> *next);
};

#endif
