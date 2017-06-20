// driver.C for connect4

#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include "connect4.h"

using namespace std;


void play2player(connect4*);
void challengeAI(connect4*);
void getNames(char[], char[]);
void getName(char[]);
void showInstructions();
void introScreen();
bool playHumanNotComputer();
bool humanGoFirst(char[]);
bool doHumansTurn(connect4*, char[], int, stack<int>&);
bool doComputerTurn(connect4*, char[], int&, bool, stack<int>&);
void clearScreen() { for (int i = 0; i<40; i++) cout << endl;}
bool setDifficulty(char[]);
bool playAgain();

int main(int argc, char* argv[])
{
#define PLAYER1 'X'
#define PLAYER2 '0'
#define HUMAN 'X'
#define AI 'O'
    
    do {
        connect4* thisGame;
        
        if (argc != 3 && argc != 2) thisGame = new connect4;
        else (argc == 3) ?
            thisGame = new connect4(atoi(argv[1]), atoi(argv[2]) ) :
            thisGame = new connect4(10, 10, ' ', true);
        
        introScreen();
        
        
        if (playHumanNotComputer() ) play2player(thisGame);
        else challengeAI(thisGame);
        
        delete thisGame;
        
    } while (playAgain());
    
    return 0;
}

bool playAgain()
{
    cout << "\nPlay again? (y/n) ";
    char response;
    cin >> response;
    while (cin.get() != '\n') ;
    return (response == 'Y' || response == 'y');
}


void introScreen()
{
    clearScreen();
    cout << "#######################################################\n";
    cout << "Connect Four - It's more than a game.\n";
    cout << "#######################################################\n";
    cout << "\n\n\n";
}


bool playHumanNotComputer()
{
    char response[75];
    
    cout << "Welcome, brave soul.  Would you care to challenge my "
    << "massive computational \nabilities or are you merely playing "
    << "against another inferior human?\n";
    do {
        cout << " \t<C>omputer or <H>uman opponent: ";
        cin >> response;
    }
    while (response[0] != 'c' && response[0] != 'C' && response[0] != 'h'
           && response[0] != 'H');
    
    // clear buffer
    while (cin.get() != '\n' ) ;
    
    return (response[0] == 'h' || response[0] == 'H');
    
}

bool humanGoFirst(char human[])
{
    char goFirst[75];
    do {
        cout << human << ", would you like to go first? (y/n) ";
        cin >> goFirst;
    }
    while (goFirst[0] != 'y' && goFirst[0] != 'Y' && goFirst[0] != 'n'
           && goFirst[0] != 'N');
    while (cin.get() != '\n') ; // clear the '\n'
    
    return (goFirst[0] == 'Y' || goFirst[0] == 'y');
    
}


void challengeAI(connect4* thisGame)
{
    cout << "\n\nIntrepid Human!!  "
    << "How dare you challenge my undeveloped AI??\n";
    char human[75];
    getName(human);
    bool useRecursion = setDifficulty(human);
    bool humansTurn = humanGoFirst(human);
    bool gameInProgress = true;
    int AIsLastTurn = -1;
    
    // instantiate a stack to contain moves, allows undoing previous
    stack<int> moves;
    
    while (gameInProgress) {
        if (humansTurn) {
            gameInProgress =
            doHumansTurn(thisGame, human, AIsLastTurn,
                         moves);
        }
        else {
            gameInProgress =
            doComputerTurn(thisGame, human, AIsLastTurn,
                           useRecursion, moves);
        }
        humansTurn = !humansTurn;
    }
}

