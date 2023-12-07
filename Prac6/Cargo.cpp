//The Cargo implementation file
#include "Cargo.h"

Cargo::Cargo(double weight, double ppw) //ppw --> per per weight
{ 
    this->weight = weight; 
    this->value = weight * ppw;
}

double Cargo::getWeight() const
{ 
    return weight;
}

double Cargo::getValue() const
{ 
    return value;
}

string Cargo::describe()
{ 
    string ret; 
    ret += "Generic cargo <"; 
    ret += getValue(); 
    ret += "> (";
    ret += getWeight(); 
    ret += ")";
    return ret;
}