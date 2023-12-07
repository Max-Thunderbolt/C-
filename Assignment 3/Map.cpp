#include "Map.h"
#include <sstream>
#include <iostream>

using namespace std;

Map::Map(int w, int h)
{
    this->width = w; 
    this->height = h; 

    this->rows = new ObjectList*[h];
    this->columns = new ObjectList*[w];

    for (int i = 0; i < h; i++)
    {
        this->rows[i] = new ObjectList(1); // set to true for vertical (y)
    }

    for (int i = 0; i < w; i++)
    {
        this->columns[i] = new ObjectList(0); // set to false for horizontal (x)
    }
}

Map::~Map()
{
    for (int i = 0; i < this->height; i++)
    {
        delete this->rows[i];
    }

    for (int i = 0; i < this->width; i++)
    {
        delete this->columns[i];
    }

    delete[] this->rows;
    delete[] this->columns;
}

void Map::add(Object *obj)
{
    int x = obj->getCoord(0);
    int y = obj->getCoord(1);

    // cout << "x: " << x << " y: " << y << endl;
    // cout << "width: " << this->width << " height: " << this->height << endl;
    cout << "adding " << obj->getIcon() << " to map" << endl;

    this->rows[y]->add(obj);
    this->columns[x]->add(obj);
}

string Map::print()
{
    /*
    1.) Create a string stream
    2.) Iterate through the rows
    3.) Iterate through the columns
    4.) Add the icon to the string stream
    5.) Add a new line to the string stream
    6.) Return the string stream as a string
    */

    string ret;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            ObjectList *row = this->rows[i];
            ObjectList *column = this->columns[j];
            
   
            int x = column->getHead()->getCoord(0);
            int y = row->getHead()->getCoord(1);

            Object *currentRowIcon = row->getHead();
            Object *currentColumnIcon = column->getHead();
            cout << "x: " << x << " y: " << y << endl;
            cout << "currentRowIcon: " << currentRowIcon->getIcon() << endl;
            cout << "currentColumnIcon: " << currentColumnIcon->getIcon() << endl;
            ret += currentRowIcon->getIcon();
            ret += currentColumnIcon->getIcon();
            currentRowIcon = currentRowIcon->getNext(1);
            currentColumnIcon = currentColumnIcon->getNext(0);
            //ss << icon;
            
        }
        ret += "\n";
    }
    return ret;
}