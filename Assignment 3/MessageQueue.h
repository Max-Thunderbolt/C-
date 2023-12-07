#ifndef MESSAGEQUEUE_H 
#define MESSAGEQUEUE_H

#include "Message.h"
#include <string>

using namespace std; 

class MessageQueue
{
    private: 
        int timeout; // the timeout each message lasts
        int current; // current timer of the timeout
        Message *head;
        Message *tail;

    public:
        MessageQueue(int timeout);
        void addMessage(Message *msg);
        string print();
        ~MessageQueue();
};

#endif
