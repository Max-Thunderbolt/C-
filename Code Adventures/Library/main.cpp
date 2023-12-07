#include "book.h"
//#include "book.cpp"
#include "member.h"
//#include "member.cpp"
#include "library.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create a new book object
    book book1("The Hobbit", "J.R.R. Tolkien", 123456789, 5);
    // Create a new member object
    member member1("John Smith", "1234 Main St.", 123456789);

    cout << "Testing printBook() and printMember() functions" << endl;
    cout << "------------------------------------------------" << endl;
    // Print the book's information
    book1.printBook();

    
    // // Print the book's information
    // book1.printBook();
    // // Print the member's information
    // member1.printMemeber();
    
    // // Set the book's title to "The Lord of the Rings"
    // book1.setTitle("The Lord of the Rings");
    // // Set the member's name to "Jane Doe"
    // member1.setName("Jane Doe");
    
    // // Print the book's information
    // book1.printBook();
    // // Print the member's information
    // member1.printMemeber();
    
    return 0;
}