bool doHumansTurn(connect4* thisGame, char human[], int C, stack<int>& moves)
{
    // define some string constants
    char response[75];
    char errorMsg[75] = "\0";
    char fullCol[] = "\t\aThat column is already full.  Try again.\n\0";
    char badCol[] = "\t\aThat is not a valid input.  Try again.\n\0";
    char moralVictory[] =
    "\tI consider this a moral victory.  Try again.\n\0";
    
    
    thisGame->printBoard();
    while (true) {
        cout << human << ", it's your turn."
        << "  You are " << HUMAN << ".\n";
        cout << errorMsg;
        if (!moves.empty()) cout << "My last turn was in column "
            << moves.top() << endl;
        cout << "Enter column # or <C>oncede or <H>int "
        << "or <I>nstructions or <U>ndo your previous turn: ";
        // repeat if user just hits return or enters too long string
        if ('\n' == cin.peek()) {
            cin.get();
            errorMsg[0] = '\0';
            continue;
        }
        // get a real answer
        cin >> response;
        while (cin.get() != '\n'); // get the \n
        // request for hint?
        if ('h' == response[0] || 'H' == response[0]) {
            cout << "Were I you, I might consider column "
            << thisGame->hint(HUMAN, AI) << endl;
            errorMsg[0] = '\0';
            continue;
        }
        else
            // request for instructions?
            if ('i' == response[0] || 'I' == response[0]) {
                showInstructions();
                errorMsg[0] = '\0';
                thisGame->printBoard();
                continue;
            }
            else
                // undo previous move?
                if ('u' == response[0] || 'U' == response[0]) {
                    if (!moves.empty()) {
                        int top = moves.top();
                        thisGame->undo(top);
                        moves.pop();
                        if (!moves.empty()) {
                            top = moves.top();
                            thisGame->undo(top);
                            moves.pop();
                        }
                    }
                    strcpy(errorMsg, moralVictory);
                    thisGame->printBoard();
                    continue;
                }
                else
                    // are they conceding?
                    if ('c' == response[0] || 'C' == response[0]) {
                        cout << "Thanks for not delaying "
                        << "the inevitable.\n";
                        return false; // game over
                    }
        // ok, turn it into a number and insert it
        int C = atoi(response);
        int insertStatus = thisGame->insert(C, HUMAN);
        if (!insertStatus) { // ok insert, no win, no stalemate
            errorMsg[0] = '\0';
            moves.push(C);
            return true; // valid move, not game-ending, AI turn
        }
        else { // game ending move or invalid entry
            switch(insertStatus) {
                case 1 :
                    strcpy(errorMsg, badCol);
                    break;
                case 2 :
                    strcpy(errorMsg, fullCol);
                    break;
                case 3 :
                    thisGame->printBoard();
                    cout << "Congratulations, "
                    << human
                    << ", you win!!\n";
                    return false;
                    break;
                case 4 :
                    thisGame->printBoard();
                    cout << "Nobody is a loser "
                    << "today. :)"
                    << "\nYou managed to play "
                    << "to a stalemate.\n";
                    return false;
                    break;
                default :
                    cout << "Major error "
                    << "I have no idea what is "
                    << "going on . . . \n"
                    << "Tell John Bent - error 23"
                    << endl;
                    return false;
                    break;
            }
        }
    }
}

bool doComputerTurn(connect4* thisGame, char human[], int& C, bool useRecursion,
                    stack<int>& moves)
{
    C = -1; // col into which AI inserts its token
    
    thisGame->printBoard();
    cout << "Very interesting.  Now it's my turn. ";
    
    //if (!useRecursion) thisGame->think();
    //else
    cout << "\nThinking . . . please wait.\n";
    
    int computerMove = thisGame->AI_turn(AI, HUMAN, C, useRecursion);
    moves.push(C);
    
    switch(computerMove) {
        case 0 :
            break;
        case 1 :
            cout << "What kind of AI are you? "
            << "You just returned an invalid "
            << "column.  Screw you.\n";
            return false; // end the game
            break;
        case 3 :
            thisGame->printBoard();
            cout << "Sorry, " << human << " but I "
            << "seem to have defeated you by playing into "
            << "column " << C << ".\n";
            char response [75];
            do {
                cout << "<U>ndo your previous move or <C>oncede? ";
                cin >> response;
            }
            while (response[0] != 'u' && response[0] != 'U'
                   && response[0] != 'C' && response[0] != 'c');
            while (cin.get() != '\n') ;
            if (response[0] == 'u' || response[0] == 'U') {
                int top = moves.top();
                moves.pop();
                thisGame->undo(top);
                top = moves.top();
                moves.pop();
                thisGame->undo(top);
                return true;
            }
            return false;
            break;
        case 4 :
            cout << "Wow, " << human << "you seem "
            << "to have played me to a stalemate.";
            return false; // game over - stalemate
            break;
        default :
            cout << "Major error "
            << "I have no idea what is "
            << "going on . . . \n"
            << "Tell John Bent 'error 25'"
            << endl;
            return false;
            break;
    }
    
    return true; // if we make it here, AI has made a non-game ending move
}

