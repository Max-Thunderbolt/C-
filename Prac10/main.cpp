#include <iostream>
#include <string>

#include "Exception.h"
#include "Disk.cpp"
#include "TowersOfHanoi.cpp"
#include "IterativeSolution.cpp"
#include "RecursiveSolution.cpp"

using namespace std;

void ISTest()
{
    cout << "Iterative Solution Test" << endl;
    cout << "-----------------------" << endl << endl;

    cout << "Creating Iterative Solution for odd number of disks..." << endl;
    IterativeSolution<int> IS = IterativeSolution<int>(1,3);
    cout << "Iterative Solution Created" << endl << endl;

    cout << "Adding disks to Iterative Solution..." << endl;
    IS.addDisk(3,1);
    IS.addDisk(2,1);
    IS.addDisk(1,1);

    cout << "Disks added to Iterative Solution" << endl << endl;

    cout << "Checking if game is valid before attempting to solve..." << endl;
    if (IS.validateGame())
    {
        cout << "game is valid: " << IS.validateGame() <<endl << endl;
    }
    else 
    {
        cout << "game is invalid: " << IS.validateGame() <<endl << endl;
    }

    cout << "Solving Iterative Solution..." << endl;
    IS.solveGame();
    cout << "Iterative Solution solved" << endl << endl;

    cout << "Testing iterative solution with even number of disks..." << endl;
    IterativeSolution<int> IS2 = IterativeSolution<int>(1,3);
    IS2.addDisk(4,1);
    IS2.addDisk(3,1);
    IS2.addDisk(2,1);
    IS2.addDisk(1,1);

    cout << "Checking if game is valid before attempting to solve..." << endl;
    if (IS2.validateGame())
    {
        cout << "game is valid: " << IS2.validateGame() <<endl << endl;
    }
    else 
    {
        cout << "game is invalid: " << IS2.validateGame() <<endl << endl;
    }

    cout << "Solving Iterative Solution..." << endl;
    IS2.solveGame();
    cout << "Iterative Solution solved" << endl << endl;

    IterativeSolution<int> ISIS = IterativeSolution<int>(1,3);
    ISIS.addDisk(3,1);
    ISIS.addDisk(2,1);
    ISIS.addDisk(1,1);

    cout << "Testing Iterative Solution moves()" << endl;
    cout << "First move: ";
    ISIS.moves(1);
    cout << endl; 
 
    cout << "Edge cases: " << endl;

    IterativeSolution<int> e1 = IterativeSolution<int>(1,4);
    IterativeSolution<int> e2 = IterativeSolution<int>(0,3);
    IterativeSolution<int> e3 = IterativeSolution<int>(1,1);
    IterativeSolution<int> e4 = IterativeSolution<int>(1,3);

    e4.addDisk(1,1);
    e4.addDisk(2,1);
    e4.addDisk(3,1);
    e4.validateGame();
    e4.solveGame();


    cout << "Code works as intended." << endl << endl;

}

void RSTest()
{
    cout << "Recursive Solution Test" << endl;
    cout << "-----------------------" << endl << endl;

    cout << "Creating Recursive Solution..." << endl;
    RecursiveSolution<int> RS = RecursiveSolution<int>(1,3);
    cout << "Recursive Solution Created" << endl << endl;

    cout << "Adding disks to Recursive Solution..." << endl;
    RS.addDisk(5,1);
    RS.addDisk(4,1);
    RS.addDisk(3,1);
    RS.addDisk(2,1);
    RS.addDisk(1,1);
    //cout << "number of disks in RS: " << RS.count() << endl;
    cout << "Disks added to Recursive Solution" << endl << endl;

    cout << "Solving Recursive Solution..." << endl;
    RS.solveGame();
    cout << "Recursive Solution solved" << endl << endl;

    cout << "Testing Recursive Solution count()" << endl;
    RecursiveSolution<int> RS2 = RecursiveSolution<int>(1,3);
    RS2.addDisk(5,1);
    RS2.addDisk(4,1);
    RS2.addDisk(3,1);
    RS2.addDisk(2,1);
    RS2.addDisk(1,1);
    RS2.moveDisk(1,2); // disk 1 to tower 2
    RS2.moveDisk(1,3); // disk 2 to tower 3

    cout << "Number of disks: " << RS2.count() << endl;
    cout << "Making sure disks were added back: " << RS2.count() << endl << endl; 

    cout << "Testing contains()" << endl;
    cout << "Contains disk 1: " << RS.contains(1) << endl;
    cout << "Contains disk 2: " << RS.contains(2) << endl;
    cout << "Contains disk 3: " << RS.contains(3) << endl;
    cout << "Contains disk 4: " << RS.contains(4) << endl;
    cout << "Contains disk 5: " << RS.contains(5) << endl << endl;

    cout << RS.count() << endl;

    // cout << "Edge cases: " << endl;
    // cout << "Will be added later." << endl;

    // cout << "Code works as intended." << endl << endl;
}

int main()
{
    //ISTest();
    RSTest();

    return 0;
}