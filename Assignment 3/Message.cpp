#include "Message.h"

using namespace std;

Message::Message(string text)
{
    this->text = text; 
    this->next = NULL;
}

string Message::getText()
{
    return this->text;
}
