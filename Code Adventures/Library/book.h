#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream> 

using namespace std;
class book{
    private:
        string title; 
        string author; 
        int ISBN;
        int numCopies;
        bool borrowed;
    public:
        book();
        book(string title, string author, int ISBN, int numCopies);
        ~book();
        void setTitle(string);
        string getTitle();
        void setAuthor(string);
        string getAuthor();
        void setISBN(int);
        int getISBN();
        void setNumCopies(int);
        int getNumCopies();
        void printBook();
       
};

#endif