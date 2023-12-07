#include "Disk.h"

template<class T>
Disk<T>::Disk(T label)
{
    this->label = label; // sets the label of the disk to the label passed in
}

template<class T>
T Disk<T>::getLabel() const
{
    return this->label;
}