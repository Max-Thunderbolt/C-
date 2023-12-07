#include "member.h"

using namespace std; 

// Overloaded constructer, assigns the passed in values to the class variables
member::member(string Name, string Address, int MembershipNumber)
{
    this->name = Name;
    this->address = Address;
    this->membershipNumber = MembershipNumber;
}

// This is the default constructor, sets every value to a default "empty" value
member::member()
{
    this->name = "";
    this->address = "";
    this->membershipNumber = 0;
}

member::~member(){
    delete this;
}

void member::setName(string name)
{
    this->name = name;
}

string member::getName()
{
    return this->name;
}

void member::setAddress(string address)
{
    this->address = address;
}

string member::getAddress()
{
    return this->address;
}

void member::setMemebershipNumber(int membershipNumber)
{
    this->membershipNumber = membershipNumber;
}

int member::getMemebershipNumber()
{
    return this->membershipNumber;
}

void member::printMemeber()
{
    cout << "Name: " << this->name <<
    "\nAddress: " << this->address << 
    "\nMembership Number: " << this->membershipNumber << endl;
}

