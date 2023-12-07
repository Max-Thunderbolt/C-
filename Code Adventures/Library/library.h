#ifndef LIBRARY_H 
#define LIBRARY_H

#include <iostream>
#include "book.h"
#include "member.h"


using namespace std; 

class library{
    private:
        book *books; // array to keep track of all the books in the library
        member *members; // array to keep track of all the members in the library
        int numBooks; // keeps track of the number of books in the library
        int numMembers; // keeps track of the number of members in the library
    public: 
        library(); // constructor
        ~library(); // destructor
        void addBook(book); // adds a book to the library
        void addMember(member); // adds a member to the library
        void displayBooks(); // displays all the books in the library
        void displayMembers(); // displays all the members in the library
        void displayBook(int); // displays a specific book in the library using isbn
        void displayMember(int); // displays a specific member in the library using membership number
        void deleteBook(int); // deletes a specific book in the library using isbn
        void deleteMember(int); // deletes a specific member in the library using membership number
        void borrowBook(int, int); // borrows a specific book in the library using isbn and membership number
        void returnBook(int, int); // returns a specific book in the library using isbn and membership number
        void displayBorrowedBooks(); // displays all the books that are currently borrowed
        void displayBorrowedBooks(int); // displays all the books that are currently borrowed by a specific member
        void displayAvailableBooks(); // displays all the books that are currently available
};

#endif