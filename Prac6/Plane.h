//The Plane class
#ifndef PLANE_H 
#define PLANE_H 

#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"
#include "Plane.cpp"

using namespace std;

//See spec on inclusion strategy for templates

template <typename T>
class Plane
{ 
private: 
    std::vector<T*> cargo;
    double maxWeight; 

public: 
    Plane(double);
    ~Plane();
    void add(T*);
    void remove(T*);
    std::string getDescription(); 
    double calculateValue();
};

#endif 
