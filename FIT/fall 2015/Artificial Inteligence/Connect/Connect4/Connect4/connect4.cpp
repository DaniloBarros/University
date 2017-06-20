// connect4.C

#include"connect4.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

connect4::connect4(int rows, int cols, char Empty, bool debug)
{
    // constrain rows and cols to be decent values
    if (rows < 5) rows = 5; if (rows > 15) rows = 15;
    if (cols < 5) cols = 5; if (cols > 19) cols = 19;
    
    maxRows = rows;
    maxCols = cols;
    empty = Empty;
    firstTurn = true;
    DEBUG_MODE = debug;
    
    // make 2 dimensional dynamic array - thanks tutsch
    // create ptrs to rows
    board = new char* [maxRows];
    // create each row and initialize each value
    for (int i = 0; i < maxRows; i++) {
        board[i] = new char[maxCols];
        for (int j = 0; j < maxCols; j++)
            board[i][j] = empty;
    }
    
    colHeights = new int[maxCols];
    for (int k = 0; k < maxCols; k++)
        colHeights[k] = 0;
    
    srand(unsigned(time(NULL)));
    
}

connect4::connect4(const connect4& rhs)
{
    maxRows = rhs.maxRows;
    maxCols = rhs.maxCols;
    empty = rhs.empty;
    firstTurn = rhs.firstTurn;
    DEBUG_MODE = rhs.DEBUG_MODE;
    
    board = new char* [this->maxRows];
    for (int i = 0; i < maxRows; i++) {
        board[i] = new char[maxCols];
        for (int j = 0; j < maxCols; j++)
            board[i][j] = rhs.board[i][j];
    }
    
    colHeights = new int[maxCols];
    for (int k = 0; k < maxCols; k++)
        colHeights[k] = rhs.colHeights[k];
    
    srand(unsigned(time(NULL)));
}

connect4::~connect4()
{
    for (int i = 0; i < maxRows; i++)
        delete [] board[i];
    delete [] board;
    
    delete [] colHeights;
}

void connect4::printBoard()
{
    clearScreen();
    
    char vert_line = '|';
    char horz_line_segment[] = "---+";
    char horz_line_segment_prefix = '+';
    
    cout << endl;
    for (int i = 0; i < maxRows; i++) {
        cout << vert_line;
        for (int j = 0; j < maxCols; j++) {
            
            cout << " " << board[i][j] << " " << vert_line;
        }
        cout << endl;
        cout << horz_line_segment_prefix;
        for (int k = 0; k < maxCols; k++) cout << horz_line_segment;
        cout << endl;
    }
    for (int m = 1; m <= maxCols; m++) {
        (m > 9) ? cout << " " : cout << "  ";
        cout << m << " ";
    }
    cout << endl;
}


// ***following are the INSERTS ****
int connect4::insert(int whichC, char player)
{
    // this is user level insert
    
    // check whether valid range
    if (whichC < 1 || whichC > maxCols) return 1;
    
    // subtract one and use real insert
    return myInsert(whichC - 1, player);
}


int connect4::myInsert(int whichC, char player)
{
    // check whether that column is already full
    if (isColumnFull(whichC)) return 2;
    
    // otherwise update board and colHeights
    int R = maxRows - colHeights[whichC] - 1;
    board [R][whichC] = player;
    colHeights[whichC]++;
    
    // check for win
    if ( checkWin (R, whichC, player) )
        return 3;
    
    // otherwise check if board is full
    if (isFull()) return 4;
    
    return 0;
    
}

void connect4::quickerInsert(int C, char player)
{
    if (isColumnFull(C)) return;
    
    board[maxRows - colHeights[C] - 1][C] = player;
    colHeights[C]++;
}

int connect4::quickInsert(int C, char player)
{
    // don't need to check whether column full, caller does that
    
    int R = maxRows - colHeights[C] - 1;
    board[R][C] = player;
    colHeights[C]++;
    
    // when called by hint, doesn't need to check for win
    // check for win
    if (checkWin (R,C,player) ) return 3;
    
    // need to check whether board is full?
    
    return 0;
}

void connect4::quickRemove(int C)
{
    colHeights[C]--;
    board[maxRows - colHeights[C] - 1][C] = empty;
}


bool connect4::isFull()
{
    for (int i = 0; i < maxCols; i++)
        if (colHeights[i] < maxRows) return false;
    return true;
}

bool connect4::isColumnFull(int C)
{
    return (colHeights[C] >= maxRows);
}

