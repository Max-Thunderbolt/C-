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

    if (this->head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template <class T>
SortNode<T> *SortList<T>::remove(T val)
{
    SortNode<T> *curr = NULL;

    if (head != NULL)
    {
        curr = head;

        while (curr != NULL && curr->getValue() != val)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            if (curr-> prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                curr = curr->next;
            }
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            else
            {
                tail = curr->prev;
            }
        }
    }
    return curr;
}

template <class T>
void SortList<T>::setAsc(bool asc)
{
    if (asc == true)
    {
        ascending = true;
        sort();
    }
    else
    {
        ascending = false;
        sort();
    }
}

template <class T>
void SortList<T>::sort()
{
    if (head != NULL && head->next != NULL)
    {
        SortNode<T> *curr = head;
        SortNode<T> *prev = NULL;
        int numNodes = 0;
        while (curr != NULL)
        {
            curr = curr->next;
            numNodes++;
        }
        if (ascending == true)
        {
            for (int i = 0; i < numNodes; i++)
            {
                curr = head->next;
                prev = head;
                for (int j = 0; j < numNodes - i - 1; j++)
                {
                    if (prev->getValue() > curr->getValue())
                    {
                        if (curr->next != NULL)
                        {
                            curr->next->prev = prev;
                            prev->next = curr->next;
                        }
                        else
                        {
                            tail = prev;
                            prev->next = NULL;
                        }
                        curr->next = prev;
                        if (prev->prev == NULL)
                        {
                            head = curr;
                            curr->prev = NULL;
                        }
                        else
                        {
                            prev->prev->next = curr;
                            curr->prev = prev->prev;
                        }
                        prev->prev = curr;
                        curr = prev->next;
                    }
                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < numNodes; i++)
            {
                curr = head->next;
                prev = head;
                for (int j = 0; j < numNodes - i - 1; j++)
                {
                    if (prev->getValue() <= curr->getValue())
                    {
                        if (curr->next != NULL)
                        {
                            curr->next->prev = prev;
                            prev->next = curr->next;
                        }
                        else
                        {
                            tail = prev;
                            prev->next = NULL;
                        }
                        curr->next = prev;
                        if (prev->prev == NULL)
                        {
                            head = curr;
                            curr->prev = NULL;
                        }
                        else
                        {
                            prev->prev->next = curr;
                            curr->prev = prev->prev;
                        }
                        prev->prev = curr;
                        curr = prev->next;
                    }
                    else
                    {
                        prev = curr;
                        curr = curr->next;
                    }
                }
            }
        }
    }
}

template <class T>
string SortList<T>::print()
{
    stringstream ss;
    SortNode<T> *temp = head;

    while (temp != NULL)
    {
        if (temp == tail)
        {
            ss << temp->print();
        }
        else
        {
            ss << temp->print() << ",";
        }
        temp = temp->next;
    }
    return ss.str();
}

template <class T>
SortNode<T> *SortList<T>::getHead()
{
    return head;
}
