// The Controller implementation file
#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include "Controller.h"
#include "Exceptions.h"
#include "Plane.h"
#include <iostream>

using namespace std;

template <typename T>
Controller<T>::Controller(Plane<T> *plane)
{
    this->plane = plane;
}

template <typename T>
string Controller<T>::loadOnPlane(T *t)
{

    try
    {
        plane->add(t);
        return "Sucess";
    }
    catch(AboveWeightEx &e){
        return "Could not load item, above max weight by " + to_string(e.getDifference());
    }
    return 0;
}

template <typename T>
double Controller<T>::getTotalValue()
{
    double val;
    try
    {
        if (plane->empty())
        {
           return 0;
        }
        val = plane->calculateValue();
    }

    catch (exception &e)
    {
    }

    catch(UndervaluedEx<T> &e){
        e.remove(e.getUndervalued());
        val = e.calculateValue();
        return val;
    }

    catch(UnauthorisedEx &e){
        return 0;
    }

    return val;
}

template <typename T>
string Controller<T>::getPlaneContents()
{
    string description;

    try
    {
        description = plane->getDescription();
    }

    catch (exception &e)
    {
    }
    
    catch(EmptyEx e){
        return "Nothing to report";
    }
    catch(UnauthorisedEx e){
        return "Not permitted";
    }

    return description;

}

#endif