bool connect4::checkWin (int R, int C, char player)
{
    // diagonal (NW --> SE)
    if (checkFour(R - 3, R + 4, C - 3, C + 4, player))
        return true;
    else
        // diagonal (SW --> NE)
        if (checkFour(R + 3, R - 4, C - 3, C + 4, player))
            return true;
        else
            // straight across (W --> E)
            if (checkFour(R, R, C - 3, C + 4, player))
                return true;
            else
                // straight down (N --> S)
                if (checkFour(R - 3, R + 4, C, C, player))
                    return true;
    
    return false;
}

bool connect4::checkFour (int startRow, int endRow, int startCol, int endCol,
                          char player)
{
    int rowStep = (startRow > endRow ? -1 : (startRow < endRow ? 1 : 0));
    int colStep = (startCol > endCol ? -1 : (startCol < endCol ? 1 : 0));
    int count = 0;
    int row = startRow;
    int col = startCol;
    
    for (; row != endRow || col != endCol; row += rowStep, col += colStep) {
        // check bounds
        if (row < 0 || col < 0 || row >= maxRows || col >= maxCols)
            continue;
        if (board[row][col] == player)
            count ++;       // tally continuous player pieces
        else
            count = 0; // discontinuous sequence -- must reset count
        
        if (count == 4) break;  // four-in-a-row found
    }
    
    return (count == 4);
}

void connect4::clearScreen()
{
    for (int i = 0; i < 30; i++) cout << endl;
}

bool connect4::isWinImmediatelyPossible(char player, int& C)
{
    const int win = 3; // value returned by insert for winning move
    
    for (int i = 0; i < maxCols; i++) {
        if (isColumnFull(i)) continue; // don't check full col
        if (win == quickInsert(i, player) ) {
            C = i;
            quickRemove(i);
            return true;
        }
        quickRemove(i);
    }
    return false; // win not immediately possible
}

int connect4::howManyWinsPossible(char player)
{
    const int win = 3; // value returned by insert for winning move
    
    int possible = 0;
    
    for (int i = 0; i < maxCols; i++) {
        if (isColumnFull(i)) continue; // don't check full col
        if (win == quickInsert(i, player)) possible++;
        quickRemove(i);
    }
    
    return possible;
}

int maxMinIterative(char pl, char op, connect4& start)
{
    int newValue = 0;
    
    // for fun, lets try something different
    for (int w = 0; w < start.maxCols; w++) {
        if (start.isColumnFull(w)) continue;
        start.quickerInsert(w, op);
        for (int q = 0; q < start.maxCols; q++) {
            if (start.isColumnFull(q)) continue;
            start.quickerInsert(q, pl);
            if (start.sequenceLeadingToWin(pl, op))
                newValue++;
            if (start.sequenceLeadingToWin(op, pl))
                newValue--;
            start.quickRemove(q);
        }
        start.quickRemove(w);
    }
    
    return newValue;
    
    int value = 0;
    int junk = 0;
    
    // don't force opponent to block win and close off future opportunity
    if (start.isWinImmediatelyPossible(pl, junk)) value -= 3000;
    
    for (int i = 0; i < start.maxCols; i++) {
        if (start.isColumnFull(i)) continue;
        // every possible insert for opponent
        start.quickerInsert(i, op);
        // REMOVE? value -= start.howManyWinsPossible(op);
        for (int j = 0; j < start.maxCols; j++) {
            if (start.isColumnFull(j)) continue;
            // every possible insert for player
            start.quickerInsert(j, pl);
            // REMOVE? value += start.howManyWinsPossible(pl);
            for (int k = 0; k < start.maxCols; k++) {
                if (start.isColumnFull(k)) continue;
                // every possible insert for opponent
                start.quickerInsert(k, op);
                // REMOVE? value-=start.howManyWinsPossible(op);
                for (int m = 0; m < start.maxCols; m++) {
                    if (start.isColumnFull(m)) continue;
                    // every possible insert for player
                    start.quickerInsert(m, pl);
                    // REMOVE?
                    value+=start.howManyWinsPossible(pl);
                    value-=start.howManyWinsPossible(op);
                    /* DON'T GO TOO DEEP
                     for (int n = 0; n < start.maxCols; n++){
                     if (start.isColumnFull(n))
                     continue;
                     // every possible oppon insert
                     start.quickerInsert(n,op);
                     value -=
                     start.howManyWinsPossible (op);
                     value +=
                     start.howManyWinsPossible(pl);
                     start.quickRemove(n);
                     }
                     DON'T GO TOO DEEP*/
                    start.quickRemove(m);
                }
                start.quickRemove(k);
            }
            start.quickRemove(j);
        }
        start.quickRemove(i);
    }
    
    return value;
}


