#include "MessageQueue.h"

using namespace std;

MessageQueue::MessageQueue(int timeout)
{
    this->timeout = timeout;
    this->current = this->timeout;
    this->head = NULL;
    this->tail = NULL;
}

MessageQueue::~MessageQueue()
{
    Message *temp = this->head;
    while (temp)
    {
        Message *next = temp->next;
        delete temp;
        temp = next;
    }
}

void MessageQueue::addMessage(Message *msg)
{
    if (this->head == NULL)
    {
        this->head = msg;
        this->tail = msg;
    }
    else
    {
        this->tail->next = msg; // not sure about this one
        this->tail = msg;
    }
}

string MessageQueue::print()
{
    Message *ptr = this->head;
    string output = "";
    while (ptr)
    {
        while (this->current > 0)
        {
            this->current--; 
            output += ptr->getText() + "\n";
            ptr = ptr->next;
        }
        this->current = this->timeout;
        Message *headMsg = this->head; 
        this->head = this->head->next;
        delete headMsg;
    }
    return output;
}
