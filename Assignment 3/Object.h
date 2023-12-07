#ifndef OBJECT_H
#define OBJECT_H

#include <sstream>


/*
NOTES: 
- Remeber to comment out all task 2 code before debugging task 1
- Remember to uncomment all task 2 code before debugging task 2
- Task 2 functions are commented in //!RED
*/

class Object
{
protected:
    char icon; //a character that represents the object
    int xPos; //x position of the object
    int yPos; //y position of the object

    //! Task 2 Members
    // bool solid; // If object is solid. i.e can't move through it
    // bool lit; // is the object lit

public:
    // MEMBERS (TASK!):
    Object *nextHoriz; // Link to the object to the right
    Object *prevHoriz; // Link to the object to the left

    Object *nextVert; // Link to the object below
    Object *prevVert; // Link to the object above (y - 1)

    Object *above; // A link to the object on top of current object. (have same x & y)
    Object *below; // A link to the object below current object. (have same x & y)

    // FUNCTIONS:
    Object(int x, int y);
    char getIcon();
    int getCoord(bool dimension);
    Object *getNext(bool dimension);
    Object *getPrev(bool dimension);
    void setNext(Object *obj, bool dim);
    void setPrev(Object *obj, bool dim);

    //! TASK 2 FUNCTIONS 
    // virtual void update(); 
    // bool isSolid(); 
    // virtual void updateLight(char direction, int intensity);
    //virtual void interact();
};

#endif