int maxMin(char player, char opponent, connect4& start, bool useRecursion)
{
    // NOTE:  start is a board in which the player has
    // already inserted a hypothetical play
    
    int depth = 4;
    int value = 0;
    
    bool alwaysUseRecursive = false;
    
    if (!useRecursion || alwaysUseRecursive) {
        value = maxMinIterative(player, opponent, start);
    }
    else {
        maxMinRecursive(player, opponent, start, value, depth, false);
    }
    
    return value;
    
    
}



void maxMinRecursive(char player, char opponent, connect4& start,
                     int& count, int depth, bool playersTurn )
{
    count += depth * start.howManyWinsPossible(player);
    count -= depth * start.howManyWinsPossible(opponent);
    if (depth > 1) {
        for (int i = 0; i < start.maxCols; i++) {
            if (start.isColumnFull(i)) continue;
            // don't bother for full col
            (playersTurn) ? start.quickerInsert(i, player)
            : start.quickerInsert(i, opponent);
            // make recursive call, note depth diminishes and playerTurn
            // flip-flops
            maxMinRecursive(player, opponent, start, count, depth - 1,
                            !playersTurn);
            // when return from recursion, remove the insert
            start.quickRemove(i);
        }
    }
}

int connect4::doFirstTurn()
{
    think();
    firstTurn = false;
    for (int i = 0; i < maxCols; i++)
        if (board[maxRows-1][i] != empty) // opponent has played already
            return (i >= maxCols/2) ? i - 1 : i + 1;
    return (4 + rand() % (maxCols/3));
}

bool connect4::areMultiplesPossibleNextTurn
(char player, int& C, int colsToCheck[], int howMany)
{
    for (int i = 0; i < howMany; i++) {
        quickerInsert(colsToCheck[i], player);
        if (howManyWinsPossible(player) > 1) {
            C = colsToCheck[i];
            quickRemove(colsToCheck[i]);
            return true;
        }
        quickRemove(colsToCheck[i]);
    }
    return false;
}

bool connect4::canCreateMultiplePossiblesIn3(char player,
                                             int &C, int colsToCheck[], int howMany)
{
    int junk;
    int howManyPossible = 1;
    int possibleThisCol = -1;
    bool foundMultiples = false;
    
    bool trace = DEBUG_MODE;
    
    for (int i = 0; i < howMany; i++) {
        quickerInsert(colsToCheck[i], player);
        if (isWinImmediatelyPossible(player, junk)) {
            quickRemove(colsToCheck[i]);
            continue;
        }
        for (int j = 0; j < maxCols; j++) {
            if (isColumnFull(j) || j == colsToCheck[i]) continue;
            quickerInsert(j, player);
            if (isWinImmediatelyPossible(player, junk)) {
                quickRemove(j);
                continue;
            }
            for (int k = 0; k < maxCols; k++) {
                if (isColumnFull(k)
                    || k == j || k == colsToCheck[i])
                    continue; // don't create towers
                quickerInsert(k, player);
                possibleThisCol = howManyWinsPossible(player);
                if (possibleThisCol > howManyPossible) {
                    howManyPossible = possibleThisCol;
                    if (trace)
                        cout << "Can create "
                        << howManyPossible
                        << " future mults by "
                        << "playing in " << colsToCheck[i]+1
                        << " then in " << j+1 << " then in "
                        << k+1 << endl;
                    C = colsToCheck[i];
                    foundMultiples = true;
                }
                quickRemove(k);
            }
            quickRemove(j);
        }
        quickRemove(colsToCheck[i]);
    }
    return foundMultiples;
}

bool connect4::canCreateMultiplePossiblesIn2(char player,
                                             int &C, int colsToCheck[], int howMany)
{
    int junk;
    int howManyPossible = 1;
    int possibleThisCol = -1;
    bool foundMultiples = false;
    
    bool trace = DEBUG_MODE;
    
    for (int i = 0; i < howMany; i++) {
        quickerInsert(colsToCheck[i], player);
        if (isWinImmediatelyPossible(player, junk)) {
            quickRemove(colsToCheck[i]);
            continue;
        }
        for (int j = 0; j < maxCols; j++) {
            if (isColumnFull(j) || j == colsToCheck[i]) continue;
            quickerInsert(j, player);
            possibleThisCol = howManyWinsPossible(player);
            if (possibleThisCol > howManyPossible) {
                howManyPossible = possibleThisCol;
                C = colsToCheck[i];
                if (trace) cout << "Can create "
                    << howManyPossible
                    << " future mults by "
                    << "playing in " << colsToCheck[i]+1
                    << " then in " << j+1 << endl;
                foundMultiples = true;
            }
            quickRemove(j);
        }
        quickRemove(colsToCheck[i]);
    }
    return foundMultiples;
}

