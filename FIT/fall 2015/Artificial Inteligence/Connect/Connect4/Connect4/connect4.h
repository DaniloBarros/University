// connect4.h

#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>
#include<stdlib.h>

class connect4 {
public:
    connect4(int rows = 8, int cols = 8, char empty = ' ',
             bool DEBUG_MODE =0);
    connect4(const connect4&);
    ~connect4();
    void printBoard();
    int insert (int whichC, char player);
    int hint (char player1, char opponent, bool useRecursion = false);
    int AI_turn(char AI, char opponent, int& C, bool useRecursion = false);
    void think();
    friend int maxMin(char, char,  connect4&);
    friend void maxMinRecursive(char, char, connect4&, int&, int, bool);
    friend int maxMinIterative(char, char, connect4&);
    void undo(int C) { quickRemove(C-1);}
    
private:
    char** board;
    int* colHeights;
    int maxRows;
    int maxCols;
    char empty;
    bool firstTurn;
    bool DEBUG_MODE;
    int doFirstTurn();
    bool checkWin(int R, int C, char player);
    bool checkFour(int, int, int, int, char);
    inline bool isFull();
    inline void quickerInsert(int, char);
    int randomlySelectFromHighestValues(int[], int);
    inline void quickRemove(int);
    int quickInsert(int, char);
    int myInsert(int, char);
    bool isWinImmediatelyPossible(char, int&);
    int howManyWinsPossible(char);
    inline void clearScreen();
    inline bool isColumnFull(int);
    void fillHintArray(char, char, int[], int&, connect4&);
    bool areMultiplesPossibleNextTurn(char, int&, int[], int);
    bool isPossibleToForceWin(char, char, int&, int[], int);
    bool sequenceLeadingToWin(char, char);
    bool canCreateMultiplePossiblesIn2(char, int&, int[], int);
    bool canCreateMultiplePossiblesIn3(char, int&, int[], int);
};

// CONSTRUCTOR
// dynamically creates an RxC char grid with defaults values supplied
// Note:  There is a private constructor which takes another connect4 object
// this is used by the AI to create temporary boards to evaluate possible
// moves


// DESTRUCTOR
// cleans up dynamic allocations

// PRINT_BOARD
// figure it out

// INSERT
// takes an int for which column and char for current player
// returns 0 if no error
// returns 1 if int passed is bad integer
// returns 2 if that column is full
// returns 3 if player has now won
// returns 4 if entire board is now full
// int insert (int whichC, char player);

// HINT
// returns the column number which AI thinks is best possible move

// AI_TURN
// uses hint and insert to simulate a computer opponent
// uses an int reference to return into which Col it played
// returns insert value (see above)
#endif