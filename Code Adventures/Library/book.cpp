#include "book.h"

using namespace std; 

// Overloaded constructer, assigns the passed in values to the class variables
book::book(string Name, string Author, int ISBN, int NumCopies)
{
    this->title = Name;
    this->author = Author;
    this->ISBN = ISBN;
    this->numCopies = NumCopies;
    this->borrowed = false;
}

// This is the default constructor, sets every value to a default "empty" value
book::book()
{
    this->title = "";
    this->author = "";
    this->ISBN = 0;
    this->numCopies = 0;
    this->borrowed = false;
}

book::~book(){
    delete this;
}

void book::setTitle(string title)
{
    this->title = title;
}

string book::getTitle()
{
    return this->title;
}

void book::setAuthor(string author)
{
    this->author = author;
}

string book::getAuthor()
{
    return this->author;
}

void book::setISBN(int ISBN)
{
    this->ISBN = ISBN;
}

int book::getISBN()
{
    return this->ISBN;
}

void book::setNumCopies(int numCopies)
{
    this->numCopies = numCopies;
}   

int book::getNumCopies()
{
    return this->numCopies;
}

void book::printBook(){  
    cout << "Title: " << this-> title <<
    "\nAuthor: " << this->author <<
    "\nISBN: " << this->ISBN <<
    "\nNumber of copies: " << this->numCopies << endl;
}