bool connect4::isPossibleToForceWin(char player, char opponent, int& C,
                                    int colsToCheck[], int howMany)
{
    int bestMove, junk;
    
    for (int y = 0; y < howMany; y++) {
        quickerInsert(colsToCheck[y], player);
        if (isWinImmediatelyPossible(player, bestMove) ) {
            // assume opponent blocks it
            quickerInsert(bestMove, opponent);
            // does it give an immediate win?
            if (isWinImmediatelyPossible(player, junk) ) {
                // this is desirable, return loop counter
                C = colsToCheck[y];
                quickRemove(bestMove);
                quickRemove(colsToCheck[y]);
                return true;
            }
            else // does it create a forced sequence to win?
                connect4 temp(*this);
            if (sequenceLeadingToWin(player,opponent)) {
                C = colsToCheck[y];
                quickRemove(bestMove);
                quickRemove(colsToCheck[y]);
                return true;
            }
            quickRemove(bestMove);
        }
        quickRemove(colsToCheck[y]);
    }
    return false;
}


// RECURSIVE
bool connect4::sequenceLeadingToWin(char player, char opponent)
{
    // can player win immediately? return true
    // else try inserts and see if they make multiple possibles
    // if they do return true, if instead they create another
    // immediate win, assume opponent blocks, recurse
    
    int temp;
    
    if (isWinImmediatelyPossible(player, temp)) return true;
    else
        for (int i = 0; i < maxCols; i++) {
            if (isColumnFull(i)) continue; // ignore full column
            quickerInsert(i, player);
            // make sure opponent can't win immediately
            if (isWinImmediatelyPossible(opponent, temp)) {
                quickRemove(i);
                continue;
            }
            else
                // are there multiple wins here?
                if (howManyWinsPossible(player) > 1) {
                    quickRemove(i);
                    return true;
                }
                else
                    // can player immediately win?
                    if (isWinImmediatelyPossible(player, temp)) {
                        // assume opponent blocks
                        quickerInsert(temp, opponent);
                        // and RECURSE
                        if (sequenceLeadingToWin(player, opponent)) {
                            quickRemove(temp);
                            quickRemove(i);
                            return true;
                        }
                        quickRemove(temp);
                    }
            quickRemove(i);
        }
    return false;
}

void connect4::fillHintArray(char player, char opponent, int colsToCheck[],
                             int& howManyColsToCheck, connect4& temp)
{
    int junk;
    howManyColsToCheck = 0;
    for (int v = 0; v < maxCols; v++) {
        if (isColumnFull(v)) continue; // no good
        // do inserts and see if give immediate win
        temp.quickerInsert(v, player);
        if (!temp.isWinImmediatelyPossible(opponent, junk)) {
            // also make sure that opponent can't play on top
            // of it and create multiples
            if (temp.isColumnFull(v)) {
                colsToCheck[howManyColsToCheck++] = v;
                continue;
            }
            temp.quickerInsert(v, opponent);
            if (temp.howManyWinsPossible(opponent) < 2)
                colsToCheck[howManyColsToCheck++] = v;
            temp.quickRemove(v);
        }
        temp.quickRemove(v);
    }
}

void showColsChecked(int columns[], int i)
{
    cout << "I checked the following columns: ";
    for (int j = 0; j < i; j++)
        cout << columns[j] + 1 << " ";
    cout << endl;
}

