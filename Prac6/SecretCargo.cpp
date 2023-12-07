//The SecretCargo implementation file
#include "SecretCargo.h"

SecretCargo::SecretCargo(double weight)
{ 
    this->weight = weight; 
}

double SecretCargo::getWeight() const
{ 
    return weight;
}