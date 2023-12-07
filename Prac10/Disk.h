#ifndef DISK_H
#define DISK_H

template <class T>
class Disk
{
private: 
    T label; // label of the disk

public: 
    Disk(T label); 
    T getLabel() const; 
};

#endif
