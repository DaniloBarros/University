// tester.C for connect4

#include <iostream>
#include<stdlib.h>
#include<string.h>
#include "connect4.h"
#include<time.h>

using namespace std;

#define PLAYER1 'X'
#define PLAYER2 '0'

void copyConstruct();
void pause();
void think();
void AIchallenge();

int main()
{
    cout << "What would you like to test?\n";
    cout << "<C>opy constructor.\n";
    cout << "<T>hink.\n";
    cout << "<R>ecursive v. Iterative.\n";
    cout << " : ";
    
    char response;
    
    cin >> response;
    
    switch(response) {
        case 'c':
        case 'C':
            copyConstruct();
            break;
        case 't':
        case 'T':
            think();
            break;
        case 'r':
        case 'R':
            AIchallenge();
            break;
        default:
            cout << "Bad input.\n";
            break;
    }
    
    
    return 0;
}

void AIchallenge()
{
    bool recursiveGoFirst = true;
    
    int recursiveWins=0, iterativeWins=0, staleMates=0;
    
    while (true) {
        srand(unsigned(time(NULL)));
        bool gameInProgress = true;
        bool recursivesTurn = recursiveGoFirst;
        recursiveGoFirst = !recursiveGoFirst;
        connect4 board(6,7,' ',false);
        while (gameInProgress) {
            board.printBoard();
            cout << "Running score - Recursive " << recursiveWins
            << " : Iterative " << iterativeWins
            << " : Stalemates " << staleMates << endl;
            if (recursivesTurn) {
                cout << "Recursive's turn . . . \n";
                int status =
                board.insert(
                             board.hint('R','I', true) + 1,
                             'R');
                switch (status) {
                    case 3:
                        board.printBoard();
                        cout << "Recursive wins\n";
                        gameInProgress = false;
                        recursiveWins++;
                        break;
                    case 4:
                        board.printBoard();
                        cout << "Stalemate\n";
                        gameInProgress = false;
                        staleMates++;
                        break;
                }
            }
            else {
                cout << "Iterative's turn . . . \n";
                int status =
                board.insert(
                             board.hint('I','R', false) + 1,
                             'I');
                switch (status) {
                    case 3:
                        board.printBoard();
                        cout << "Iterative wins\n";
                        iterativeWins++;
                        gameInProgress = false;
                        break;
                    case 4:
                        board.printBoard();
                        cout << "Stalemate\n";
                        gameInProgress = false;
                        break;
                }
            }
            recursivesTurn = !recursivesTurn;
        } // end current game
    }
}
void think()
{
    connect4 temp;
    temp.think();
}

void pause()
{
    cout << "Hit return to continue";
    while (cin.get() != '\n') ;
}

void copyConstruct()
{
    while (cin.get() != '\n') ; 
    
    cout << "Here is copy constructor test.\n";
    cout << "Creating start board . . . ";
    connect4 start(6,7);
    
    cout << "Here is start board . . . \n";
    start.printBoard();
    cout << endl;
    
    pause();
    
    cout << "Inserting values into start . . . \n";
    
    for (int i = 1; i < 6; i++) {
        start.insert(i, 'X');
        start.insert(i+1, 'O');
        start.insert(i+1, 'X');
        start.insert(i, 'O');
    }
    
    cout << "Here is start board with inserted values . . . \n";
    start.printBoard();
    cout << endl;
    pause();
    
    cout << "Testing copy constructor . . .\n";
    connect4 target(start);
    cout << "Here is target board . . . \n";
    target.printBoard();
    cout << endl;
    pause();
}

