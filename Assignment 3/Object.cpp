#include "Object.h"

/*
! CHECK HEADER FILE FOR NOTES
*/

using namespace std;

Object::Object(int x, int y)
{
    this->xPos = x; 
    this->yPos = y;
    this->icon = '?';
    this->nextHoriz = NULL;
    this->nextVert = NULL;
    this->prevHoriz = NULL;
    this->prevVert = NULL;
    this->above = NULL;
    this->below = NULL;
}

char Object::getIcon()
{
    // TASK 1
    return this->icon;

    //! TASK 2
    // if (this->lit == true)
    // {
    //     return this->icon;
    // }
    // else
    // {
    //     return ' ';
    // }
}

int Object::getCoord(bool dimension)
{
    // false = x, true = y
    if (dimension == false)
    {
        return this->xPos;
    }
    else 
    {
        return this->yPos;
    }
}

Object *Object::getNext(bool dimension)
{
    // false = x, true = y
    if (dimension == false)
    {
        return this->nextHoriz;
    }
    else 
    {
        return this->nextVert;
    }
}

Object *Object::getPrev(bool dimension)
{
    // false = x, true = y
    if (dimension == false)
    {
        return this->prevHoriz;
    }
    else 
    {
        return this->prevVert;
    }
}

void Object::setNext(Object *obj, bool dim)
{
    // false = x, true = y
    if (dim == false)
    {
        this->nextHoriz = obj;
    }
    else 
    {
        this->nextVert = obj;
    }
}

void Object::setPrev(Object *obj, bool dim)
{
    // false = x, true = y
    if (dim == false)
    {
        this->prevHoriz = obj;
    }
    else 
    {
        this->prevVert = obj;
    }
}

//! TASK 2 
// void Object::update()
// {
//     this->lit = false;
// }

// bool Object::isSolid()
// {
//     if (this->above != NULL && this->above->solid == true) // if object above is solid
//     {
//         return true;
//     }
//     else if (this->above == NULL && this->solid == false) // If there is no object above and isn't solid
//     {
//         return false;
//     }
//     else if (this->above == NULL && this->solid == true) // If there is no object above and is solid
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void Object::updateLight(char direction, int intensity)
// {
//     /*
//     CHAR DIRECTION: 
//     ~~~~~~~~~~~~~~~
//     u = up 
//     d = down 
//     l = left 
//     r = right
//     */

   
// }
