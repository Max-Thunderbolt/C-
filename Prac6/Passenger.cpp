//The Passenger implementation file
#include "Passenger.h"

Passenger::Passenger(string ID, double weight, double ticketPrice)
{ 
    this->ID = ID; 
    this->weight = weight; 
    this->ticketPrice = ticketPrice;
}

double Passenger::getWeight() const
{ 
    return weight;
}

double Passenger::getValue() const
{ 
    return ticketPrice;
}

string Passenger::describe()
{ 
    string ret;
    ret += "ID";
    ret += ID;
    ret += " "; 
    ret += "<"; 
    ret += to_string(getValue());
    ret += "> ("; 
    ret += to_string(getWeight());
    ret += ")";

    return ret;
}