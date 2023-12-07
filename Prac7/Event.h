#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "Utils.h"

using namespace std;

class Event
{
public: 
    long int start, end;
    int id; 
    string type; 
    Event* next; 

    Event(long int start, long int end, int id, string type);
    ~Event(); //does nothing 
    friend ostream& operator<<(ostream& os, Event& event);
};


#endif // EVENT_H