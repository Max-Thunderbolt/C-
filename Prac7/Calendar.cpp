#include "Calendar.h"

using namespace std;

Calendar::Calendar()
{
    this->head = NULL;
}

template <class event_data>
Calendar::Calendar(vector<event_data> input)
{
    this->head = NULL;
    for (int i = 0; i < input.size(); i++)
    {
        this->createEvent(input[i]);
    }
}

Calendar::~Calendar()
{
    clearCalendar();
}

Event *Calendar::getUpcommingEvent(long int now)
{
    Event *ret;
    if (head->start == NULL)
    {
        return NULL;
    }
    else
    {
        while (head->start != NULL)
        {
            if (head->start == now)
            {
                ret = head;
            }
            else if (head->start == now && head->next == NULL)
            {
                ret = NULL;
            }
            head = head->next;
        }
    }

    return ret;
}

template <class Event>
vector<Event> Calendar::filterEvents(int *id, long int *start, long int *end, string *type)
{
    vector<Event> output;
    Event *temp = head;
    Event *tempEvent = new Event(id, start, end, type);

    int x = 0;

    while (temp != NULL)
    {

        if (tempEvent->id != NULL)
        {
            x = 0;
        }
        else if (tempEvent->start != NULL)
        {
            x = 1;
        }
        else if (tempEvent->end != NULL)
        {
            x = 2;
        }
        else if (tempEvent->type != NULL)
        {
            x = 3;
        }

        switch (x)
        {

        case 0:
            if (temp->id == *id)
            {
                output.push_back(temp);
            }
            break;

        case 1:
            if (temp->start == *start)
            {
                output.push_back(temp);
            }
            break;

        case 2:
            if (temp->end == *end)
            {
                output.push_back(temp);
            }
            break;

        case 3:
            if (temp->type == *type)
            {
                output.push_back(temp);
            }
            break;

        default:
            for (long int *i = 0; i < end; i++)
            {
                output.push_back(temp[i]);
                return output;
            }
        }
        return output;
    }
}

void Calendar::alterEvent(int id, long int *end, string *type)
{
    while (head != NULL)
    {
        if (head->id != id)
        {
            head = head->next;
        }
        else if (head->id == id)
        {
            if (end != NULL && type != NULL)
            {
                head->end = *end;
                head->type = *type;
            }
        }
    }
}

void Calendar::removeEvent(int id)
{
    Event *temp = head;
    Event *prev = NULL;

    while (head != NULL)
    {
        if (temp->id != id)
        {
            prev = head;
            temp = head->next;
        }
        else if (temp->id == id)
        {
            if (prev == NULL)
            {
                head = head->next;
                delete temp;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
            }
        }
    }
}

void Calendar::createEvent(event_data data)
{
    Event *temp = new Event(data.start, data.end, data.id, data.type);
    Event *prev = NULL;
    Event *curr = head;

    while (curr != NULL)
    {
        if (curr == NULL) // there is no linked list
        {
            break;
        }
        else
        {
            while (temp->start != curr->start) // while curr is reaching where event is
            {
                prev = curr;
                curr = head->next;

                if (curr->start == temp->start)
                {
                    if (curr->id != NULL) // there is already an event with same start
                    {
                        curr = curr->next; // move to next item
                        curr = temp;       // add event after previous event
                    }
                    if (curr->id != temp->id) // there is no event with same start
                    {
                        curr = temp;
                    }
                }
            }
        }
    }
}

void Calendar::clearCalendar()
{
    Event *temp = head;
    Event *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

Event *Calendar::getFirstEvent()
{
    return head;
}

ostream &operator<<(ostream &out, Calendar &calendar)
{
    Event *temp = calendar.head;
    long int counter = 0;
    while (temp != NULL)
    {
        out << counter << temp->type << " " << temp->start << "->" << temp->end << endl;
        temp = temp->next;
        counter++;
    }

    return out;
}
