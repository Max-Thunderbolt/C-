#ifndef CALENDAR_H
#define CALENDAR_H

#include "Event.h"
#include <vector>

using namespace std;

class Calendar
{
private: 
    Event *head;

public: 
    Calendar(); 
    template<typename event_data>
    Calendar(vector<event_data> input);
    ~Calendar();
    Event* getUpcommingEvent(long int now);
    template<typename Event>
    vector<Event> filterEvents(int *id, long int *start, long int *end, string *type);
    void alterEvent(int id, long int *end, string *type);
    void removeEvent(int id);
    void createEvent(event_data data);
    void clearCalendar(); 
    Event* getFirstEvent();
    friend ostream& operator<<(ostream& out, Calendar& calendar);
};

#endif // CALENDAR_H