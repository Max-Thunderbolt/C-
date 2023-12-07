// This is the main file for the Sudoku game, here is where the game is played.
// #include "isValidSudoku.cpp"
// #include "sudokuSolver.cpp"
#include "printSudoku.h"
#include "createGame.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to Sudoku!" << endl;
    cout << "This is a 9x9 grid of numbers, with 3x3 boxes." << endl;
    cout << "The goal is to fill in the numbers 1-9 in each row, column, and box." << endl;
    cout << "You can enter a number by typing the row, column, and number." << endl;
    cout << "\t-- NOTE: The first row and column are 0, not 1 -- " << endl;
    cout << "\t- To exit the game, type 'exit'." << endl;
    cout << "\t- To see the solution, type 'solution'." << endl
         << endl;

    cout << "Select which game you want to play:" << endl;
    cout << "1.) " << endl;
    createGame g1;
    g1.createGame1();
    g1.deleteGame();
    cout << endl;
    cout << "2.) " << endl;
    createGame g2;
    g2.createGame2();
    g2.deleteGame();
    cout << endl;
    cout << "3.) " << endl;
    createGame g3;
    g3.createGame3();
    g3.deleteGame();
    cout << endl;

    cout << "Enter the number of the game you want to play: ";
    string gameChoice = "";
    cin >> gameChoice;
    bool playing = true;
    while (playing)
    {
        if (gameChoice == "1")
        {
            cout << "you chose game 1!" << endl;
            createGame g1;
            g1.createGame1();
            playing = false;
        }
        if (gameChoice == "2")
        {
            cout << "you chose game 2!" << endl;
        }
        if (gameChoice == "3")
        {
            cout << "you chose game 3!" << endl;
        }
        if (gameChoice == "exit")
        {
            cout << "Goodbye!" << endl;
            playing = false;
        }
    }

    return 0;
}