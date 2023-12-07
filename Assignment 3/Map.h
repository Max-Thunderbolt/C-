#ifndef MAP_H 
#define MAP_H

#include "ObjectList.h"
#include <string>

using namespace std;

class Map
{
private: 
    int width; 
    int height; 
    ObjectList **rows; 
    ObjectList **columns;

public: 
    Map(int width, int height);
    void add(Object *obj);
    string print(); 
    ~Map();
};

#endif
