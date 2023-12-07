#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

using namespace std;
class member{
    private:
        string name; 
        string address; 
        int membershipNumber;
    public: 
        member();
        member(string name , string address , int membershipNumber);
        ~member();
        void setName(string);
        string getName();
        void setAddress(string);
        string getAddress();
        void setMemebershipNumber(int);
        int getMemebershipNumber();
        void printMemeber();
};

#endif