int connect4::hint (char player, char opponent, bool useRecursion)
{
    int trace = DEBUG_MODE;
    int bestMove = -1;
    int pretendThink = 0;
    
    // can player win immediately?
    if (isWinImmediatelyPossible(player, bestMove) ) {
        if (pretendThink) think();
        if (trace) cout << "I can win immediately.\n";
        return bestMove;
    }
    
    // can opponent win on next turn?
    if (isWinImmediatelyPossible(opponent, bestMove) ){
        if (pretendThink) think();
        if (trace) cout << "Opponent can win immediately.\n";
        return bestMove;
    }
    
    // otherwise, it gets more complicated - create a temporary board
    // to insert hypothetical plays
    connect4 temp(*this);
    
    // create a partially filled array containing those columns
    // which are worth evaluating (exclude full and those which
    // give immediate possible win)
    int *colsToCheck = new int[maxCols];
    int howManyColsToCheck = 0;
    fillHintArray(player, opponent, colsToCheck, howManyColsToCheck, temp);
    
    // then pass board and array to various functions
    
    // can player play anywhere and make multiple possible wins?
    // if so, return that column if it doesn't give immediate win
    if (temp.areMultiplesPossibleNextTurn(player, bestMove, colsToCheck,
                                          howManyColsToCheck)) {
        if (pretendThink) think();
        if (trace) cout << "I can make multiple possible wins.\n";
        if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
        delete [] colsToCheck;
        return bestMove;
    }
    
    // can player create an immediate win whose block enables immediate W?
    // or a sequence leading to inevitable victory?
    // if so, return that C if it doesn't give immediate win
    if (temp.isPossibleToForceWin(player, opponent, bestMove, colsToCheck,
                                  howManyColsToCheck)) {
        if (pretendThink) think();
        if (trace) cout << "I can create sequence leading to win.\n";
        if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
        delete [] colsToCheck;
        return bestMove;
    }
    
    
    // can opponent play anywhere and make multiple possible wins?
    // if so, return that column if it doesn't give immediate win
    if (temp.areMultiplesPossibleNextTurn(opponent, bestMove, colsToCheck,
                                          howManyColsToCheck)) {
        if (pretendThink) think();
        if (trace) cout <<"Opponent can make multiple possible wins.\n";
        if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
        delete [] colsToCheck;
        return bestMove;
    }
    
    
    // can opponent create an immediate win whose block enables immediate W?
    // or a sequence leading to inevitable victory?
    // if so, return tha column if it doesn't give immediate win
    if (temp.isPossibleToForceWin(opponent, player, bestMove, colsToCheck,
                                  howManyColsToCheck)) {
        if (pretendThink) think();
        if (trace) cout << "Opponent can create seq -> win.\n";
        if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
        delete [] colsToCheck;
        return bestMove;
    }
    
    if (false) { // these tests seem to make the AI dumber
        // can player create multiple possibles in two turns?
        // is so, return that column if it doesn't give immediate win
        if (temp.canCreateMultiplePossiblesIn2(player, bestMove,
                                               colsToCheck, howManyColsToCheck)) {
            if (pretendThink) think();
            if (trace) cout << "I can create multiple possibles in 2.\n";
            if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
            delete [] colsToCheck;
            return bestMove;
        }
        
        /* I don't like this test
         // can opponent create multiple possibles in two turns?
         // is so, return that column if it doesn't give immediate win
         if (temp.canCreateMultiplePossiblesIn2(opponent, bestMove,
         colsToCheck, howManyColsToCheck)) {
         if (pretendThink) think();
         if (trace)
         cout << "Oppon can create multiple possibles in 2.\n";
         if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
         delete [] colsToCheck;
         return bestMove;
         }*/
        
        // can player create multiple possibles in three turns?
        // is so, return that column if it doesn't give immediate win
        if (temp.canCreateMultiplePossiblesIn3(player, bestMove,
                                               colsToCheck, howManyColsToCheck)) {
            if (pretendThink) think();
            if (trace) cout << "I can create multiple possibles in 3.\n";
            if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
            delete [] colsToCheck;
            return bestMove;
        }
        
        /* I don't think I like this test
         // can opponent create multiple possibles in three turns?
         // is so, return that column if it doesn't give immediate win
         if (temp.canCreateMultiplePossiblesIn3(opponent, bestMove,
         colsToCheck, howManyColsToCheck)) {
         if (pretendThink) think();
         if (trace)
         cout << "Oppon can create multiple possibles in 3.\n";
         if (trace) showColsChecked(colsToCheck, howManyColsToCheck);
         delete [] colsToCheck;
         return bestMove;
         }*/
    } // end if !useRecursion
    
    // no immediate tests were obvious so
    // check whether they are any possible columns
    if (howManyColsToCheck == 0) {
        delete [] colsToCheck;
        if (pretendThink) think();
        if (trace) cout << "I'm going to lose.\n";
        for (int i = 0; i < maxCols; i++)
            if (!isColumnFull(i)) return i;
        if (trace) cout << "Game is about to crash.\n" << endl;
        if (trace) cout.flush();
        return -1; 
    }
    else if (howManyColsToCheck == 1) {
        if (pretendThink) think();
        if (trace) cout << "I seem to be constrained into playing in "
            << "column " << colsToCheck[0] + 1;
        bestMove = colsToCheck[0];
        delete [] colsToCheck;
        return bestMove;
    }
    
    // remove any columns which create immediate player win and force
    // opponent to block because these opportunities are better left
    // unforced until they can be inserted into a sequence -> win
    // place these in a new array noForceCols
    int* noForceCols = new int[howManyColsToCheck];
    int howManyNoForce = 0;
    for (int y = 0; y < howManyColsToCheck; y++) {
        temp.quickerInsert(colsToCheck[y], player);
        if (!temp.isWinImmediatelyPossible(player, bestMove)) 
            noForceCols[howManyNoForce++] = colsToCheck[y];
        temp.quickRemove(colsToCheck[y]);
    } 
    
    // if noForceCols[] is not empty, randomly choose from its contents
    // 4/5 of time, other 1/5 choose from colsToCheck[]
    // else evaluate and return best column in colsToCheck[]
    int* whichOne, howMany;
    if (howManyNoForce && rand()%5) {
        whichOne = noForceCols;
        howMany  = howManyNoForce;
        if (trace) cout << "\nSelecting from no force cols only:";
    }
    else {
        whichOne = colsToCheck;
        howMany  = howManyColsToCheck;
        if (trace) cout << "\nSelecting from force and no-force cols:";
    }
    
    // send each possible column to maxMin to evaluate
    // create an array to hold these values
    int* colEvals = new int[howMany];
    if (!trace) cout << "\nEvaluating column         ";
    for (int j = 0; j < howMany; j++) {
        temp.quickerInsert(whichOne[j], player);
        if (trace) cout << colEvals[0] << " . . . ";
        colEvals[j] = maxMin(player, opponent, temp, useRecursion);
        if (trace) cout << "\nColumn " << whichOne[j] + 1
            << " evaluated with a value of "
            << colEvals[j]; 
        else {
            cout << "\b\b\b\b\b\b\b\b"; // delete elipse
            if (j != 0 && whichOne[j-1] > 9) cout << "\b";
            // delete second digit if any
            cout << whichOne[j] + 1 << " . . . "; cout.flush();
        }	
        temp.quickRemove(whichOne[j]);
    }
    
    bestMove = whichOne[randomlySelectFromHighestValues(colEvals, howMany)];
    delete [] colsToCheck;
    delete [] noForceCols;
    return bestMove; 
}

