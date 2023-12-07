#include "Event.h"

using namespace std;

Event::Event(long int start, long int end, int id, string type)
{ 
    this->start = start;
    this->end = end; 
    this->id = id;
    this->type = type; 
    this->next = NULL;
}

Event::~Event()
{
    //does nothing
}

ostream& operator<<(ostream& out, Event& event)
{ 
    out << event.type; 
    out << " ";
    out << unix_to_string(event.start);
    out << "->";
    out << unix_to_string(event.end);
    return out;
}
