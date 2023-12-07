#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

template <class T>
class SortNode;

template <class T>
class SortList
{

private:
    bool ascending;
    SortNode<T> *head;
    SortNode<T> *tail;

public:
    SortList(bool asc);
    void add(SortNode<T> *a);
    SortNode<T> *remove(T val);
    void setAsc(bool a);
    void sort();
    std::string print();
    SortNode<T> *getHead();
    string debug();
};

#include "SortList.cpp"

#endif