int connect4::randomlySelectFromHighestValues(int Cols[], int howMany)
{
    // find best maxMin evaluated value in array of cols
    
    // create an array to hold all moves with same evaluations to choose
    // one randomly - don't need to then initialize all values at -1
    int* possibleMoves = new int[maxCols];
    int bestMaxMinSoFar = Cols[0];
    int howManyPossibleMoves = 1;
    possibleMoves[0] = 0;
    
    for (int ii = 1; ii < howMany; ii++) {
        if (Cols[ii] > bestMaxMinSoFar) {
            possibleMoves[0] = ii;
            howManyPossibleMoves = 1;
            bestMaxMinSoFar = Cols[ii];
        }
        else if (Cols[ii] == bestMaxMinSoFar) {
            possibleMoves[howManyPossibleMoves] = ii;
            howManyPossibleMoves++;
        }
    }
    
    // now we have a partially filled array with each column that 
    // received the highest evaluation - let's randomly choose the
    // best one
    return possibleMoves[rand()%howManyPossibleMoves];	
    
}

int connect4::AI_turn(char AI, char opponent, int& C, bool useRecursion)
{
    // add one to account for difference, C is reported back to human
    (firstTurn) ?   C = doFirstTurn() + 1 : 
    C = hint (AI, opponent, useRecursion) + 1;
    
    return myInsert ( C - 1, AI);
}

void connect4::think()
{
    const long LARGE_NUM = 9999999;
    
    cout << " \nEvaluating column 1 . . . ";
    cout.flush();
    
    for (int j = 1; j < maxCols; j++) {
        for (long i = 0; i < LARGE_NUM; i++) ; // waste time loop
        (j > 9) ? cout << "\b\b" : cout << "\b"; // erase previous #
        cout << "\b\b\b\b\b\b\b"; // erase previous elipse
        cout << j+1 << " . . . "; 
        cout.flush();
    }
}