#include <iostream>
using namespace std;

template <class T>
SortList<T>::SortList(bool asc)
{
    this->ascending = asc;
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
void SortList<T>::add(SortNode<T> *node)
{
    node->next = NULL;
    node->prev = NULL;

    if (head == NULL)
    {
        head = node;
        tail = head;
    }
    else
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
}

template <class T>
SortNode<T> *SortList<T>::remove(T val)
{
    // SortNode<T> *nodePtr = head;
    // SortNode<T> *prevNode = NULL;
    // if (head)
    // {
    //     while (nodePtr && nodePtr->getValue() != val)
    //     {
    //         prevNode = nodePtr;
    //         nodePtr = nodePtr->next;
    //     }
    //     if (nodePtr)
    //     {
    //         if (nodePtr == head)
    //         {
    //             head = head->next;
    //         }
    //         else
    //         {
    //             prevNode->next = nodePtr->next;
    //             return (nodePtr);
    //         }
    //     }
    // }

    // return (nodePtr);
    SortNode<T> *curr = head;
    SortNode<T> *prevNode = NULL;
    if (head)
    {
        while (curr && curr->getValue() != val)
        {
            prevNode = curr;
            curr = curr->next;
        }
        if (curr)
        {
            if (curr == head)
            {
                head = head->next;
            }
            else
            {
                prevNode->next = curr->next;
                return (curr);
            }
        }
    }

    return (curr);
}

template <class T>
void SortList<T>::sort()
{
    SortNode<T> *curr = head;
    SortNode<T> *next = NULL;
    SortNode<T> *prev = NULL;
    SortNode<T> *temp = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        prev = curr->prev;
        temp = curr;

        while (prev != NULL && (ascending ? prev->getValue() > temp->getValue() : prev->getValue() < temp->getValue()))
        {
            if (prev->prev == NULL)
            {
                head = temp;
            }
            else
            {
                prev->prev->next = temp;
            }
            temp->prev = prev->prev;
            prev->prev = temp;
            prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = prev;
            }
            else
            {
                tail = prev;
            }
            temp->next = prev;
            prev = temp->prev;
        }
        curr = next;
    }
}

template <class T>
string SortList<T>::print()
{
    stringstream ss;
    SortNode<T> *temp = head;
    if (head == NULL)
    {
        ss << "";
        return ss.str();
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                ss << temp->getValue();
            }
            else
            {
                ss << temp->getValue() << ",";
            }
            temp = temp->next;
        }
    }
    return ss.str();
}

template <class T>
SortNode<T> *SortList<T>::getHead()
{
    return head;
}

template <class T>
void SortList<T>::setAsc(bool asc)
{
    SortNode<T> *curr = head;
    SortNode<T> *prev = NULL, *next = NULL;

    this->ascending = asc; 

    if (ascending == false)
    {
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
}

template <class T>
string SortList<T>::debug()
{
    stringstream ss;
    SortNode<T> *temp = head;
    while (temp != NULL)
    {
        ss << temp->print() << " ";
        temp = temp->next;
    }
    ss << endl;
    temp = tail;
    while (temp != NULL)
    {
        ss << temp->print() << " ";
        temp = temp->prev;
    }
    return ss.str();
}