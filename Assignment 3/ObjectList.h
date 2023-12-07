#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "Object.h"
#include <string>

using namespace std;

class ObjectList
{
private:
    bool dimension; // which dimension to use
    Object *head; // Head of the list
    Object *current; // The current object during iteration

public:
    ObjectList(bool dim);
    void add(Object *obj); //! massive headache
    Object *getHead();
    string print();
    void reset();
    Object *iterate();
    string debug();
};

#endif