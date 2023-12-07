#include "library.h"

void library::addBook(book b){
    this->books = new book[numBooks+1]; // creates a new array with one more space than the old array
    for(int i = 0; i < numBooks; i++){ // copies all the books from the old array to the new array
        this->books[i] = books[i];
    }
    this->books[numBooks] = b;
    this->numBooks++;
}

void library::addMember(member m){
    this->members = new member[numMembers+1];
    for(int i = 0; i < numMembers; i++){ 
        this->members[i] = members[i];
    }
    this->members[numMembers] = m;
    this->numMembers++;
}

// default constructor
library::library(){
    this->books = nullptr;
    this->members = nullptr;
    this->numBooks = 0;
    this->numMembers = 0;
}

// destructor
library::~library(){
    delete[] this->books;
    delete[] this->members;
}

void library::displayBooks(){
    for (int i = 0; i < numBooks; i++){
        books[i].printBook();
    }
}

void library::displayMembers(){
    for (int i = 0; i < numMembers; i++){
        members[i].printMemeber();
    }
}

void library::displayBook(int isbn){
    for (int i = 0; i < numBooks; i++){
        if (books[i].getISBN() == isbn){
            books[i].printBook();
        } else 
        {
            cout << "Book not found" << endl;
        }
    }
}

void library::displayMember(int membershipNumber){
    for (int i = 0; i < numMembers; i++){
        if (members[i].getMemebershipNumber() == membershipNumber){
            members[i].printMemeber();
        } else 
        {
            cout << "Member not found" << endl;
        }
    }
}

void library::deleteBook(int isbn){
    // This is a lazy method of removing a book. 
    // It copies all the books from the old array to the new array, except for the book that needs to be deleted.
    //! A revised version should see book objects as pointers, would actually deallocate memory, instead of "skipping over".
    for(int i = 0; i < numBooks; i++){
        if (books[i].getISBN() == isbn){
            for(int j = i; j < numBooks; j++){
                books[j] = books[j+1];
            }
            numBooks--;
        } else 
        {
            cout << "Book not found" << endl;

        }
    }
}

void library::deleteMember(int membershipNumber){
    for (int i = 0 ; i < numMembers; i++){
        if (members[i].getMemebershipNumber() == membershipNumber){
            for(int j = i; j < numMembers; j++){
                members[j] = members[j+1];
            }
            numMembers--;
        } else 
        {
            cout << "Member not found" << endl;
        }
    }
}

void library::borrowBook(int isbn, int membershipNumber){
    for (int i = 0; i < numBooks; i++){
        if (books[i].getISBN() == isbn && books[i].getNumCopies() > 0){
            for (int j = 0; j < numMembers; j++){
                if (members[j].getMemebershipNumber() == membershipNumber){
                    books[i].setNumCopies(books[i].getNumCopies() - 1);
                    cout << "Book borrowed" << endl;
                } else 
                {
                    cout << "Member not found" << endl;
                }
            }
        } else 
        {
            cout << "Book not found" << endl;
        }
    }
}

void library::returnBook(int isbn, int membershipNumber){
    for (int i = 0; i < numBooks; i++){
        if (books[i].getISBN() == isbn){
            for (int j = 0; j < numMembers; j++){
                if (members[j].getMemebershipNumber() == membershipNumber){
                    books[i].setNumCopies(books[i].getNumCopies() + 1);
                    cout << "Book returned" << endl;
                } else 
                {
                    cout << "Member not found" << endl;
                }
            }
        } else 
        {
            cout << "Book not found" << endl;
        }
    }
}

void library::displayBorrowedBooks(){
    //? what if there is only 1 book in the library?
    //? what if there is only 1 / 5 books borrowed?
    for (int i = 0; i < numBooks; i++){
        if (books[i].getNumCopies() == 0){
            books[i].printBook();
        }
    }
}

void library::displayBorrowedBooks(int membershipNumber){
    //? how would this even work?!?!
    for (int i = 0; i < numBooks; i++){
        if (books[i].getNumCopies() == 0){
            for (int j = 0; j < numMembers; j++){
                if (members[j].getMemebershipNumber() == membershipNumber){
                    books[i].printBook();
                } else 
                {
                    cout << "Member not found" << endl;
                }
            }
        }
    }
}

void library::displayAvailableBooks(){
    for (int i = 0; i < numBooks; i++){
        if (books[i].getNumCopies() > 0){
            books[i].printBook();
        }
    }
}