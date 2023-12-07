#include "chesspiece.h"

#include <iostream>
#include <string> 

using namespace std;

Chesspiece::Chesspiece()
{
    name = "";
    int temp;
    temp = numberOfPieces; 
    temp++; 
    numberOfPieces = temp;
}

Chesspiece::Chesspiece(Chesspiece &obj)
{
    double temp; 
    this->name = obj.getName(); 
    this->type = obj.getType();
    numberOfPieces = obj.getNumberOfPieces();
    temp = numberOfPieces;
    temp++;
    this->numberOfPieces = temp; 
}

Chesspiece::Chesspiece(string in_name)
{
    this->name = in_name;
    this->numberOfPieces = this->numberOfPieces + 1;
}

Chesspiece::~Chesspiece()
{
    this->numberOfPieces = this->numberOfPieces - 1;
}

string Chesspiece::getName() const
{
    return this->name;
}

bool Chesspiece::getType() const
{
    return this->type;
}

int Chesspiece::getNumberOfPieces() const
{
    return this->numberOfPieces;
}

Chesspiece::Chesspiece(string in_name, bool in_type)
{
    this->name = in_name;
    this->type = in_type;
}