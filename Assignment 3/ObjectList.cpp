#include "ObjectList.h"

using namespace std;

ObjectList::ObjectList(bool dim)
{
    this->dimension = dim;
    this->head = NULL;
    this->current = NULL;
}

void ObjectList::add(Object *obj)
{
    if (this->head == NULL) // The list is empty
    {
        // Set the head && current to the new object
        this->head = obj;
        this->current = obj;

        // Set the next and prev to NULL
        if (this->dimension == false)
        {
            obj->nextHoriz = NULL;
            obj->prevHoriz = NULL;
        }
        else
        {
            obj->nextVert = NULL;
            obj->prevVert = NULL;
        }
    }
    else
    {
        Object *ptr = this->head;                 //? Ptr is a pointer to search for the end of the list
        Object *prevPtr = NULL;                   //? Pointer that points to the previous object
        int pos = obj->getCoord(this->dimension); //? Stores what position the object is in (x or y)
        int prevObjectPos = 0;                    //? Stores the position of the object that ptr is pointing to

        while (ptr->getNext(this->dimension) != NULL) // while there are still objects in the list of this dimension
        {
            prevPtr = ptr;                                  // set the previous pointer to the current pointer
            prevObjectPos = ptr->getCoord(this->dimension); // get the position of the current object
            ptr = ptr->getNext(this->dimension);            // Move the pointer to the next object in the list

            if (pos < prevObjectPos && pos < ptr->getCoord(this->dimension)) // if the position of the new object is less than the previous object and less than the next object
            {
                // Set the new object's next and prev to the current object and the previous object
                if (this->dimension == false)
                {
                    obj->nextHoriz = ptr;
                    obj->prevHoriz = prevPtr;
                }
                else
                {
                    obj->nextVert = ptr;
                    obj->prevVert = prevPtr;
                }

                // Set the previous object's next to the new object
                if (this->dimension == false)
                {
                    prevPtr->nextHoriz = obj;
                }
                else
                {
                    prevPtr->nextVert = obj;
                }

                // Set the next object's prev to the new object
                if (this->dimension == false)
                {
                    ptr->prevHoriz = obj;
                }
                else
                {
                    ptr->prevVert = obj;
                }
            }
            else if (pos == prevObjectPos) // if the position of the new object is the same as the previous object
            {
                // Set the new object's above and below to the current object and the previous object
                ptr->above = obj;
                obj->below = ptr;

                // Set the previous object's below to the new object
                prevPtr->below = obj;

                // Set the next object's above to the new object
                ptr->above = obj;
            }
        }

        if (pos > prevObjectPos) // If the position of the new object is greater than the position of the last object in the list
        {
            ptr->setNext(obj, this->dimension); // Set the next object of the last object in the list to the new object
            obj->setPrev(ptr, this->dimension); // Set the previous object of the new object to the last object in the list
        }
        else if (pos < prevObjectPos) // If the position of the new object is less than the position of the last object in the list
        {
            if (prevPtr == NULL) // Check if the previous object is NULL
            {
                obj->setNext(ptr, this->dimension); // Set the next object of the new object to the first object in the list
                ptr->setPrev(obj, this->dimension); // Set the previous object of the first object in the list to the new object
                this->head = obj;                   // Set the head of the list to the new object
            }
            else // If the previous object is not NULL
            {
                obj->setNext(ptr, this->dimension);     // Set the next object of the new object to the current object
                obj->setPrev(prevPtr, this->dimension); // Set the previous object of the new object to the previous object
                prevPtr->setNext(obj, this->dimension); // Set the next object of the previous object to the new object
                ptr->setPrev(obj, this->dimension);     // Set the previous object of the current object to the new object
            }
        }
        else // If the position of the new object is equal to the position of the last object in the list
        {
            ptr->above = obj; // Set the above object of the last object in the list to the new object
            obj->below = ptr; // Set the below object of the new object to the last object in the list
        }
    }
}

Object *ObjectList::getHead()
{
    return this->head;
}

string ObjectList::print()
{
    string output = "";
    Object *ptr = this->head;

    while (ptr != NULL)
    {
        output += ptr->getIcon();
        ptr = ptr->getNext(this->dimension);
    }

    return output;
}

void ObjectList::reset()
{
    this->current = this->head;
}

Object *ObjectList::iterate()
{
    Object *ptr = this->current;

    if (ptr != NULL)
    {
        this->current = ptr->getNext(this->dimension);
    }

    return ptr;
}

string ObjectList::debug()
{
    string output = "Forward: \n";
    Object *ptr = this->head;

    while (ptr)
    {
        char top;
        if (ptr->above == NULL)
        {
            top = 'Y';
        }
        else
        {
            top = 'N';
        }
        char icon = ptr->getIcon();

        output += "<";
        output += icon;
        output += "> at (" + to_string(ptr->getCoord(0)) + ", " + to_string(ptr->getCoord(1)) + ") Top:" + top + "\n";
        ptr = ptr->getNext(0);
    }
    return output;
}