void play2player(connect4* thisGame)
{
    const int nameLength = 75;
    char player = PLAYER1;
    char player1[nameLength], player2[nameLength];
    char response[nameLength];
    char errorMsg[nameLength];
    char empty[] = "\0";
    char fullCol[] = "\t\aThat column is already full.  Try again.\n\0";
    char badCol[] = "\t\aThat is not a valid input.  Try again.\n\0";
    getNames(player1, player2);
    bool keepGoing = true;
    strcpy (errorMsg, empty);
    
    
    while (keepGoing) {
        thisGame->printBoard();
        (PLAYER1 == player) ?
        cout << player1 << " (" << PLAYER1 << ")" :
        cout << player2 << " (" << PLAYER2 << ")";
        cout << ":\n";
        cout << errorMsg;
        cout << "\tChoose a column or <h>elp or <c>oncede. ";
        // repeat if user just hits return
        if ('\n' == cin.peek()) {
            cin.get();
            strcpy(errorMsg, empty);
            continue;
        }
        // get a real answer
        cin >> response;
        while (cin.get() != '\n'); // get the \n
        // request for help?
        if ('h' == response[0] || 'H' == response[0]) {
            showInstructions();
            strcpy(errorMsg, empty);
            continue;
        }
        // are they conceding?
        if ('c' == response[0] || 'C' == response[0]) {
            cout << "Congratulations, ";
            (PLAYER1 == player) ?   cout << player2 :
            cout << player1 ;
            cout << ", you win!!\n";
            break;
        }
        // ok, turn it into a number and insert it
        int C = atoi(response);
        int insertStatus = thisGame->insert(C, player);
        if (!insertStatus) { // ok insert, no win, no stalemate
            (PLAYER1 == player) ?   player = PLAYER2 :
            player = PLAYER1;
            strcpy(errorMsg, empty);
            continue;
        }
        else {
            switch(insertStatus) {
                case 1 :
                    strcpy(errorMsg, badCol);
                    break;
                case 2 :
                    strcpy(errorMsg, fullCol);
                    break;
                case 3 :
                    thisGame->printBoard();
                    cout << "Congratulations, ";
                    (PLAYER1 == player) ?
                    cout << player1 :
                    cout << player2;
                    cout << ", you win!!\n";
                    keepGoing = false;
                    break;
                case 4 :
                    thisGame->printBoard();
                    cout << "Nobody is a loser today. :)"
                    << "\nYou managed to play to a "
                    << "stalemate.\n";
                    keepGoing = false;
                    break;
            }
        }
    }
}

// reads players names into strings passed from play2player
// won't return until non-zero length different names are entered
void getNames(char player1[], char player2[])
{
    while (true)  {
        cout << "Player One - Please enter your name: ";
        if ('\n' == cin.peek()) { // too short
            cin.get();
            continue;
        }
        cin >> player1; while (cin.get() != '\n'); // get the '\n'
        break;
    }
    
    while (true) {
        cout << "Player Two - Please enter your name: ";
        if ('\n' == cin.peek()) { // too short
            cin.get();
            continue;
        }
        cin >> player2; while (cin.get() != '\n');
        if (!strcmp(player1, player2)) {
            cout << "Player Two - You cannot have same"
            << " name as Player One.\n";
            continue;
        }
        break;
    }
    
    
}

// gets human's name in AI challenge, won't return until non-null string is
// entered
void getName(char player1[])
{
    while (true) {
        cout << "\tPlease enter your name: ";
        if ('\n' == cin.peek() ) { // too short
            cin.get();
            continue;
        }
        cin >> player1; while (cin.get() != '\n'); // get the '\n'
        break;
    }
}

bool setDifficulty(char player1[])
{
    cout << player1 << ", do you want me to play <E>asy or <H>ard? ";
    char answer[75];
    cin >> answer;
    while (cin.get() != '\n') ;
    return !(answer[0] == 'h' || answer[0] == 'H');
}


void showInstructions()
{
    for (int i = 0; i < 30; i++) cout << endl;
    cout << "Do you really need instructions on how to play "
    << "connect4?  Hit <ENTER> after you have finished reading these "
    << "instructions. ";
    while (cin.get() != '\n');
}